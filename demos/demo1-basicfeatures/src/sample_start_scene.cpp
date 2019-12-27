//
// Created by Wouter Groeneveld on 02/08/18.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "sample_start_scene.h"
#include "flying_stuff_scene.h"

#include "lama.h"
#include "ff.h"
#include "megaman.h"
#include "metroid.h"
#include "sample_sound.h"

std::vector<Background *> SampleStartScene::backgrounds() {
    return {};
}

std::vector<Sprite *> SampleStartScene::sprites() {
    return {  /*animation.get(),*/ finalFantasyGuy.get(), megamanMoving.get(), metroidBewegen.get() };
}

void SampleStartScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    SpriteBuilder<Sprite> builder;
    /*
    animation = builder
            .withData(lamaTiles, sizeof(lamaTiles))
            .withSize(SIZE_32_32)
            .withAnimated(6, 3)
            .withLocation(50, 50)
            .buildPtr();
    */
    finalFantasyGuy = builder
            .withData(lopen_jongenTiles, sizeof(lopen_jongenTiles))
            .withSize(SIZE_16_16)
            .withAnimated(2, 10)
            .withLocation(10, 10)
            .buildPtr();

    megamanMoving = builder
            .withData(megamanTiles, sizeof(megamanTiles))
            .withSize(SIZE_32_32)
            .withAnimated(3, 5)
            .withLocation(90, 50)
            .buildPtr();

    metroidBewegen = builder
            .withData(metroid_bewegenTiles, sizeof(metroid_bewegenTiles))
            .withSize(SIZE_32_64)
            .withAnimated(10, 3)
            .withLocation(50, 50)
            .buildPtr();

    TextStream::instance().setText("PRESS START", 3, 8);

    engine->getTimer()->start();
    engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);
}

void SampleStartScene::tick(u16 keys) {
    TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);

    metroidBewegen->stopAnimating();
    if(pressingAorB && !((keys & KEY_A) || (keys & KEY_B))) {
        engine->getTimer()->toggle();
        pressingAorB = false;
    }

    if(keys & KEY_START) {
        if(!engine->isTransitioning()) {
            engine->enqueueSound(zelda_secret_16K_mono, zelda_secret_16K_mono_bytes);

            TextStream::instance() << "entered: starting next scene";

            engine->transitionIntoScene(new FlyingStuffScene(engine), new FadeOutScene(2));
        }
    } else if(keys & KEY_LEFT) {
        metroidBewegen->animate();
        metroidBewegen->flipHorizontally(true);
        metroidBewegen->setVelocity(-2, 0);
    } else if(keys & KEY_RIGHT) {
        metroidBewegen->animate();
        metroidBewegen->flipHorizontally(false);
        metroidBewegen->setVelocity(+2, 0);
    } else if(keys & KEY_UP) {
        megamanMoving->flipVertically(true);
    } else if(keys & KEY_DOWN) {
        megamanMoving->flipVertically(false);
    } else if((keys & KEY_A) || (keys & KEY_B)) {
        pressingAorB = true;
    } else {
        metroidBewegen->animateToFrame(0);
        metroidBewegen->setVelocity(0, 0);

    }
}
