//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <engine/gba/tonc_memdef.h>
#include <engine/background/text_stream.h>
#include "gba_engine.h"
#include "allocator.h"

SoundControl* GBAEngine::activeChannelA;
SoundControl* GBAEngine::activeChannelB;

void GBAEngine::vsync() {
    while (REG_VCOUNT >= 160);
    while (REG_VCOUNT < 160);
}

void GBAEngine::onVBlank() {
    stopOnVBlank();

    unsigned short tempInterruptState = REG_IF;

    if((REG_IF & INTERRUPT_VBLANK) == INTERRUPT_VBLANK) {
        if(GBAEngine::activeChannelA && GBAEngine::activeChannelA->done()) {

        }
        if(GBAEngine::activeChannelB) {
            if(GBAEngine::activeChannelB->done()) {
                GBAEngine::activeChannelB->disable();
                delete GBAEngine::activeChannelB;
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

    if(GBAEngine::activeChannelA) {
        GBAEngine::activeChannelA->disable();
    } if(GBAEngine::activeChannelB) {
        GBAEngine::activeChannelB->disable();
    }
}

void GBAEngine::enqueueSound(const s8 *data, int totalSamples, int sampleRate, SoundChannel channel) {
    SoundControl* control;
    stopOnVBlank();

    if(channel == ChannelA) {                       // repeating bg music can be restarted
        if(GBAEngine::activeChannelA) delete GBAEngine::activeChannelA;
        control = SoundControl::channelAControl();
        GBAEngine::activeChannelA = control;
    } else {                                        // sound still playing, don't stop that
        if(GBAEngine::activeChannelB) {
            if(!GBAEngine::activeChannelB->done()) return;
            delete GBAEngine::activeChannelB;
        }
        control = SoundControl::channelBControl();
        GBAEngine::activeChannelB = control;
    }

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
    Allocator::free();
}

void GBAEngine::update() {
    if(sceneToTransitionTo) {
        dequeueAllSounds();
        currentEffectForTransition->update();

        if(currentEffectForTransition->isDone()) {
            setScene(sceneToTransitionTo);
        }
    }

    u16 keys = readKeys();
    this->currentScene->tick(keys);

    vsync();
    spriteManager.render();
}

void GBAEngine::transitionIntoScene(Scene *scene, SceneEffect* effect) {
    sceneToTransitionTo = scene;
    currentEffectForTransition = effect;
    currentEffectForTransition->setSceneToAffect(this->currentScene);
}

void GBAEngine::cleanupPreviousScene()  {
    delete currentScene;
    sceneToTransitionTo = nullptr;
    delete currentEffectForTransition;
}

void GBAEngine::setScene(Scene* scene) {
    if(this->currentScene) {
        cleanupPreviousScene();
        TextStream::instance().clear();
    }
    scene->load();

    auto fgPalette = scene->getForegroundPalette();
    if(fgPalette) {
        fgPalette->persist();
    }
    auto bgPalette = scene->getBackgroundPalette();
    if(bgPalette) {
        bgPalette->persist();
    }

    Allocator::free();
    TextStream::instance().persist();

    spriteManager.set(scene->sprites());
    spriteManager.persist();

    for(const auto bg : scene->backgrounds()) {
        bg->persist();
    }

    this->currentScene = scene;
}
