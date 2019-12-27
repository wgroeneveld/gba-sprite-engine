//
// Created by woute on 27/12/2019.
// With a lot of inspiration from demo 3
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_AIRBALL_H
#define GBA_SPRITE_ENGINE_PROJECT_AIRBALL_H


#include <libgba-sprite-engine/sprites/sprite.h>
#ifdef CODE_COMPILED_AS_PART_OF_TEST
#include <libgba-sprite-engine/gba/tonc_math_stub.h>
#else
#include <libgba-sprite-engine/gba/tonc_math.h>
#endif
#include <deque>

class AirBall {
private:
    std::unique_ptr<Sprite> sprite;
    std::deque<VECTOR> coords;
    VECTOR dest;

public:
    AirBall(std::unique_ptr<Sprite> sprite) : sprite(std::move(sprite)), dest(VECTOR()) {}

    void tick();
    void setDestination(VECTOR destination);
    bool isOffScreen() { return sprite->isOffScreen(); }
    Sprite* getSprite() { return sprite.get(); }
};




#endif //GBA_SPRITE_ENGINE_PROJECT_AIRBALL_H
