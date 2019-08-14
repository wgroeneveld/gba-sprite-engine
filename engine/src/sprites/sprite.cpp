//
// Created by Wouter Groeneveld on 26/07/18.
//

#include <cstdlib>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gba_engine.h>

Sprite::Sprite(const Sprite &other) : Sprite(nullptr, 0, other.x, other.y, other.spriteSize) {
    tileIndex = other.tileIndex;
}

Sprite::Sprite(const void *imageData, int imageSize, int x, int y, SpriteSize size)
        : x(x), y(y), data(imageData), imageSize(imageSize), spriteSize(size), priority(0),
          animationDelay(0), numberOfFrames(0), beginFrame(0), currentFrame(0), animationCounter(0) {
    setAttributesBasedOnSize(size);
}

void Sprite::moveTo(VECTOR location) {
    moveTo(location.x, location.y);
}

void Sprite::moveTo(int x, int y) {
    this->x = x;
    this->y = y;
    if(oam) {
        syncOam();
    }
}

bool Sprite::isOffScreen() {
    return x < 0 || x > GBA_SCREEN_WIDTH || y < 0 || y > GBA_SCREEN_HEIGHT;
}

void Sprite::flipHorizontally(bool flip) {
    if(flip) {
        oam->attr1 |= ATTR1_HFLIP;
    } else {
        oam->attr1 &= FLIP_HORIZONTAL_CLEAR;
    }
}

void Sprite::flipVertically(bool flip) {
    if(flip) {
        oam->attr1 |= ATTR1_VFLIP;
    } else {
        oam->attr1 &= FLIP_VERTICAL_CLEAR;
    }
}

void Sprite::syncVelocity() {
    oam->attr0 = (oam->attr0 &  ~ATTR0_Y_MASK) | (y & ATTR0_Y_MASK);
    oam->attr1 = (oam->attr1 & ~ATTR1_X_MASK) | (x & ATTR1_X_MASK);
}

void Sprite::syncAnimation() {
    int newTileIndex = this->tileIndex + (currentFrame * (this->animation_offset * 2));
    oam->attr2 &= OAM_TILE_OFFSET_CLEAR;
    oam->attr2 |= (newTileIndex & OAM_TILE_OFFSET_NEW);
}

void Sprite::syncOam() {
    syncVelocity();
    syncAnimation();
}

void Sprite::updateVelocity() {
    if(dx == 0 && dy == 0) return;

    this->x += this->dx;
    this->y += this->dy;

    if(stayWithinBounds) {
        if(this->x < 0) this->x = 0;
        if(this->y < 0) this->y = 0;
        if(this->x > (GBA_SCREEN_WIDTH - this->w)) this->x = GBA_SCREEN_WIDTH - this->w;
        if(this->y > (GBA_SCREEN_HEIGHT - this->h)) this->y = GBA_SCREEN_HEIGHT - this->h;
    }
}

void Sprite::updateAnimation() {
    if(!animating) return;

    animationCounter++;
    if(animationCounter > animationDelay) {
        currentFrame++;
        if(currentFrame > (numberOfFrames - 1) + beginFrame) {
            currentFrame = beginFrame;
        }
        if(currentFrame < beginFrame) {
            currentFrame = beginFrame;
        }

        animationCounter = 0;
    }
}

void Sprite::update() {
    updateVelocity();
    updateAnimation();
    syncOam();
}

void Sprite::setAttributesBasedOnSize(SpriteSize size) {
    switch (size) {
        case SIZE_8_8:   size_bits = 0; shape_bits = 0; w = 8; h = 8; animation_offset = 1; break;
        case SIZE_16_16: size_bits = 1; shape_bits = 0; w = 16; h = 16; animation_offset = 4; break;
        case SIZE_32_32: size_bits = 2; shape_bits = 0; w = 32; h = 32; animation_offset = 16; break;
        case SIZE_64_64: size_bits = 3; shape_bits = 0; w = 64; h = 64; animation_offset = 64; break;
        case SIZE_16_8:  size_bits = 0; shape_bits = 1; w = 16; h = 8; animation_offset = 2; break;
        case SIZE_32_8:  size_bits = 1; shape_bits = 1; w = 32; h = 8; animation_offset = 4; break;
        case SIZE_32_16: size_bits = 2; shape_bits = 1; w = 32; h = 16; animation_offset = 8; break;
        case SIZE_64_32: size_bits = 3; shape_bits = 1; w = 64; h = 32; animation_offset = 32; break;
        case SIZE_8_16:  size_bits = 0; shape_bits = 2; w = 8; h = 16; animation_offset = 2; break;
        case SIZE_8_32:  size_bits = 1; shape_bits = 2; w = 8; h = 32; animation_offset = 4; break;
        case SIZE_16_32: size_bits = 2; shape_bits = 2; w = 16; h = 32; animation_offset = 8; break;
        case SIZE_32_64: size_bits = 3; shape_bits = 2; w = 32; h = 64; animation_offset = 32; break;
    }
}

bool Sprite::collidesWith(Sprite &s2) {
    const Sprite &s1 = *this;

    if(s1.x < s2.x + s2.w &&
            s1.x + s1.w > s2.x &&
            s1.y < s2.y + s2.h &&
            s1.h + s1.y > s2.y) {
        return true;
    }
    return false;
}


void Sprite::buildOam(int tileIndex) {
    this->tileIndex = tileIndex;

    if(!oam) {
        this->oam = std::unique_ptr<OBJ_ATTR>(new OBJ_ATTR());

        this->oam->attr0 = ATTR0_Y(this->y & 0x00FF) |
                ATTR0_MODE(0) |
                (GFX_MODE << 10) |
                (MOSAIC_MODE << 12) |
                (COLOR_MODE_256 << 13) |
                (this->shape_bits << 14);
        this->oam->attr1 = (this->x & 0x01FF) |
                (AFFINE_FLAG_NONE_SET_YET << 9) |
                (HORIZONTAL_FLIP_FLAG << 12) |
                (VERTICAL_FLIP_FLAG << 13) |
                (this->size_bits << 14);
    }

    this->oam->attr2 = ATTR2_ID(tileIndex) |
            ATTR2_PRIO(priority) |
            ATTR2_PALBANK(0);
}
