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
    else{
        if(isShooting){
            if(getBullet()->getX() <= 0){
                getBullet()->setVelocity(0,0);
                getBullet()->moveTo(-60,0);
                getBullet()->stopAnimating();
                isShooting = false;
            }
            if(getBullet()->getX() >= 232) {
                isShooting = false;
                getBullet()->setVelocity(0, 0);
                getBullet()->moveTo(-60, 0);
                getBullet()->stopAnimating();
            }
        }
    }
    shootLeft = false;
    shootRight = false;
    /*
    if(shootLeft){
        if(getBullet()->getX() <= 0){
            shootLeft = false;
            isShooting =false;
            getBullet()->setVelocity(0,0);
            getBullet()->moveTo(-60,0);
            getBullet()->stopAnimating();
        }
        else {
            isShooting= true;
            getBullet()->animate();
            getBullet()->setVelocity(-2, 0);
        }
    }
    else if(shootRight) {
        if (getBullet()->getX() >= 232) {
            shootRight = false;
            isShooting = false;
            getBullet()->setVelocity(0, 0);
            getBullet()->moveTo(-60, 0);
            getBullet()->stopAnimating();
        } else {
            isShooting = true;
            getBullet()->animate();
            getBullet()->setVelocity(2, 0);
        }
    }*/
}

