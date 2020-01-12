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
    getMario()->stopAnimating();
    if(lives <= 0){
       getMario()->setVelocity(0,0);
       getMario()->moveTo(-20,20);
    }
    else{
        if(goLeft && canGoLeft) {
            getMario()->makeAnimated(3,5);
            getMario()->flipHorizontally(true);
            getMario()->setVelocity(-1, 0);
        }
        else if(goLeft && !canGoLeft){
            goLeft = false;
            getMario()->makeAnimated(3,5);
            getMario()->flipHorizontally(false);
            getMario()->setVelocity(+1, 0);
        }
        else{
            if(canGoRight) {
                getMario()->makeAnimated(3, 5);
                getMario()->flipHorizontally(false);
                getMario()->setVelocity(+1, 0);
                goLeft = false;
            }
            else{
                goLeft = true;
            }
        }
    }

}

void Mario::setCanGoLeft(bool canGoLeft) {
    Mario::canGoLeft = canGoLeft;
}

void Mario::setCanGoRight(bool canGoRight) {
    Mario::canGoRight = canGoRight;
}

void Mario::setGoLeft(bool goLeft) {
    Mario::goLeft = goLeft;
}
