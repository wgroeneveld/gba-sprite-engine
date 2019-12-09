//
// Created by Erwin on 20/11/2019.
//
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "Start_Screen.h"

std::vector<Background *> Start_Screen::backgrounds() {
    return {};
}

std::vector<Sprite *> Start_Screen::sprites() {
    return {sp_arrow.get()};
}

void Start_Screen::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal,sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    SpriteBuilder<Sprite> builder;

    sp_arrow = builder
            .withData(arrowTiles, sizeof(arrowTiles))
            .withSize(SIZE_16_16)
            .withLocation(64, 36)
            .buildPtr();

    TextStream::instance().setText("START THE GAME", 5, 10);
    TextStream::instance().setText("CHOOSE CHARACTER", 10, 10);

}


Startscreen::Start_Screen(std::shared_ptr<GBAEngine> gameEngine, int charachter) {

}
