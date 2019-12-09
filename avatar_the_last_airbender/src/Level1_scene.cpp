//
// Created by woute on 28/11/2019.
//

#include "Level1_scene.h"
#include "aang_jump (1).h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

std::vector<Background *> Level1_scene::backgrounds() {
    return {};
}

std::vector<Sprite *> Level1_scene::sprites() {
    return {  aang.get()};
}

void Level1_scene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(aang_jump__1_Pal, sizeof(aang_jump__1_Pal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    SpriteBuilder<Sprite> builder;

    aang = builder
            .withData(aang_jump__1_Tiles, sizeof(aang_jump__1_Tiles))
            .withSize(SIZE_32_32)
            .withAnimated(6, 20)
            .withLocation(50, 50)
            .buildPtr();

    TextStream::instance().setText("PRESS ENTER TO JUMP", 3, 8);
}



void Level1_scene::tick(u16 keys) {
    TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);

    if(pressingAorB && !((keys & KEY_A) || (keys & KEY_B))) {
        engine->getTimer()->toggle();
        pressingAorB = false;
    }

    if((keys & KEY_LEFT)) {
        aang->flipHorizontally(true);
    } else if(keys & KEY_RIGHT) {
        aang->flipHorizontally(false);
    } else if(keys & KEY_UP) {
        aang->flipVertically(true);
    } else if(keys & KEY_DOWN) {
        aang->flipVertically(false);
    } else if((keys & KEY_A) || (keys & KEY_B)) {
        pressingAorB = true;
    }
}