//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include "flying_stuff_scene.h"
#include "kul.h"

std::vector<Sprite *> FlyingStuffScene::sprites() {
    return {
        smiley.get(), kul.get(), kulFlying.get(), player.get()
    };
}

std::vector<Background *> FlyingStuffScene::backgrounds() {
    return {
        bg.get()
    };
}

void FlyingStuffScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bg_palette, sizeof(bg_palette)));

    SpriteBuilder<Sprite> builder;
    SpriteBuilder<AffineSprite> affineBuilder;

    smiley = builder
            .withData(piskelTiles, sizeof(piskelTiles))
            .withSize(SIZE_16_16)
            .withLocation(10, 10)
            .buildPtr();

    kul = builder
            .withData(kulTiles, sizeof(kulTiles))
            .withSize(SIZE_64_32)
            .withLocation(30, 30)
            .buildPtr();

    kulFlying = affineBuilder
            .withData(kulTiles, sizeof(kulTiles))
            .withSize(SIZE_64_32)
            .withLocation(100, 50)
            .withVelocity(1, 1)
            .buildPtr();

    player = affineBuilder
            .withData(piskel2Tiles, sizeof(piskel2Tiles))
            .withSize(SIZE_16_16)
            .withLocation(150, 60)
            .buildPtr();

    TextStream::instance() << "level 1 ofwa" << "ziet da af";

    bg = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    bg.get()->useMapScreenBlock(16);
}

void FlyingStuffScene::tick(u16 keys) {
    scrollX += 1;

    rotation += rotationDiff;
    kulFlying.get()->rotate(rotation);
    player.get()->rotate(rotation);
    bg.get()->scroll(scrollX, scrollY);
}
