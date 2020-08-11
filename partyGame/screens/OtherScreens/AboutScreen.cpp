//
// Created by michi on 22/03/2020.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "AboutScreen.h"
#include "MainMenuScreen.h"


std::vector<Background *> AboutScreen::backgrounds() {
    return {/*background.get()*/}; //als ik hier dat laat staan, crasht ie, omdat dat zelfde naam is als bij de andere? Of gewoon omdat er geen background gecreeerd wordt? Het tweede.
}


std::vector<Sprite *> AboutScreen::sprites() { return {};}

void AboutScreen::load() {

    TextStream::instance().setText("AboutScreen", 1, 1);
    TextStream::instance().setText("UP go to the main screen", 3, 1);



}

void AboutScreen::tick(u16 keys) {
    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (!(keys & KEY_UP) && (lastKeys & KEY_UP)) {// ENTER key, wait until released
        engine->transitionIntoScene(new MainMenuScreen(engine), new FadeOutScene(2));
    }

    if (!(keys & KEY_DOWN) && (lastKeys & KEY_DOWN)) {// ENTER key, wait until released
        engine->transitionIntoScene(new MainMenuScreen(engine), new FadeOutScene(2));
    }



    lastKeys = keys;


}