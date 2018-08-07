//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_GBAENGINE_H
#define GBA_SPRITE_ENGINE_GBAENGINE_H


#include <engine/sprites/sprite_manager.h>
#include <engine/gba/tonc_memmap.h>
#include <engine/gba/tonc_memdef.h>
#include <engine/effects/scene_effect.h>
#include "Scene.h"

#define CLOCK 16777216
#define CYCLES_PER_BLANK 280806
#define OVERFLOW_16_BIT_VALUE 65536
#define DISPLAY_INTERRUPT_VBLANK_ENABLE 0x08
#define INTERRUPT_VBLANK 0x1
#define DMA_SYNC_TO_TIMER 0x30000000

#define IRQ_CALLBACK ((volatile unsigned int*) 0x3007FFC)

enum SoundChannel {
    ChannelA, ChannelB
};

struct SoundControl {
    vu32* DMAControl;               // ex. &REG_DMA1CNT
    vu32* DMASourceAddress;         // ex. &REG_DMA1SAD
    vu32* DMADestinationAddress;    // ex. &REG_DMA1DAD
    vu32* FiFoBuffer;               // ex. &REG_FIFOA
    u16 ControlFlags;
};

void onvblank();

class GBAEngine {
private:
    // WHY raw pointers? the engine does the transition and cleanup work itself
    Scene* currentScene;
    Scene* sceneToTransitionTo;
    SceneEffect* currentEffectForTransition;

    SpriteManager spriteManager;

    void vsync() {
        while (REG_VCOUNT >= 160);
        while (REG_VCOUNT < 160);
    }
    SoundControl channelAControl();
    SoundControl channelBControl();
    SoundControl soundControl(SoundChannel channel) {
        return channel == ChannelA ? channelAControl() : channelBControl();
    };

    void cleanupPreviousScene();
    void queueSound(const s8* data, int totalSamples, int sampleRate, SoundControl control);

public:
    GBAEngine();

    void setScene(Scene* scene);
    void transitionIntoScene(Scene* scene, SceneEffect* effect);

    void queueMusic(const s8* data, int totalSamples) {
        queueSound(data, totalSamples, 16000, soundControl(ChannelA));
    }
    void queueSound(const s8* data, int totalSamples) {
        queueSound(data, totalSamples, 16000, soundControl(ChannelB));
    }

    u16 readKeys();
    void update();
    void delay(int times) {
        for(int i = 0; i < times; i++){}
    }
};


#endif //GBA_SPRITE_ENGINE_GBAENGINE_H
