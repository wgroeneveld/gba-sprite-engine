//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_GBAENGINE_H
#define GBA_SPRITE_ENGINE_GBAENGINE_H


#include <engine/sprites/sprite_manager.h>
#include <engine/gba/tonc_memmap.h>
#include <engine/effects/scene_effect.h>
#include "Scene.h"

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
    void cleanupPreviousScene();

public:
    GBAEngine();

    void setScene(Scene* scene);
    void transitionIntoScene(Scene* scene, SceneEffect* effect);

    u16 readKeys();
    void update();
    void delay(int times) {
        for(int i = 0; i < times; i++){}
    }
};


#endif //GBA_SPRITE_ENGINE_GBAENGINE_H
