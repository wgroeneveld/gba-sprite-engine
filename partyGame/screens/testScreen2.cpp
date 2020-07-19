//
// Created by michi on 18/07/2020.
//

#include "testScreen2.h"
#include "testScreen1.h"
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>

void testScreen2::load() {

    TextStream::instance().setText(std::string("testScreen2"), 1, 5);
    //TextStream::instance().setText(std::string(std::to_string(*pointerTeller)), 2, 5);
}
std::vector<Sprite *> testScreen2::sprites() {
    return {/*ufo.get()*/};

}

std::vector<Background *> testScreen2::backgrounds() {
    return {/*background.get()*/};
}

void testScreen2::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }



    if (!(keys & KEY_RIGHT) && (lastKeys & KEY_RIGHT)) {// ENTER key, wait until released
        engine->setScene(new testScreen1 (engine, referenceTest));
    }
    if (!(keys & KEY_UP) && (lastKeys & KEY_UP)) {// ENTER key, wait until released
        //(*pointerTeller)++;
        referenceTest.verhoogTweedeGetal();
    }
    TextStream::instance().setText(std::string(std::to_string(referenceTest.getEersteGetal())), 2, 5);
    TextStream::instance().setText(std::string(std::to_string(referenceTest.getTweedeGetal())), 3, 5);
    lastKeys = keys;
}



