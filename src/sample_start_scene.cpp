//
// Created by Wouter Groeneveld on 02/08/18.
//

#include <engine/sprites/sprite_builder.h>
#include <engine/background/text_stream.h>
#include <engine/gba/tonc_memdef.h>
#include "sample_start_scene.h"
#include "kul.h"

std::vector<Background *> SampleStartScene::backgrounds() {
    return {};
}

std::vector<Sprite *> SampleStartScene::sprites() {
    return { smiley.get(), logo.get() };
}

void SampleStartScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));

    SpriteBuilder<Sprite> builder;

    smiley = builder
            .withData(piskelTiles, sizeof(piskelTiles))
            .withSize(SIZE_16_16)
            .withLocation(10, 10)
            .buildPtr();

    logo = builder
            .withData(kulTiles, sizeof(kulTiles))
            .withSize(SIZE_64_32)
            .withLocation(50, 50)
            .buildPtr();

    TextStream::instance().clear();
    TextStream::instance().setText("PRESS START", 3, 8);
}

void SampleStartScene::tick(u16 keys) {
    if(keys & KEY_START) {
        TextStream::instance() << "entered: starting next scene";
    }
}
