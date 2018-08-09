//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_SPRITE_BUILDER_H
#define GBA_SPRITE_ENGINE_SPRITE_BUILDER_H

#include "sprite.h"

template<typename T> class SpriteBuilder {
private:
    u32 imageSize;
    bool stayWithinBounds;
    const void *imageData;
    u32 x, y, dx, dy;
    u32 numberOfFrames, animationDelay;
    SpriteSize size;

    void setProperties(T* sprite);
    void reset() {
        imageSize = x = y = dx = dy = numberOfFrames = animationDelay = 0;
        imageData = nullptr;
        size = SIZE_16_16;
    }
public:
    SpriteBuilder() {
        reset();
    }
    SpriteBuilder& withinBounds() {
        stayWithinBounds = true;
        return *this;
    }
    SpriteBuilder& withData(const void* imageData, int imageSize) {
        this->imageData = imageData;
        this->imageSize = imageSize;
        return *this;
    }
    SpriteBuilder& withVelocity(int dx, int dy) {
        this->dx = dx;
        this->dy = dy;
        return *this;
    }

    SpriteBuilder& withLocation(u32 x, u32 y) {
        this->x = x;
        this->y = y;
        return *this;
    }
    SpriteBuilder& withSize(const SpriteSize &size) {
        this->size = size;
        return *this;
    }
    SpriteBuilder& withAnimated(int numberOfFrames, int delay) {
        this->numberOfFrames = numberOfFrames;
        this->animationDelay = delay;
        return *this;
    }
    T build();
    std::unique_ptr<T> buildPtr();
    std::unique_ptr<T> buildWithDataOf(const Sprite &other);
};

template<typename T> std::unique_ptr<T> SpriteBuilder<T>::buildWithDataOf(const Sprite &other) {
    auto s = new T(other);
    s->moveTo(this->x, this->y);
    setProperties(s);

    reset();
    return std::unique_ptr<T>(s);
}

template<typename T> void SpriteBuilder<T>::setProperties(T* s) {
    s->setVelocity(this->dx, this->dy);
    if(this->numberOfFrames > 0) {
        s->makeAnimated(this->numberOfFrames, this->animationDelay);
    }
    s->setStayWithinBounds(stayWithinBounds);

}

template<typename T> std::unique_ptr<T> SpriteBuilder<T>::buildPtr() {
    auto s = new T(this->imageData, this->imageSize, this->x, this->y, this->size);
    setProperties(s);

    reset();
    return std::unique_ptr<T>(s);
}

template<typename T> T SpriteBuilder<T>::build() {
    T s(this->imageData, this->imageSize, this->x, this->y, this->size);
    setProperties(&s);

    reset();
    return s;
}


#endif //GBA_SPRITE_ENGINE_SPRITE_BUILDER_H
