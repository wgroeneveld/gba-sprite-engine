//
// Created by SDM Technics on 4/01/2020.
//

#include "MarioBullet.h"

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
        if (!isShooting) {
            getBullet()->setVelocity(0, 0);
            getBullet()->moveTo(-60, 0);
            getBullet()->stopAnimating();
        }
    }
    shootLeft = false;
    shootRight = false;

}