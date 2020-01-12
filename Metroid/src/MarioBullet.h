//
// Created by SDM Technics on 4/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MARIOBULLET_H
#define GBA_SPRITE_ENGINE_PROJECT_MARIOBULLET_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gba/tonc_math.h>
#include "Bullet.h"

class MarioBullet : public Bullet {
private:
    int cooldown = 0;


public:
    MarioBullet(std::unique_ptr<Sprite> sprite1) : Bullet(std::move(sprite1)){}
    void tick(u16 keys) override;
    int getCooldown(){return cooldown;}
    void setCooldown(int value){cooldown = value;}


};

#endif //GBA_SPRITE_ENGINE_PROJECT_MARIOBULLET_H
