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
        if(!canGoUp){
            isJumping = false;
            isFalling = true;
        }
        else if (canGoLeft && (keys & KEY_LEFT)){
            getMetroid()->setDx(-1);
            getMetroid()->flipHorizontally(true);
            goLeft = true;
        }
        else if (canGoRight && (keys & KEY_RIGHT)){
            getMetroid()->setDx(1);
            getMetroid()->flipHorizontally(false);
            goLeft = false;
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
        else if (canGoLeft && (keys & KEY_LEFT)){
            getMetroid()->setDx(-1);
            getMetroid()->flipHorizontally(true);
            goLeft = true;
        }
        else if (canGoRight && (keys & KEY_RIGHT)){
            getMetroid()->setDx(1);
            getMetroid()->flipHorizontally(false);
            goLeft = false;
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

void Metroid::setCanGoUp(bool canGoUp) {
    Metroid::canGoUp = canGoUp;
}

void Metroid::setCanGoDown(bool canGoDown) {
    Metroid::canGoDown = canGoDown;
}
