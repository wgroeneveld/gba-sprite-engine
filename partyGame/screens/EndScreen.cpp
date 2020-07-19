//
// Created by michi on 17/07/2020.
//
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include "EndScreen.h"

std::vector<Background *> EndScreen::backgrounds() {
    return {/*background.get()*/};
}

std::vector<Sprite *> EndScreen::sprites() {
    return {/*stickman.get(), basketball.get()*/};
}


void EndScreen::load() {
    TextStream::instance().setText(std::string("EndScreen"), 1, 1);
}

void EndScreen::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (!(keys & KEY_UP) && (lastKeys & KEY_UP)) {// ENTER key, wait until released
        //engine->setScene(new GameScreen(engine));
    }

    lastKeys = keys;


}
