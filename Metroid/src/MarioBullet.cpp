//
// Created by SDM Technics on 4/01/2020.
//

#include "MarioBullet.h"

void MarioBullet::shootBulletLeft() {
    if(!isShooting){
        shootLeft = true;
    }
}

void MarioBullet::shootBulletRight() {
    if(!isShooting){
        shootRight = true;
    }
}

void MarioBullet::setIsShooting(bool value) {
    isShooting = value;
}

void MarioBullet::tick(u16 keys) {
    // getBullet()->stopAnimating();

    if(!isShooting){

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
            if ((getBullet()->getX() <= 0) || (getBullet()->getX() >= 232)) {
                getBullet()->setVelocity(0, 0);
                getBullet()->moveTo(-60, 0);
                getBullet()->stopAnimating();
                isShooting = false;
            }
        }
        else{
            getBullet()->setVelocity(0, 0);
            getBullet()->moveTo(-60, 0);
            getBullet()->stopAnimating();
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