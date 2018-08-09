//
// Created by Wouter Groeneveld on 09/08/18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BULLET_H
#define GBA_SPRITE_ENGINE_PROJECT_BULLET_H


#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gba/tonc_math.h>

class Bullet {
private:
    std::unique_ptr<Sprite> sprite;
    VECTOR dest;
    VECTOR vel;
    VECTOR direction;

public:
    Bullet(std::unique_ptr<Sprite> sprite) : sprite(std::move(sprite)), dest(VECTOR()) {}

    void tick();
    void setDestination(VECTOR vec);
    bool isOffScreen() { return sprite->isOffScreen(); }
    Sprite* getSprite() { return sprite.get(); }
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BULLET_H
