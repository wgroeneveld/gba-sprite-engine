//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_GBAENGINE_H
#define GBA_SPRITE_ENGINE_GBAENGINE_H


#include <engine/sprites/sprite_manager.h>
#include <engine/gba/tonc_memmap.h>
#include "Scene.h"

class GBAEngine {
private:
    Scene* currentScene;
    SpriteManager spriteManager;

    void vsync() {
        while (REG_VCOUNT >= 160);
        while (REG_VCOUNT < 160);
    }
    void cleanupPreviousScene() {
        delete currentScene;
    }

public:
    GBAEngine();

    void setScene(Scene* scene);
    u16 readKeys();
    void update();
    void delay(int times) {
        for(int i = 0; i < times; i++){}
    }
};


#endif //GBA_SPRITE_ENGINE_GBAENGINE_H
