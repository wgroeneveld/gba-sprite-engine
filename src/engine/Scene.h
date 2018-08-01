//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_SCRENE_H
#define GBA_SPRITE_ENGINE_SCRENE_H

#include <vector>
#include <engine/background/background.h>
#include "engine/sprites/sprite.h"

class Scene {
public:
    // bg in here
    // bg music in here
    virtual std::vector<Sprite*> sprites() = 0;
    virtual std::vector<Background*> backgrounds() = 0;
    virtual void load() = 0;
    virtual void tick() = 0;

    Scene() { }
    ~Scene() {
        // scenes should manage their own resources - use std::unique_ptr
    }

};


#endif //GBA_SPRITE_ENGINE_SCRENE_H
