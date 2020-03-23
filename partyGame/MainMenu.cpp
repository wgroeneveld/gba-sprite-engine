//
// Created by michi on 21/03/2020.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "MainMenu.h"
#include "About.h"
#include "boardScreen.h"

std::vector<Background *> MainMenu::backgrounds() {
    return {};
}


std::vector<Sprite *> MainMenu::sprites() {


    return {};
}

void MainMenu::load() {
    //foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(spritesPal, sizeof(spritesPal)));
   // backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    TextStream::instance().setText("PRESS START", 3, 8);
}

void MainMenu::tick(u16 keys) {
    if (keys & KEY_START) { //KEY_START = enter
        engine->transitionIntoScene(new About(engine), new FadeOutScene(2));
    }
    if (keys & KEY_UP) { //KEY_START = enter
        engine->transitionIntoScene(new boardScreen(engine), new FadeOutScene(2));
    }

     /*
    if (keys & KEY_START) {
        if (!engine->isTransitioning()) {

            //TextStream::instance() << "entered: starting next scene";

            //engine->transitionIntoScene(new level1(engine), new FadeOutScene(2));
        }*/
    }
