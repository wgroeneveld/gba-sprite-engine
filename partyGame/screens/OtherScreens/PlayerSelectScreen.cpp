//
// Created by michi on 10/08/2020.
//

#include "PlayerSelectScreen.h"


#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>

#include "../GameScreen/GameScreen.h"

#include "../../backgrounds/standard/gras.h"
#include "../../backgrounds/standard/grasBackground.h"

#include "../../Sprites/wit_spook_1.h"
#include "../../Sprites/wit_spook_2.h"
#include "../../Sprites/pijl.h"
#include "../../Sprites/shared.h"



std::vector<Background *> PlayerSelectScreen::backgrounds() {return {background.get()};}

std::vector<Sprite *> PlayerSelectScreen::sprites() {return {pijl.get(), spook1.get(), spook2.get()};}

void PlayerSelectScreen::load() {
    TextStream::instance().setText(std::string("Choose Your player"), 2, 5);


    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    SpriteBuilder<Sprite> spriteBuilder;
    pijl = spriteBuilder
            .withData(pijlTiles, sizeof(pijlTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 40)
            .withLocation(5, 52)
            .buildPtr();
    spook1 = spriteBuilder
            .withData(wit_spook_1Tiles, sizeof(wit_spook_1Tiles))
            .withSize(SIZE_32_32)
            .withAnimated(6, 8)
            .withLocation(40, 46)
            .buildPtr();
    spook2 = spriteBuilder
            .withData(wit_spook_2Tiles, sizeof(wit_spook_2Tiles))
            .withSize(SIZE_32_32)
            .withAnimated(6, 8)
            .withLocation(40, 90)
            .buildPtr();

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(grasPal, sizeof(grasPal)));
    background = std::unique_ptr<Background>(new Background(1, grasTiles, sizeof(grasTiles), grasBackground, sizeof(grasBackground)));
    background->useMapScreenBlock(20);
}

void PlayerSelectScreen::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (!(keys & KEY_START) && (lastKeys & KEY_START)) {// ENTER key, wait until released
        if (spelerKeuze == 0) {
            if (!engine->isTransitioning()) {
                engine->setScene(new GameScreen(engine,0));
            }
        }
        else {
            engine->setScene(new GameScreen(engine, 1));
        }
    }
    else if ((keys & KEY_DOWN) && !(lastKeys & KEY_DOWN)) {
        if (spelerKeuze == 0) {
            spelerKeuze++;
            updatePijl();
        }
    }
    else if ((keys & KEY_UP) && !(lastKeys & KEY_UP)) {
        if (spelerKeuze == 1) {
            spelerKeuze--;
            updatePijl();
        }
    }
    lastKeys = keys;
}

void PlayerSelectScreen::updatePijl() {
    pijl->moveTo(5, 52 + spelerKeuze * 44);
}
