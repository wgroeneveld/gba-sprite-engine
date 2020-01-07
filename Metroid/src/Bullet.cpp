//
// Created by SDM Technics on 30/12/2019.
//

#include "Bullet.h"

void Bullet::shootBulletLeft() {
    if(!isShooting){
       shootLeft = true;
    }
}

void Bullet::shootBulletRight() {
    if(!isShooting){
        shootRight = true;
    }
}

void Bullet::setIsShooting(bool value) {
    isShooting = value;
}

void Bullet::tick(u16 keys) {
   // getBullet()->stopAnimating();
    if(shootLeft){
            isShooting= true;
            getBullet()->animate();
            getBullet()->setVelocity(-3, 0);
    }
    else if(shootRight) {
            isShooting = true;
            getBullet()->animate();
            getBullet()->setVelocity(3, 0);
    }
    else {
        if (isShooting) {
           // if(!canGoLeft && getBullet()->getDx()<0) isShooting = false;
            if(!canGoRight) isShooting = false;
           /*  if(!canGoLeft || !canGoRight){
                getBullet()->setVelocity(0, 0);
                getBullet()->moveTo(-60, 0);
                getBullet()->stopAnimating();
                isShooting = false;
            }
        /*    if ((getBullet()->getX() <= 0) || (getBullet()->getX() >= 232)) {
                getBullet()->setVelocity(0, 0);
                getBullet()->moveTo(-60, 0);
                getBullet()->stopAnimating();
                isShooting = false;
            }*/
        }
        else{
            getBullet()->setVelocity(0, 0);
            getBullet()->moveTo(-60, 0);
            getBullet()->stopAnimating();
        }
    }
    shootLeft = false;
    shootRight = false;
}

