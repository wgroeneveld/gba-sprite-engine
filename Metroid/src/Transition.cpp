//
// Created by kyles on 27/12/2019.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include "Transition.h"
#include "../achtergrond/AchtergrondTransition.h"
#include "Level2.h"

std::vector<Background *> Transition::backgrounds() {
    return {bg.get()};
}

std::vector<Sprite *> Transition::sprites() {
    return { };
}

void Transition::load() {
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(tussenschermMapPal, sizeof(tussenschermMapPal)));

    bg = std::unique_ptr<Background>(new Background(1, tussenschermTiles, sizeof(tussenschermTiles), tussenschermMap, sizeof(tussenschermMap)));
    bg.get()->useMapScreenBlock(29);

}


void Transition::tick(u16 keys) {


    if (keys & KEY_START) {
        if (!engine->isTransitioning()) {
            engine->transitionIntoScene(new Level2(engine), new FadeOutScene(8));
        }
    }
}