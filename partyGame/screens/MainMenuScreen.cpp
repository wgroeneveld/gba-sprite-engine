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
#include "boardScreen.h"
#include "../img/minion_image.h"
//#include "../backgrounds/testtest2.h"
#include "../img/basketballAnimated.h"
#include "../img/stickmanAnimated.h"
#include "../img/shared.h"
#include "../backgrounds/map.h"
#include "../backgrounds/tiles.h"
#include "GameScreen.h"


std::vector<Background *> MainMenuScreen::backgrounds() {
    return {background.get()};
}

std::vector<Sprite *> MainMenuScreen::sprites() {
    return {stickman.get(), basketball.get()};
}

void MainMenuScreen::updateSelect() {
    //minion->moveTo(70, 360);
}

void MainMenuScreen::load() {
    //foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(spritesPal, sizeof(spritesPal)));
   // backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    //foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(minion_palette, sizeof(minion_palette)));
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));

    //TextStream::instance().setText("WELCOME TO PARTY GAME", 3, 3);
    //TextStream::instance().setText("BoardScreen", 7, 8);
    //TextStream::instance().setText("AboutScreen", 11, 8);

    SpriteBuilder<Sprite> spriteBuilder;
/*
   minion = spriteBuilder
            .withData(minion_data, sizeof(minion_data))
            .withSize(SIZE_32_32)
            .withAnimated(2, 20)
            .withLocation(70, 320)
            .buildPtr();*/
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

    //backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(backgroundPal, sizeof(backgroundPal)));
    //background = std::unique_ptr<Background>(new Background(1, backgroundTiles, sizeof(backgroundTiles), backgroundMap, sizeof(backgroundMap)));
    //background->useMapScreenBlock(24);

   // backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(CityBGPal, sizeof(CityBGPal)));
   // background = std::unique_ptr<Background>(new Background(1, CityBGTiles, sizeof(CityBGTiles), City_Map, sizeof(City_Map)));
    //background.get()->useMapScreenBlock(16);

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(tilesPal, sizeof(tilesPal)));
    background = std::unique_ptr<Background>(new Background(1, tilesTiles, sizeof(tilesTiles), map, sizeof(map)));
    background.get()->useMapScreenBlock(16);
}

void MainMenuScreen::tick(u16 keys) {
    if (keys & KEY_START) { //KEY_START = enter
        engine->setScene(new GameScreen(engine));
    }
    if (keys & KEY_UP) { //KEY_START = enter
        engine->setScene(new boardScreen(engine));
    }
    if (keys & KEY_DOWN) { //KEY_START = enter
        updateSelect();
    }

    if(keys & KEY_LEFT) {
        //background.get()->scroll(5,0);
        int blub = basketball.get()->getX();
        basketball.get()->moveTo(blub-5,300);

    }
    if (keys & KEY_RIGHT) {
        //background.get()->scrollSpeed(5,0);
        int blub = basketball.get()->getX();
        basketball.get()->moveTo(blub+5,300);
    }



}
