//
// Created by Wouter Groeneveld on 09/08/18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BULLET_H
#define GBA_SPRITE_ENGINE_PROJECT_BULLET_H


#include <libgba-sprite-engine/sprites/sprite.h>
#ifdef CODE_COMPILED_AS_PART_OF_TEST
#include <libgba-sprite-engine/gba/tonc_math_stub.h>
#else
#include <libgba-sprite-engine/gba/tonc_math.h>
#endif
#include <deque>

class Bullet {
private:
    std::unique_ptr<Sprite> sprite;
    std::deque<VECTOR> coords;
    VECTOR dest;

public:
    Bullet(std::unique_ptr<Sprite> sprite) : sprite(std::move(sprite)), dest(VECTOR()) {}

    void tick();
    void setDestination(VECTOR destination);
    bool isOffScreen() { return sprite->isOffScreen(); }
    Sprite* getSprite() { return sprite.get(); }
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BULLET_H
