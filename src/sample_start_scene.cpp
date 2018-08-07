//
// Created by Wouter Groeneveld on 02/08/18.
//

#include <engine/sprites/sprite_builder.h>
#include <engine/background/text_stream.h>
#include <engine/gba/tonc_memdef.h>
#include <engine/gba_engine.h>
#include <engine/effects/fade_out_scene.h>
#include "sample_start_scene.h"
#include "flying_stuff_scene.h"

#include "lama.h"
#include "sample_sound.h"

std::vector<Background *> SampleStartScene::backgrounds() {
    return {};
}

std::vector<Sprite *> SampleStartScene::sprites() {
    return {  animation.get() };
}

void SampleStartScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(lama_palette, sizeof(lama_palette)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    SpriteBuilder<Sprite> builder;

    animation = builder
            .withData(lama_data, sizeof(lama_data))
            .withSize(SIZE_32_32)
            .withAnimated(6, 3)
            .withLocation(50, 50)
            .buildPtr();

    TextStream::instance().setText("PRESS START", 3, 8);
    engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);
}

void SampleStartScene::tick(u16 keys) {
    if(keys & KEY_START) {
        if(!engine->isTransitioning()) {
            engine->enqueueSound(zelda_secret_16K_mono, zelda_secret_16K_mono_bytes);

            TextStream::instance() << "entered: starting next scene";

            engine->transitionIntoScene(new FlyingStuffScene(engine), new FadeOutScene(2));
        }
    } else if(keys & KEY_LEFT) {
        animation->flipHorizontally(true);
    } else if(keys & KEY_RIGHT) {
        animation->flipHorizontally(false);
    } else if(keys & KEY_UP) {
        animation->flipVertically(true);
    } else if(keys & KEY_DOWN) {
        animation->flipVertically(false);
    }
}
