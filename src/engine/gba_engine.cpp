//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <engine/gba/tonc_memdef.h>
#include <engine/background/text_stream.h>
#include "gba_engine.h"
#include "allocator.h"

void GBAEngine::render() {
    vsync();

    spriteManager.render();
    this->currentScene->tick();
}

GBAEngine::GBAEngine() {
    REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;
    Allocator::free();
}

void GBAEngine::setScene(Scene& scene) {
    if(this->currentScene) {
        cleanupPreviousScene();
    }

    scene.load();
    Allocator::free();
    TextStream::instance().persist();

    spriteManager.set(scene.sprites());
    spriteManager.persist();

    for(const auto bg : scene.backgrounds()) {
        bg->persist();
    }

    this->currentScene = &scene;
}
