//
// Created by woute on 9/11/2019.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "Last_stage.h"
#include "ff.h"

std:: vector<Background *> Last_stage::backgrounds(){
    return{};
}
std:: vector<Sprite *> Last_stage::sprites() {
    return {autootje.get()};
}

void Last_stage::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    SpriteBuilder<Sprite> builder;

    autootje = builder
            .withData(lopen_jongenTiles, sizeof(lopen_jongenTiles))
            .withSize(SIZE_16_16)
            .withAnimated(2, 10)
            .withLocation(10, 10)
            .buildPtr();

    TextStream::instance().setText("LOPEN MAAR!", 1,1);
}

void Last_stage::tick(u16 keys) {
    if(keys & KEY_UP){
        if(autootje->getY()>1) {
            autootje->moveTo(autootje->getX(), autootje->getY() - 1);
        }
    }else if(keys & KEY_DOWN){
        if(autootje->getY()<150) {
            autootje->moveTo(autootje->getX(), autootje->getY() + 1);
        }
    }else if(keys & KEY_LEFT){
        if(autootje->getX()>1) {
            autootje->moveTo(autootje->getX() - 1, autootje->getY());
        }
    }else if(keys & KEY_RIGHT){
        if(autootje->getX()<200) {
            autootje->moveTo(autootje->getX() + 1, autootje->getY());
        }
    }
}