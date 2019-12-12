//
// Created by woute on 9/12/2019.
//

#include "Level1_scene.h"
#include "aang_jump (1).h"
#include "aang_jump2.h"
#include "background_water.h"
#include "background_earth_tilemap.h"
#include "background_earth_data.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

std::vector<Background *> Level1_scene::backgrounds() {
    return { background.get()};
}

std::vector<Sprite *> Level1_scene::sprites() {
    return {  aang.get()};
}

void Level1_scene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(aang_jump2_Pal, sizeof(aang_jump2_Pal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(background_earth_data2Pal, sizeof(background_earth_data2Pal)));

    background = std:: unique_ptr<Background>(new Background(0, background_earth_data2Tiles, sizeof(background_earth_data2Tiles),background_earth_tilemap , sizeof(background_earth_tilemap)));
    //background.get()->useMapScreenBlock(64);

    SpriteBuilder<Sprite> builder;

    aang = builder
            .withData(aang_jump2_Tiles, sizeof(aang_jump2_Tiles))
            .withSize(SIZE_32_64)
            .withLocation(50, 70)
            .buildPtr();
}

int counter = 0;
bool jump = false;
int frame = 1;

void Level1_scene::tick(u16 keys) {
    if((keys & KEY_LEFT)) {
        if(aang->getX()-2>0) {
            aang->moveTo(aang->getX() - 2, aang->getY());
        }
    } else if(keys & KEY_RIGHT) {
        if(aang->getX()+2<240)
        aang->moveTo(aang->getX() + 2,aang->getY());
    } else if(keys & KEY_UP) {
        if(aang->getY()-1>65)
            aang->moveTo(aang->getX(),aang->getY()-1);
    } else if(keys & KEY_DOWN) {
        if(aang->getY()+1<95)
            aang->moveTo(aang->getX(),aang->getY()+1);
    } else if(keys & KEY_A) {
        if (jump == false) jump = true;
    }

    counter++;

    if(jump && counter > 10) {
        counter = 0;
        aang->animateToFrame(frame);
        if(frame == 5) {
            jump = false;
            frame = 0;
            aang->animateToFrame(frame);
        }
        else {
            frame++;
        }
    }
}
