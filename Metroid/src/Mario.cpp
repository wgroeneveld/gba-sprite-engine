//
// Created by SDM Technics on 2/01/2020.
//

#include "Mario.h"


int Mario::getLives() {
    return lives;
}

void Mario::reduceLives(int value) {
    lives -= value;
}

void Mario::tick(u16 keys) {
    if(goLeft) {
        // getEnemy()->animate();
        if(getMario()->getX() <= 0){
            goLeft = false;
            getMario()->flipHorizontally(false);
            getMario()->setVelocity(+2, 0);
        }
        else {
            getMario()->flipHorizontally(true);
            getMario()->setVelocity(-2, 0);
        }
    }
    else{
        if(getMario()->getX() >= 224){
            goLeft = true;
            getMario()->flipHorizontally(true);
            getMario()->setVelocity(-2, 0);
        }
        else{
            getMario()->flipHorizontally(false);
            getMario()->setVelocity(+2, 0);
        }
    }
}