//
// Created by SDM Technics on 4/01/2020.
//

#include "MarioBullet.h"

void MarioBullet::shootBulletLeft() {
        shootLeft = true;
}

void MarioBullet::shootBulletRight() {
        shootRight = true;
}

void MarioBullet::setIsShooting(bool value) {
    isShooting = value;
}

void MarioBullet::tick(u16 keys) {

    if(!isShooting){
        cooldown++;
    }

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
          /*  if ((getBullet()->getX() <= 0) || (getBullet()->getX() >= 232)) {
                getBullet()->setVelocity(0, 0);
                getBullet()->moveTo(-60, 0);
                getBullet()->stopAnimating();
                cooldown = 0;
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