//
// Created by michi on 21/03/2020.
//


#include <libgba-sprite-engine/background/text_stream.h>
#include "MainMenu.h"

std::vector<Background *> MainMenu::backgrounds() {
    return {};
}


std::vector<Sprite *> MainMenu::sprites() {


    return {};
}

void MainMenu::load() {
    //foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(spritesPal, sizeof(spritesPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    TextStream::instance().setText("PRESS START", 3, 8);
}

void MainMenu::tick(u16 keys) {
    /*if (keys) {
        //goomba ->flipHorizontally(true);
    }
    if (keys & KEY_START) {
        if (!engine->isTransitioning()) {

            //TextStream::instance() << "entered: starting next scene";

            //engine->transitionIntoScene(new level1(engine), new FadeOutScene(2));
        }*/
    }
