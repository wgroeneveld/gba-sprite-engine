//
// Created by Wouter Groeneveld on 03/08/18.
//

#include <engine/gba/tonc_memdef.h>
#include "animated_sprite.h"

AnimatedSprite::AnimatedSprite(const void *imageData, int imageSize, int x, int y, SpriteSize size, int frameTileSize, int delay)
        : Sprite(imageData, imageSize, x, y, size), frameTileSize(frameTileSize), frame(0), counter(0), delay(delay) {}

void AnimatedSprite::flipHorizontally(bool flip) {
    if(flip) {
        oam.get()->attr1 |= ATTR1_HFLIP;
    } else {
        oam.get()->attr1 &= FLIP_HORIZONTAL_CLEAR;
    }
}

void AnimatedSprite::flipVertically(bool flip) {
    if(flip) {
        oam.get()->attr1 |= ATTR1_VFLIP;
    } else {
        oam.get()->attr1 &= FLIP_VERTICAL_CLEAR;
    }
}

void AnimatedSprite::update() {
    counter++;
    if(counter > delay) {
        frame += frameTileSize;
        if(frame > frameTileSize) {
            frame = 0;
        }

        updateTileOffsetInOam();
        counter = 0;
    }
}

void AnimatedSprite::updateTileOffsetInOam() {
    oam.get()->attr2 &= OAM_TILE_OFFSET_CLEAR;
    oam.get()->attr2 |= (frame & OAM_TILE_OFFSET_NEW);
}