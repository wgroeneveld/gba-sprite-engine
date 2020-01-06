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
 //   for(int i = 0; i < 2000; i++){}
    getMario()->stopAnimating();
    if(goLeft && canGoLeft) {
        // getEnemy()->animate();
        if(getMario()->getX() <= 0){
            goLeft = false;
            getMario()->makeAnimated(3,5);
            getMario()->flipHorizontally(false);
            getMario()->setVelocity(+1, 0);
        }
        else {
            getMario()->makeAnimated(3,5);
            getMario()->flipHorizontally(true);
            getMario()->setVelocity(-1, 0);
        }
    }
    else{
        goLeft = false;
        if(canGoRight) {
            if (getMario()->getX() >= 224) {
                goLeft = true;
                getMario()->makeAnimated(3, 5);
                getMario()->flipHorizontally(true);
                getMario()->setVelocity(-1, 0);
            } else {
                getMario()->makeAnimated(3, 5);
                getMario()->flipHorizontally(false);
                getMario()->setVelocity(+1, 0);
            }
        }
    }
}

bool Mario::isCanGoLeft() const {
    return canGoLeft;
}

void Mario::setCanGoLeft(bool canGoLeft) {
    Mario::canGoLeft = canGoLeft;
}

bool Mario::isCanGoRight() const {
    return canGoRight;
}

void Mario::setCanGoRight(bool canGoRight) {
    Mario::canGoRight = canGoRight;
}
