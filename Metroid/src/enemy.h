//
// Created by SDM Technics on 30/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ENEMY_H
#define GBA_SPRITE_ENGINE_PROJECT_ENEMY_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gba/tonc_math.h>

class Enemy {
private:
    std::unique_ptr<Sprite> enemy;
    int lives = 100;

public:
    Enemy(std::unique_ptr<Sprite> sprite1) : enemy(std::move(sprite1)){}
    Sprite *getEnemy() {return enemy.get();}
    void tick(u16 keys);
    int getLives();
    void reduceLives(int value);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENEMY_H
