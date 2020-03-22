//
// Created by michi on 22/03/2020.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "About.h"
#include "MainMenu.h"

std::vector<Background *> About::backgrounds() {return {};}


std::vector<Sprite *> About::sprites() { return {};}

void About::load() {
    //foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(spritesPal, sizeof(spritesPal)));
    // backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    TextStream::instance().setText("About", 3, 8);
}

void About::tick(u16 keys) {
    if (keys & KEY_START) {
        engine->transitionIntoScene(new MainMenu(engine), new FadeOutScene(2));
    }
     /*
    if (keys & KEY_START) {
        if (!engine->isTransitioning()) {

            //TextStream::instance() << "entered: starting next scene";

            //engine->transitionIntoScene(new level1(engine), new FadeOutScene(2));
        }*/
}