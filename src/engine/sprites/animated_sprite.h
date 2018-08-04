//
// Created by Wouter Groeneveld on 03/08/18.
//

#ifndef GBA_SPRITE_ENGINE_ANIMATED_SPRITE_H
#define GBA_SPRITE_ENGINE_ANIMATED_SPRITE_H


#include "sprite.h"

#define FLIP_VERTICAL_CLEAR 0xdfff
#define FLIP_HORIZONTAL_CLEAR 0xefff
#define OAM_TILE_OFFSET_CLEAR 0xfc00
#define OAM_TILE_OFFSET_NEW 0x03ff

class AnimatedSprite : public Sprite {
private:
    int delay;
    int frame, frameTileSize;
    int counter;

    void updateTileOffsetInOam();

public:
    AnimatedSprite(const void *imageData, int imageSize, int x, int y, SpriteSize size, int frameTileSize, int delay);

    void flipVertically(bool flip);
    void flipHorizontally(bool flip);

    void update();
};


#endif //GBA_SPRITE_ENGINE_ANIMATED_SPRITE_H
