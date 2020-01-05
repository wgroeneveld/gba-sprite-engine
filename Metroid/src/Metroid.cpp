//
// Created by SDM Technics on 28/12/2019.
//

#include "Metroid.h"
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/gba/tonc_math.h>

int Metroid::getLives() {
    return lives;
}

void Metroid::reduceLives(int value) {
    lives -= value;
}

void Metroid::setCanGoRight(bool value){
    canGoRight = value;
}

void Metroid::setCanGoLeft(bool value){
    canGoLeft = value;
}

void Metroid::setIsFalling(bool value) {
    isFalling = value;
}

void Metroid::setIsJumping(bool value) {
    isJumping = value;
}

void Metroid::tick(u16 keys) {


    if(isJumping){
        if(goLeft){
            getMetroid()->setVelocity(-1, -1);
        }
        else{
            getMetroid()->setVelocity(+1, -1);
        }
    }

    if(isFalling){
        if(getMetroid()->getY() == 80){
            isFalling = false;
            canJump = true;
        }
        else {
            if(goLeft){
                getMetroid()->setVelocity(-1, 1);
            }
            else{
                getMetroid()->setVelocity(+1, 1);
            }
        }
    }


    if(!canGoRight){
        getMetroid()->setDx(0);
    }
    else if(!canGoLeft){
        getMetroid()->setDx(0);
    }
    else if(!canGoUp){
        if(isJumping){
            isJumping = false;
            isFalling = true;
        }
    }
    else if(!canGoDown){
        getMetroid()->setDy(0);
        isFalling = false;
        canJump = true;
    }
    else if(isJumping){
        if(keys & KEY_LEFT){
            getMetroid()->setDx(-1);
        }
        if(keys & KEY_RIGHT){
            getMetroid()->setDx(1);
        }
    }
    else if(isFalling){
        getMetroid()->setDy(-1);
        if(keys & KEY_LEFT){
            getMetroid()->setDx(-1);
        }
        if(keys & KEY_RIGHT){
            getMetroid()->setDx(1);
        }
    }

    if(keys & KEY_LEFT && canGoLeft) {
        if(canJump){
            goLeft =true;
            isCrouching = false;
            if(keys & KEY_B){
                isJumping = true;
                canJump = false;
                getMetroid()->animateToFrame(5);
                getMetroid()->flipHorizontally(true);
                getMetroid()->stopAnimating();
            }
            else {
                getMetroid()->makeAnimated(6, 5);
                getMetroid()->flipHorizontally(true);
                getMetroid()->setVelocity(-1, 0);
            }
        }

    } else if(keys & KEY_RIGHT && canGoRight) {
        if(canJump){
            goLeft = false;
            isCrouching = false;
            if(keys & KEY_B) {
                isJumping = true;
                canJump = false;
                getMetroid()->animateToFrame(5);
                getMetroid()->flipHorizontally(false);
                getMetroid()->stopAnimating();
            }
            else{
                getMetroid()->makeAnimated(6,5);
                getMetroid()->flipHorizontally(false);
                getMetroid()->setVelocity(+1, 0);
            }

        }
    }
    else if(keys & KEY_DOWN){
        if(canJump) {
            isCrouching = true;
            getMetroid()->animateToFrame(10);
            getMetroid()->setVelocity(0, 0);
            if (goLeft) {
                getMetroid()->flipHorizontally(true);
            } else {
                getMetroid()->flipHorizontally(false);
            }
        }
    }
    else {
        if(canJump) {
            getMetroid()->animateToFrame(7);
            getMetroid()->stopAnimating();
            getMetroid()->setVelocity(0, 0);
            isCrouching = false;
        }
    }




}

bool Metroid::isCanGoUp() const {
    return canGoUp;
}

void Metroid::setCanGoUp(bool canGoUp) {
    Metroid::canGoUp = canGoUp;
}

bool Metroid::isCanGoDown() const {
    return canGoDown;
}

void Metroid::setCanGoDown(bool canGoDown) {
    Metroid::canGoDown = canGoDown;
}
