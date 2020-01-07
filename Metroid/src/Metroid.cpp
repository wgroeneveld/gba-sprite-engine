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

/*
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
    else if(!canGoDown && !isJumping){
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
    else if(canGoDown){
        isFalling = true;
        canJump = false;
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
    else if(keys & KEY_B){
        isJumping = true;
        canJump = false;

        if(goLeft){
            getMetroid()->flipHorizontally(true);
        } else{
            getMetroid()->flipHorizontally(false);
        }
        getMetroid()->animateToFrame(5);
        getMetroid()->setVelocity(0,1);
        getMetroid()->stopAnimating();
    }
    else {
        if(canJump) {
            getMetroid()->animateToFrame(7);
            getMetroid()->stopAnimating();
            getMetroid()->setVelocity(0, 0);
            isCrouching = false;
        }
    }




}*/

if(isJumping){
    if(!canGoUp){
        //getMetroid()->setDy(1);
        isJumping = false;
        isFalling = true;
    }
    else if (!canGoLeft){
        getMetroid()->setDx(0);
    }
    else if (!canGoRight){
        getMetroid()->setDx(0);
    }
    else if (canGoLeft && (keys & KEY_LEFT)){
        getMetroid()->setDx(-1);
        getMetroid()->flipHorizontally(true);
    }
    else if (canGoRight && (keys & KEY_RIGHT)){
        getMetroid()->setDx(1);
        getMetroid()->flipHorizontally(false);
    } else{
        getMetroid()->setDx(0);
    }
}

else if (isFalling){
    getMetroid()->setDy(2);
    if(!canGoDown){
        isFalling = false;
        getMetroid()->setDy(0);
    }
    else if (!canGoLeft){
        getMetroid()->setDx(0);
    }
    else if (!canGoRight){
        getMetroid()->setDx(0);
    }
    else if (canGoLeft && (keys & KEY_LEFT)){
        getMetroid()->setDx(-1);
        getMetroid()->flipHorizontally(true);
    }
    else if (canGoRight && (keys & KEY_RIGHT)){
        getMetroid()->setDx(1);
        getMetroid()->flipHorizontally(false);
    } else{
        getMetroid()->setDx(0);
    }
}
else{
    if(keys & KEY_B){
        if(canGoUp){
            isJumping = true;
            getMetroid()->setDy(-2);
            getMetroid()->animateToFrame(5);
            getMetroid()->stopAnimating();
        }
    }
    else if (keys & KEY_RIGHT && canGoRight){
        goLeft = false;
        isCrouching = false;
        if(canGoDown){
            isFalling = true;
            getMetroid()->setDx(0);
            getMetroid()->animateToFrame(5);
            getMetroid()->stopAnimating();
        }
        else {
            getMetroid()->setDx(1);
            getMetroid()->makeAnimated(6, 3);
            getMetroid()->flipHorizontally(false);
        }
    }
    else if (keys & KEY_LEFT && canGoLeft){
        goLeft = true;
        isCrouching = false;
        if(canGoDown){
            isFalling = true;
            getMetroid()->setDx(0);
            getMetroid()->animateToFrame(5);
            getMetroid()->stopAnimating();
        }
        else {
            getMetroid()->setDx(-1);
            getMetroid()->makeAnimated(6, 3);
            getMetroid()->flipHorizontally(true);
        }
    }
    else if (keys & KEY_DOWN){
        isCrouching = true;
        getMetroid()->animateToFrame(10);
        getMetroid()->setVelocity(0, 0);
    }
    else{
        isCrouching = false;
        getMetroid()->animateToFrame(7);
        getMetroid()->stopAnimating();
        getMetroid()->setVelocity(0, 0);
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
