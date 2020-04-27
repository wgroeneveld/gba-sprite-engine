//
// Created by michi on 14/04/2020.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include "GameScreen.h"
#include "../img/shared.h"
#include "../img/speler1.h"
#include "../img/spelerAI.h"
#include "../img/hoofdpersonage.h"
#include "MainMenuScreen.h"
#include "../backgrounds/tilesNummers.h"
#include "../backgrounds/tilesMetRandMap.h"
#include "VangspelScreen.h"

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>



void GameScreen::load() {
    //TextStream::instance().setText(std::string("Blub."), 3, 1);

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(tilesNummersPal, sizeof(tilesNummersPal)));
    background = std::unique_ptr<Background>(new Background(1, tilesNummersTiles, sizeof(tilesNummersTiles), tilesMetRandMap, sizeof(tilesMetRandMap)));
    background.get()->useMapScreenBlock(16);

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(hoofdpersonagePal, sizeof(hoofdpersonagePal)));

    SpriteBuilder<Sprite> spriteBuilder;



    speler1Sprite = spriteBuilder
            .withData(hoofdpersonageTiles, sizeof(hoofdpersonageTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 40)
            .withLocation(0, 0)
            .buildPtr();

}

std::vector<Sprite *> GameScreen::sprites() {
    return {speler1Sprite.get()};

}

std::vector<Background *> GameScreen::backgrounds() {
    return {background.get()};
}

void GameScreen::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }


    if (!(keys & KEY_UP) && (lastKeys & KEY_UP)) {
        game.movePlayer();
    }

    /*
    if (!(keys & KEY_RIGHT) && (lastKeys & KEY_RIGHT)) {
        game.switchSelectedPlayer();
    }*/


    updateSpeler1();

    if (double(game.getSpeler1Vakje()) == 1) {
        int n = 0;
        while(n < 500000) {
            n++;
        }
        engine->setScene(new VangspelScreen(engine));
    }


    lastKeys = keys;


}

void GameScreen::updateSpeler1() {
    int teller = 0;
    int n = game.getSpeler1Vakje();
    while (n >= 5) {
        teller++;
        n = n - 5;
    }
    speler1Sprite.get()->moveTo(n * 32, teller*32);
}


