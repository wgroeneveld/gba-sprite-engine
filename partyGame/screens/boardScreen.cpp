//
// Created by michi on 23/03/2020.
//
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "boardScreen.h"
#include "MainMenuScreen.h"

std::vector<Background *> boardScreen::backgrounds() {return {};}


std::vector<Sprite *> boardScreen::sprites() { return {};}

void boardScreen::load() {
    //foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(spritesPal, sizeof(spritesPal)));
    // backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    TextStream::instance().setText("boardScreen", 3, 8);

    // nieuw stuk
    //backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(startscreenimagePal, sizeof(startscreenimagePal)));
    //auto bg = std::unique_ptr<Background>(new Background(0, startscreenimageTiles, sizeof(startscreenimageTiles), startscreenimageMap, sizeof(startscreenimageMap)));
    //bg->useMapScreenBlock(24);
}

void boardScreen::tick(u16 keys) {
    if (keys & KEY_START) {
        engine->setScene(new MainMenuScreen(engine));
    }
    /*
   if (keys & KEY_START) {
       if (!engine->isTransitioning()) {

           //TextStream::instance() << "entered: starting next scene";

           //engine->transitionIntoScene(new level1(engine), new FadeOutScene(2));
       }*/
}