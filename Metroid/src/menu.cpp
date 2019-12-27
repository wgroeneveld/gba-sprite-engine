//
// Created by kyles on 27/12/2019.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "menu.h"

#include "samus_aran.h"
#include "sample_sound.h"

std::vector<Background *> Menu::backgrounds() {
    return {};
}

std::vector<Sprite *> Menu::sprites() {
    return {  metroidBewegen.get() };
}

void Menu::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    SpriteBuilder<Sprite> builder;

    metroidBewegen = builder
            .withData(bewegenTiles, sizeof(bewegenTiles))
            .withSize(SIZE_32_64)
            .withAnimated(10, 3)
            .withLocation(50, 50)
            .buildPtr();

    TextStream::instance().setText("PRESS START", 3, 8);

    engine->getTimer()->start();
    engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);
}

void Menu::tick(u16 keys) {
    TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);

    metroidBewegen->stopAnimating();
    if(pressingAorB && !((keys & KEY_A) || (keys & KEY_B))) {
        engine->getTimer()->toggle();
        pressingAorB = false;
    } else if(keys & KEY_LEFT) {
        metroidBewegen->animate();
        metroidBewegen->flipHorizontally(true);
        metroidBewegen->setVelocity(-2, 0);
    } else if(keys & KEY_RIGHT) {
        metroidBewegen->animate();
        metroidBewegen->flipHorizontally(false);
        metroidBewegen->setVelocity(+2, 0);
    } else if((keys & KEY_A) || (keys & KEY_B)) {
        pressingAorB = true;
    } else {
        metroidBewegen->animateToFrame(0);
        metroidBewegen->setVelocity(0, 0);

    }
}
