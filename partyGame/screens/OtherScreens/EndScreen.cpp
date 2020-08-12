//
// Created by michi on 17/07/2020.
//
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include "EndScreen.h"
#include "MainMenuScreen.h"
#include "../../backgrounds/gras.h"
#include "../../backgrounds/grasBackground.h"
#include "../../sound/win.h"

std::vector<Background *> EndScreen::backgrounds() {
    return {background.get()};
}

std::vector<Sprite *> EndScreen::sprites() {
    return {};
}


void EndScreen::load() {
    TextStream::instance().setText(std::string("Yay! You made it!"), 1, 1);
    TextStream::instance().setText(std::string("Score: " + std::to_string(score)), 2, 1);

    TextStream::instance().setText(std::string("Press start for the main menu"), 10, 1);

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(grasPal, sizeof(grasPal)));
    background = std::unique_ptr<Background>(new Background(1, grasTiles, sizeof(grasTiles), grasBackground, sizeof(grasBackground)));
    background->useMapScreenBlock(16);

    engine->enqueueMusic(win, sizeof(win), 44100);
}

void EndScreen::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (!(keys & KEY_START) && (lastKeys & KEY_START)) {
        engine->setScene(new MainMenuScreen(engine));
    }

    lastKeys = keys;


}
