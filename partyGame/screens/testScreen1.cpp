//
// Created by michi on 18/07/2020.
//

#include "testScreen1.h"
#include "testScreen2.h"
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>

void testScreen1::load() {

    TextStream::instance().setText(std::string("testScreen1"), 1, 5);
}
std::vector<Sprite *> testScreen1::sprites() {
    return {/*ufo.get()*/};

}

std::vector<Background *> testScreen1::backgrounds() {
    return {/*background.get()*/};
}

void testScreen1::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (!(keys & KEY_RIGHT) && (lastKeys & KEY_RIGHT)) {// ENTER key, wait until released
        //engine->setScene(new testScreen2 (engine, pointerTest));
        engine->setScene(new testScreen2 (engine, referenceTest));
    }
    if (!(keys & KEY_UP) && (lastKeys & KEY_UP)) {// ENTER key, wait until released
        //(*pointerTeller)++;
        referenceTest.verhoogEersteGetal();
    }
    TextStream::instance().setText(std::string(std::to_string(referenceTest.getEersteGetal())), 2, 5);
    TextStream::instance().setText(std::string(std::to_string(referenceTest.getTweedeGetal())), 3, 5);
    lastKeys = keys;
}




