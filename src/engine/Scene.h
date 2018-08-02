//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_SCRENE_H
#define GBA_SPRITE_ENGINE_SCRENE_H

#include <vector>
#include <functional>
#include <engine/background/background.h>
#include "engine/sprites/sprite.h"
#include "palette_manager.h"

class Scene {
protected:
    std::unique_ptr<ForegroundPaletteManager> foregroundPalette;
    std::unique_ptr<BackgroundPaletteManager> backgroundPalette;
    std::function<void (Scene&)> onNextSceneFn;

public:
    ForegroundPaletteManager* getForegroundPalette() { return foregroundPalette.get(); }
    BackgroundPaletteManager* getBackgroundPalette() { return backgroundPalette.get(); }
    // bg music in here
    virtual std::vector<Sprite*> sprites() = 0;
    virtual std::vector<Background*> backgrounds() = 0;
    virtual void load() = 0;
    virtual void tick(u16 i) = 0;

    void onNextScene(std::function<void(Scene &)> fn) { onNextSceneFn = fn; };


    Scene() { }
    ~Scene() {
        // scenes should manage their own resources - use std::unique_ptr
    }

};


#endif //GBA_SPRITE_ENGINE_SCRENE_H
