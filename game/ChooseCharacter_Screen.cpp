//
// Created by Erwin on 28/11/2019.
//
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <vector>
#include "ChooseCharacter_Screen.h"
#include "Start_Screen.h"
#include "Sprites_Data.h"

std::vector<Background *> ChooseCharacter_Screen::backgrounds() {
    return {};
}

std::vector<Sprite *> ChooseCharacter_Screen::sprites() {
    return {character_ptr(),
            character_Ben(),
            character_Erwin(),
            character_Stefan(),};
}

void ChooseCharacter_Screen::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal,sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    createSpriteObjects();
    TextStream::instance().setText("CHOOSE YOUR CHARACTER :", 2, 2);
    TextStream::instance().setText("STEFAN IS THE 'BOKKMAN'", 3, 2);
    TextStream::instance().setText("ERWIN IS THE 'SAFMAN'", 4, 2);
    TextStream::instance().setText("AND BEN = BEN", 5, 2);

}

void ChooseCharacter_Screen::tick(u16 keys) {

    /** knoppen voor geheugen bij start */
    right_mem = right_pressed;
    left_mem = left_pressed;
    up_mem  = up_pressed;
    down_mem = down_pressed;
    start_mem = start_pressed;
    if(keys & KEY_RIGHT){right_pressed = true;}
    else{right_pressed = false;}
    if(keys & KEY_LEFT){left_pressed = true;}
    else{left_pressed = false;}
    if(keys & KEY_UP){up_pressed = true;}
    else{up_pressed = false;}
    if(keys & KEY_DOWN){down_pressed = true;}
    else{down_pressed = false;}
    if(keys & KEY_START){start_pressed = true;}
    else{start_pressed  = false;}

    if(character_ptr->getX() == charBen_X & character_ptr->getY() == charBen_Y){
        if(right_pressed == true & right_mem != true){
            character_ptr->moveTo(charBen_X, charBen_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            character_ptr->moveTo(charErwin_X, charErwin_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            character_ptr->moveTo(charStefan_X, charStefan_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
    }
    else if(character_ptr->getX() == charErwin_X & character_ptr->getY() == charErwin_Y){
        if(right_pressed == true & right_mem != true){
            character_ptr->moveTo(charBen_X, charBen_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            character_ptr->moveTo(charErwin_X, charErwin_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            character_ptr->moveTo(charStefan_X, charStefan_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
    }
    else if(character_ptr->getX() == charStefan_X & character_ptr->getY() == charStefan_Y) {
        if (right_pressed == true & right_mem != true) {
            character_ptr->moveTo(charBen_X, charBen_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        } else if (left_pressed == true & left_mem != true) {
            character_ptr->moveTo(charErwin_X, charErwin_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        } else if (up_pressed == true & up_mem != true) {
            character_ptr->moveTo(charStefan_X, charStefan_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
    }
}

void ChooseCharacter_Screen::createSpriteObjects(){
    SpriteBuilder<Sprite> builder;

    character_ptr = builder
            .withData(character_ptr_tiles, sizeof(character_ptr_tiles))
            .withSize(SIZE_16_16)
            .withLocation(charPtr_X, charPtr_Y)
            .buildPtr();
    character_Ben = builder
            .withData(character_Ben_tiles, sizeof(character_Ben_tiles))
            .withSize(SIZE_32_32)
            .withLocation(charBen_X, charBen_Y)
            .buildPtr();
    character_Erwin = builder
            .withData(character_Erwin_tiles, sizeof(character_Erwin_tiles))
            .withSize(SIZE_32_32)
            .withLocation(charBen_X, charBen_Y)
            .buildPtr();
    character_Stefan = builder
            .withData(character_Stefan_tiles, sizeof(character_Stefan))
            .withSize(SIZE_32_32)
            .withLocation(charBen_X, charBen_Y)
            .buildPtr();
}



