//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_SPRITE_BUILDER_H
#define GBA_SPRITE_ENGINE_SPRITE_BUILDER_H

#include "sprite.h"

template<typename T> class SpriteBuilder {
private:
    int imageSize;
    const u32 *imageData;
    int x, y, dx, dy;
    SpriteSize size;

    void reset() {
        imageSize = x = y = dx = dy = 0;
        imageData = nullptr;
        size = SIZE_16_16;
    }
public:
    SpriteBuilder& withData(const u32 imageData[], int imageSize) {
        this->imageData = imageData;
        this->imageSize = imageSize;
        return *this;
    }
    SpriteBuilder& withVelocity(int dx, int dy) {
        this->dx = dx;
        this->dy = dy;
        return *this;
    }
    SpriteBuilder& withLocation(int x, int y) {
        this->x = x;
        this->y = y;
        return *this;
    }
    SpriteBuilder& withSize(const SpriteSize &size) {
        this->size = size;
        return *this;
    }
    T build();
    std::unique_ptr<T> buildPtr();
};

template<typename T> std::unique_ptr<T> SpriteBuilder<T>::buildPtr() {
    auto s = new T(this->imageData, this->imageSize, this->x, this->y, this->size);
    s->setVelocity(this->dx, this->dy);

    reset();
    return std::unique_ptr<T>(s);
}

template<typename T> T SpriteBuilder<T>::build() {
    T s(this->imageData, this->imageSize, this->x, this->y, this->size);
    s.setVelocity(this->dx, this->dy);

    reset();
    return s;
}


#endif //GBA_SPRITE_ENGINE_SPRITE_BUILDER_H
