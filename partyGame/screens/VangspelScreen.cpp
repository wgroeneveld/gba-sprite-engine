//
// Created by michi on 27/04/2020.
//

#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "VangspelScreen.h"

std::vector<Background *> VangspelScreen::backgrounds() {
    return {/*background.get()*/}; }


std::vector<Sprite *> VangspelScreen::sprites() { return {};}

void VangspelScreen::load() {

    TextStream::instance().setText("Ik speel een spel.", 1, 1);




}

void VangspelScreen::tick(u16 keys) {
    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }




    lastKeys = keys;


}