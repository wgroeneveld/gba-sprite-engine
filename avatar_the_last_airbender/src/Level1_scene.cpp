//
// Created by woute on 9/12/2019.
//

#include "Level1_scene.h"
#include "aang_jump (1).h"
#include "aang_jump2.h"
#include "white_background.h"

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
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(white_backgroundPal, sizeof(white_backgroundPal)));

    background = std:: unique_ptr<Background>(new Background(0, white_backgroundTiles, sizeof(white_backgroundTiles), white_backgroundMap, sizeof(white_backgroundMap)));
    background.get()->useMapScreenBlock(24);

    SpriteBuilder<Sprite> builder;

    aang = builder
            .withData(aang_jump2_Tiles, sizeof(aang_jump2_Tiles))
            .withSize(SIZE_32_64)
            .withLocation(50, 50)
            .buildPtr();

    TextStream::instance().setText("PRESS UP TO JUMP", 3, 8);
}



void Level1_scene::tick(u16 keys) {
    TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);

    if(pressingAorB && !((keys & KEY_A) || (keys & KEY_B))) {
        engine->getTimer()->toggle();
        pressingAorB = false;
    }

    if((keys & KEY_LEFT)) {
        aang->moveTo(aang->getX() - 2,aang->getY());
    } else if(keys & KEY_RIGHT) {
        aang->moveTo(aang->getX() + 2,aang->getY());
    } else if(keys & KEY_UP) {
        aang->makeAnimated(1,5,20);
    } else if(keys & KEY_DOWN) {
        aang->flipVertically(false);
    } else if((keys & KEY_A) || (keys & KEY_B)) {
        pressingAorB = true;
    }
}
