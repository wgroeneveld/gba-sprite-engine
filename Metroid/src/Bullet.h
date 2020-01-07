//
// Created by SDM Technics on 30/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BULLET_H
#define GBA_SPRITE_ENGINE_PROJECT_BULLET_H


#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gba/tonc_math.h>

class Bullet {
private:
    std::unique_ptr<Sprite> bullet;
    bool shootLeft = false;
    bool shootRight = false;
    bool isShooting = false;
    bool canGoLeft = true;
    bool canGoRight = true;

public:
    Bullet(std::unique_ptr<Sprite> sprite1) : bullet(std::move(sprite1)){}
    Sprite *getBullet() {return bullet.get();}
    void tick(u16 keys);
    void shootBulletLeft();
    void shootBulletRight();
    bool getIsShooting(){return isShooting;}
    void setIsShooting(bool value);
    void setCanGoLeft(bool value){canGoLeft = value;}
    void setCanGoRight(bool value){canGoRight = value;}
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BULLET_H
