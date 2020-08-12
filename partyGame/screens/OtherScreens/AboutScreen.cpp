//
// Created by michi on 22/03/2020.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "AboutScreen.h"
#include "MainMenuScreen.h"

#include "../../backgrounds/gras.h"
#include "../../backgrounds/grasBackground.h"



std::vector<Background *> AboutScreen::backgrounds() {
    return {background.get()};}


std::vector<Sprite *> AboutScreen::sprites() { return {};}

void AboutScreen::load() {

    TextStream::instance().setText("AboutScreen", 1, 1);
    TextStream::instance().setText("Verhaaltje", 3, 1);

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(grasPal, sizeof(grasPal)));
    background = std::unique_ptr<Background>(new Background(1, grasTiles, sizeof(grasTiles), grasBackground, sizeof(grasBackground)));
    background->useMapScreenBlock(16);

}

void AboutScreen::tick(u16 keys) {
    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }


        lastKeys = keys;
}