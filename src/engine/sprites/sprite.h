//
// Created by Wouter Groeneveld on 26/07/18.
//

#ifndef GBA_SPRITE_ENGINE_SPRITE_H
#define GBA_SPRITE_ENGINE_SPRITE_H

#include <engine/gba/tonc_types.h>
#include <memory>

#define COLOR_MODE_16 0
#define COLOR_MODE_256 1
#define GFX_MODE 0
#define MOSAIC_MODE 0
#define AFFINE_FLAG_NONE_SET_YET 0
#define HORIZONTAL_FLIP_FLAG 0
#define VERTICAL_FLIP_FLAG 0

enum SpriteSize {
    SIZE_8_8,
    SIZE_16_16,
    SIZE_32_32,
    SIZE_64_64,
    SIZE_16_8,
    SIZE_32_8,
    SIZE_32_16,
    SIZE_64_32,
    SIZE_8_16,
    SIZE_8_32,
    SIZE_16_32,
    SIZE_32_64
};

class SpriteManager;

class Sprite {
protected:
    const void *data;
    int x, y, priority, dx, dy;
    int w, h, size_bits, shape_bits;
    int imageSize;

    std::unique_ptr<OBJ_ATTR> oam;

    virtual void syncOam();
    virtual void buildOam(int tileIndex);
    void setAttributesBasedOnSize(SpriteSize size);

public:
    Sprite(const void *imageData, int imageSize, int x, int y, SpriteSize size);

    void setVelocity(int dx, int dy) {
        this->dx = dx;
        this->dy = dy;
    }
    void move();
    void moveTo(int x, int y);
    bool collidesWith(const Sprite &other);

    int getX() { return x; }
    int getHeight() { return h; }
    int getWidth() { return w; }
    int getY() { return y; }

    friend class SpriteManager;
};


#endif //GBA_SPRITE_ENGINE_SPRITE_H
