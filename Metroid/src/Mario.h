//
// Created by SDM Technics on 2/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MARIO_H
#define GBA_SPRITE_ENGINE_PROJECT_MARIO_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gba/tonc_math.h>

class Mario {
private:
    std::unique_ptr<Sprite> enemy;
    int lives = 100;
    bool goLeft = true;
public:
    Mario(std::unique_ptr<Sprite> sprite1) : enemy(std::move(sprite1)){}
    Sprite *getMario() {return enemy.get();}
    void tick(u16 keys);
    int getLives();
    void reduceLives(int value);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MARIO_H
