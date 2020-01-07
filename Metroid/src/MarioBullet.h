//
// Created by SDM Technics on 4/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MARIOBULLET_H
#define GBA_SPRITE_ENGINE_PROJECT_MARIOBULLET_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gba/tonc_math.h>

class MarioBullet {
private:
    std::unique_ptr<Sprite> bullet;
    bool canGoLeft = true;
    bool shootLeft = false;
    bool shootRight = false;
    bool isShooting = false;
    int cooldown = 0;

public:
    MarioBullet(std::unique_ptr<Sprite> sprite1) : bullet(std::move(sprite1)){}
    Sprite *getBullet() {return bullet.get();}
    void tick(u16 keys);
    void shootBulletLeft();
    void shootBulletRight();
    bool getIsShooting(){return isShooting;}
    void setIsShooting(bool value);
    int getCooldown(){return cooldown;}
    void setCooldown(int value){cooldown = value;}


};

#endif //GBA_SPRITE_ENGINE_PROJECT_MARIOBULLET_H
