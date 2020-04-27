//
// Created by michi on 21/03/2020.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "MainMenuScreen.h"
#include "AboutScreen.h"
#include "../img/basketballAnimated.h"
#include "../img/stickmanAnimated.h"
#include "../img/shared.h"
//#include "../backgrounds/map.h"
//#include "../backgrounds/tiles.h"
#include "../backgrounds/tilesMetRand.h"
#include "../backgrounds/tilesMetRandMap.h"
#include "../backgrounds/tilesNummers.h"
#include "GameScreen.h"


std::vector<Background *> MainMenuScreen::backgrounds() {
    return {/*background.get()*/};
}

std::vector<Sprite *> MainMenuScreen::sprites() {
    return {/*stickman.get(), basketball.get()*/};
}


void MainMenuScreen::load() {
    TextStream::instance().setText(std::string("UP go to the game"), 1, 1);
    TextStream::instance().setText(std::string("DOWN read more about the game"), 3, 1);
/*
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));


    SpriteBuilder<Sprite> spriteBuilder;



    stickman = spriteBuilder
            .withData(stickmanAnimatedTiles, sizeof(stickmanAnimatedTiles))
            .withSize(SIZE_32_32)
            .withAnimated(4, 40)
            .withLocation(110, 300)
            .buildPtr();

    basketball = spriteBuilder
            .withData(basketballAnimatedTiles, sizeof(basketballAnimatedTiles))
            .withSize(SIZE_32_32)
            .withAnimated(4, 40)
            .withLocation(70, 300)
            .buildPtr();

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(tilesNummersPal, sizeof(tilesNummersPal)));
    background = std::unique_ptr<Background>(new Background(1, tilesNummersTiles, sizeof(tilesNummersTiles), tilesMetRandMap, sizeof(tilesMetRandMap)));
    background.get()->useMapScreenBlock(16);*/

}

void MainMenuScreen::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (!(keys & KEY_UP) && (lastKeys & KEY_UP)) {// ENTER key, wait until released
        engine->setScene(new GameScreen(engine));
    }

    if (!(keys & KEY_DOWN) && (lastKeys & KEY_DOWN)) {// ENTER key, wait until released
        engine->setScene(new AboutScreen(engine));
    }



    lastKeys = keys;


}
