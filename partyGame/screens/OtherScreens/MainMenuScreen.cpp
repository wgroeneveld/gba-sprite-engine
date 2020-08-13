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
#include "PlayerSelectScreen.h"

#include "../../sprites/pijl.h"
#include "../../sprites/shared.h"

#include "../../backgrounds/standard/gras.h"
#include "../../backgrounds/standard/grasBackground.h"


void MainMenuScreen::load() {
    TextStream::instance().setText(std::string("Start Game"), 7, 5);
    TextStream::instance().setText(std::string("More about the game"), 10, 5);
    TextStream::instance().setText(std::string("WELCOME TO SPOOK-Y TOWN"), 2, 3);

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    SpriteBuilder<Sprite> spriteBuilder;
    pijl = spriteBuilder
            .withData(pijlTiles, sizeof(pijlTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 40)
            .withLocation(5, 46)
            .buildPtr();

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(grasPal, sizeof(grasPal)));
    background = std::unique_ptr<Background>(new Background(1, grasTiles, sizeof(grasTiles), grasBackground, sizeof(grasBackground)));
    background->useMapScreenBlock(16);
}

std::vector<Background *> MainMenuScreen::backgrounds() {return {background.get()};}

std::vector<Sprite *> MainMenuScreen::sprites() {return {pijl.get()};}

void MainMenuScreen::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (!(keys & KEY_START) && (lastKeys & KEY_START)) {// ENTER key, wait until released
        if (keuze == 0) {
            if (!engine->isTransitioning()) {
                engine->setScene(new PlayerSelectScreen(engine));
            }
        }
        else {
            engine->setScene(new AboutScreen(engine));
        }
    }
    else if ((keys & KEY_DOWN) && !(lastKeys & KEY_DOWN)) {
        if (keuze == 0) {
            keuze++;
            updatePijl();
        }
    }
    else if ((keys & KEY_UP) && !(lastKeys & KEY_UP)) {
        if (keuze == 1) {
            keuze--;
            updatePijl();
        }
    }
    lastKeys = keys;
}
void MainMenuScreen::updatePijl() {
    pijl->moveTo(5, 46 + keuze * 24);
}
