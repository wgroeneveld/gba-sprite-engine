//
// Created by SDM Technics on 28/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_METROID_H
#define GBA_SPRITE_ENGINE_PROJECT_METROID_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gba/tonc_math.h>

class Metroid {
private:
    std::unique_ptr<Sprite> metroid;
    int lives = 100;
    bool goLeft = false;
    bool isCrouching = false;
    bool isJumping = false;
    bool isFalling = false;
    bool canJump = true;

public:
    Metroid(std::unique_ptr<Sprite> sprite1) : metroid(std::move(sprite1)){}
    Sprite *getMetroid() {return metroid.get();}
    void tick(u16 keys);
    void reduceLives(int value);
    int getLives();
    bool getGoLeft(){return goLeft;}
    bool getIsCrouching(){return isCrouching;}
    bool getIsJumping(){return isCrouching;}
};


#endif //GBA_SPRITE_ENGINE_PROJECT_METROID_H
