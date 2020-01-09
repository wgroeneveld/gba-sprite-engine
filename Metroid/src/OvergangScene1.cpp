//
// Created by kyles on 9/01/2020.
//

#include "OvergangScene1.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "achtergrond.h"
#include "Level2.h"

OvergangScene1::OvergangScene1(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> OvergangScene1::sprites() {
    return {};
}

std::vector<Background *> OvergangScene1::backgrounds() {
    return {bg.get()};
}

void OvergangScene1::tick(u16 keys) {

    engine->getTimer()->start();
    if(engine->getTimer()->getSecs() > 11) {
        if (!engine->isTransitioning()) {
            engine->transitionIntoScene(new Level2(engine), new FadeOutScene(6));
        }
    }
}

void OvergangScene1::load() {
    engine.get()->disableText();
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(tussenschermMapPal, sizeof(tussenschermMapPal)));

    bg = std::unique_ptr<Background>(new Background(0, tussenschermTiles, sizeof(tussenschermTiles), tussenschermMap, sizeof(tussenschermMap),24,0,MAPLAYOUT_32X32));


}

