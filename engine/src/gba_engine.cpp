//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/allocator.h>

std::unique_ptr<SoundControl> GBAEngine::activeChannelA;
std::unique_ptr<SoundControl> GBAEngine::activeChannelB;

void GBAEngine::vsync() {
    while (REG_VCOUNT >= 160);
    while (REG_VCOUNT < 160);
}

void GBAEngine::onVBlank() {
    // WARNING this is a very dangerous piece of code.
    // GBA IRQs seem eager to crash or eat up CPU. Get in, disable stuff, work, enable, get out!
    stopOnVBlank();

    unsigned short tempInterruptState = REG_IF;

    if((REG_IF & INTERRUPT_VBLANK) == INTERRUPT_VBLANK) {
        if(GBAEngine::activeChannelA) {
            if(GBAEngine::activeChannelA->done()) {
                GBAEngine::activeChannelA->reset();
            } else {
                GBAEngine::activeChannelA->step();
            }
        }
        if(GBAEngine::activeChannelB) {
            if(GBAEngine::activeChannelB->done()) {
                GBAEngine::activeChannelB->disable();
                GBAEngine::activeChannelB = nullptr;    // never delete, let unique_ptr do that, known to flip here
            } else {
                GBAEngine::activeChannelB->step();
            }
        }
    }

    REG_IF = tempInterruptState;
    startOnVBlank();
}

u16 GBAEngine::readKeys() {
    return ~REG_KEYS & KEY_ANY;
}

void GBAEngine::dequeueAllSounds() {
    stopOnVBlank();
    vsync();

    if(GBAEngine::activeChannelA) {
        GBAEngine::activeChannelA->disable();
    } if(GBAEngine::activeChannelB) {
        GBAEngine::activeChannelB->disable();
    }
}

void GBAEngine::enqueueSound(const s8 *data, int totalSamples, int sampleRate, SoundChannel channel) {
    SoundControl* control;

    if(channel == ChannelA) {                       // repeating bg music can be restarted
        GBAEngine::activeChannelA = SoundControl::channelAControl();
        control = GBAEngine::activeChannelA.get();
    } else {                                        // sound still playing, don't stop that
        if(GBAEngine::activeChannelB) {
            if(!GBAEngine::activeChannelB->done()) return;
            GBAEngine::activeChannelB = nullptr;
        }
        GBAEngine::activeChannelB = SoundControl::channelBControl();
        control = GBAEngine::activeChannelB.get();
    }

    stopOnVBlank();
    REG_TM0CNT = 0;
    control->disable();

    REG_SNDDSCNT |= control->getControlFlags();     // output to both sides, reset fifo
    REG_SNDSTAT = SSTAT_ENABLE;                     // enable all sound
    u16 ticksPerSample = CLOCK / sampleRate;        // divide the clock (ticks/second) by the sample rate (samples/second)

    control->accept(data, totalSamples, ticksPerSample);
    startOnVBlank();
    control->enable();

    REG_TM0D = OVERFLOW_16_BIT_VALUE - ticksPerSample;
    REG_TM0CNT = TM_ENABLE | TM_FREQ_1;             // enable timer - dma auto-syncs to this thanks to DMA_SYNC_TO_TIMER
}

GBAEngine::GBAEngine() {
    // setup screen control flags
    REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;

    // setup interrupt control flags for vblank IRQing (started only when sound played)
    REG_DISPSTAT |= DISPLAY_INTERRUPT_VBLANK_ENABLE;
    REG_IE |= INTERRUPT_VBLANK;
    *IRQ_CALLBACK = (u32) &GBAEngine::onVBlank;

    REG_SNDDSCNT = 0;
    disableTextBg = false;
    Allocator::free();
}

void GBAEngine::update() {
    vsync();

    if(sceneToTransitionTo) {
        currentEffectForTransition->update();

        if(currentEffectForTransition->isDone()) {
            setScene(sceneToTransitionTo);
        }
    }

    u16 keys = readKeys();
    currentScene->tick(keys);

    if(currentScene->sprites().size() != spriteManager.getSpriteSize()) {
        updateSpritesInScene();
    }

    spriteManager.render();
}

void GBAEngine::transitionIntoScene(Scene* scene, SceneEffect* effect) {
    sceneToTransitionTo = scene;
    currentEffectForTransition = effect;
    currentEffectForTransition->setSceneToAffect(this->currentScene);
}

void GBAEngine::cleanupPreviousScene()  {
    for(auto bg : currentScene->backgrounds()) {
        bg->clearData();
    }

    delete currentScene;
    sceneToTransitionTo = nullptr;
    delete currentEffectForTransition;
}

void GBAEngine::setScene(Scene* scene) {
    dequeueAllSounds();
    if(this->currentScene) {
        cleanupPreviousScene();
        if(!this->disableTextBg) {
            TextStream::instance().clear();
        }
    }
    scene->load();

    auto fgPalette = scene->getForegroundPalette();
    if(!fgPalette) {
        failure_gba(NoFgPaletteDefined);
    }
    fgPalette->persist();
    auto bgPalette = scene->getBackgroundPalette();
    if(!bgPalette) {
        failure_gba(NoBgPaletteDefined);
    }
    bgPalette->persist();

    if(!this->disableTextBg) {
        TextStream::instance().persist();
    }

    for(const auto bg : scene->backgrounds()) {
        bg->persist();
    }

    this->currentScene = scene;
    updateSpritesInScene();
}

void GBAEngine::updateSpritesInScene() {
    Allocator::free();
    spriteManager.set(currentScene->sprites());
    spriteManager.persist();
}