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
#include "sound.h"

class GBAEngine {
private:
    // WHY raw pointers? the engine does the transition and cleanup work itself
    Scene* currentScene;
    Scene* sceneToTransitionTo;
    SceneEffect* currentEffectForTransition;

    SpriteManager spriteManager;

    static std::unique_ptr<SoundControl> activeChannelA;
    static std::unique_ptr<SoundControl> activeChannelB;

    void vsync();
    void cleanupPreviousScene();
    void enqueueSound(const s8 *data, int totalSamples, int sampleRate, SoundChannel channel);

    static void startOnVBlank() { REG_IME = 1; }
    static void stopOnVBlank() { REG_IME = 0; }
    static void onVBlank();

public:
    GBAEngine();

    void setScene(Scene* scene);
    void transitionIntoScene(Scene* scene, SceneEffect* effect);
    bool isTransitioning() { return currentEffectForTransition != nullptr; }

    void dequeueAllSounds();
    void enqueueMusic(const s8 *data, int totalSamples) {
        enqueueSound(data, totalSamples, 16000, ChannelA);
    }
    void enqueueSound(const s8 *data, int totalSamples) {
        enqueueSound(data, totalSamples, 16000, ChannelB);
    }

    u16 readKeys();
    void update();
    void delay(int times) {
        for(int i = 0; i < times; i++){}
    }
};


#endif //GBA_SPRITE_ENGINE_GBAENGINE_H
