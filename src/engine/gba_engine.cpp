//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <engine/gba/tonc_memdef.h>
#include <engine/background/text_stream.h>
#include "gba_engine.h"
#include "allocator.h"

int x = 0;
void onvblank() {
    REG_IME = 0;

    unsigned short tempInterruptState = REG_IF;

    if((REG_IF & INTERRUPT_VBLANK) == INTERRUPT_VBLANK) {
        // if vblanks_remaning is zero: stop
        //*sound_control &= ~(SOUND_B_RIGHT_CHANNEL | SOUND_B_LEFT_CHANNEL | SOUND_B_FIFO_RESET);
        //*dma2_control = 0;
        // else counter--
        // OR: to restart sound (channelA)


        x++;
    }

    //TextStream::instance() << x;
    REG_IF = tempInterruptState;
    REG_IME = 1;
}

void GBAEngine::update() {
    vsync();

    if(sceneToTransitionTo) {
        currentEffectForTransition->update();

        if(currentEffectForTransition->isDone()) {
            setScene(sceneToTransitionTo);
        }
    }

    spriteManager.render();
    u16 keys = readKeys();
    this->currentScene->tick(keys);
}

void GBAEngine::transitionIntoScene(Scene *scene, SceneEffect* effect) {
    sceneToTransitionTo = scene;
    currentEffectForTransition = effect;
    currentEffectForTransition->setSceneToAffect(this->currentScene);
}

u16 GBAEngine::readKeys() {
    return ~REG_KEYS & KEY_ANY;
}

SoundControl GBAEngine::channelAControl() {
    return {
            &REG_DMA1CNT,
            &REG_DMA1SAD,
            &REG_DMA1DAD,
            &REG_FIFOA,
            SDS_AR | SDS_AL | SDS_ARESET
    };
}

SoundControl GBAEngine::channelBControl() {
    return {
            &REG_DMA2CNT,
            &REG_DMA2SAD,
            &REG_DMA2DAD,
            &REG_FIFOB,
            SDS_BR | SDS_BL | SDS_BRESET
    };
}

void GBAEngine::queueSound(const s8 *data, int totalSamples, int sampleRate, SoundControl control) {
    REG_TM0CNT = 0;
    *(control.DMAControl) = 0;                      // reset previous sound

    REG_SNDDSCNT |= control.ControlFlags;           // output to both sides, reset fifo
    REG_SNDSTAT = SSTAT_ENABLE;                     // enable all sound

    *(control.DMASourceAddress) = (u32) data;
    *(control.DMADestinationAddress) = *(control.FiFoBuffer);
    *(control.DMAControl) = DMA_DST_FIXED | DMA_REPEAT | DMA_32 | DMA_SYNC_TO_TIMER | DMA_ENABLE;

    u16 ticksPerSample = CLOCK / sampleRate;        // divide the clock (ticks/second) by the sample rate (samples/second)

    REG_TM0D = OVERFLOW_16_BIT_VALUE - ticksPerSample;
    // channel_a_vblanks_remaining = total_samples * ticks_per_sample * (1.0 / CYCLES_PER_BLANK);

    REG_TM0CNT = TM_ENABLE | TM_FREQ_1;             // enable timer - dma auto-syncs to this thanks to DMA_SYNC_TO_TIMER
}

GBAEngine::GBAEngine() {
    // setup screen control flags
    REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;

    // setup interrupt control flags for vblank IRQing
    REG_DISPSTAT |= DISPLAY_INTERRUPT_VBLANK_ENABLE;
    REG_IE |= INTERRUPT_VBLANK;
    *IRQ_CALLBACK = (u32) &onvblank;
    //REG_IME = 1;

    REG_SNDDSCNT = 0;
    Allocator::free();
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
