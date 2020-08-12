//
// Created by michi on 17/07/2020.
//
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include "EndScreen.h"
#include "MainMenuScreen.h"

std::vector<Background *> EndScreen::backgrounds() {
    return {/*background.get()*/};
}

std::vector<Sprite *> EndScreen::sprites() {
    return {/*stickman.get(), basketball.get()*/};
}


void EndScreen::load() {
    TextStream::instance().setText(std::string("Yay! You made it!"), 1, 1);
    TextStream::instance().setText(std::string("Score: " + std::to_string(score)), 2, 1);

    TextStream::instance().setText(std::string("Press start for the main menu"), 10, 1);

}

void EndScreen::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (!(keys & KEY_START) && (lastKeys & KEY_START)) {// ENTER key, wait until released
        engine->setScene(new MainMenuScreen(engine));
    }

    lastKeys = keys;


}
