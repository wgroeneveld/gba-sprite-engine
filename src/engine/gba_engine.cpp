//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <engine/gba/tonc_memdef.h>
#include <engine/background/text_stream.h>
#include "gba_engine.h"
#include "allocator.h"

void GBAEngine::update() {
    vsync();

    spriteManager.render();
    u16 keys = readKeys();
    this->currentScene->tick(keys);
}

u16 GBAEngine::readKeys() {
    return ~REG_KEYS & KEY_ANY;
}

GBAEngine::GBAEngine() {
    REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
    Allocator::free();
}

void GBAEngine::setScene(Scene& scene) {
    if(this->currentScene) {
        cleanupPreviousScene();
    }
    scene.load();

    auto fgPalette = scene.getForegroundPalette();
    if(fgPalette) {
        fgPalette->persist();
    }
    auto bgPalette = scene.getBackgroundPalette();
    if(bgPalette) {
        bgPalette->persist();
    }

    Allocator::free();
    TextStream::instance().persist();

    spriteManager.set(scene.sprites());
    spriteManager.persist();

    for(const auto bg : scene.backgrounds()) {
        bg->persist();
    }

    this->currentScene = &scene;
}
