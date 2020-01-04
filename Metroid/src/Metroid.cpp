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

void Metroid::tick(u16 keys) {

    if(isJumping){
        if(getMetroid()->getY() <= 30){
            isJumping = false;
            isFalling = true;
            if(goLeft){
            //    getMetroid()->flipHorizontally(true);
                getMetroid()->setVelocity(-2,-4);
            }
            else{
         //       getMetroid()->flipHorizontally(true);
                getMetroid()->setVelocity(+2,-4);
            }
        }
        else {
            if(goLeft){
           //     getMetroid()->flipHorizontally(true);
                getMetroid()->setVelocity(-1, -2);
            }
            else{
          //      getMetroid()->flipHorizontally(false);
                getMetroid()->setVelocity(+1, -2);
            }
        }
    }

    if(isFalling){
        if(getMetroid()->getY() == 88){
            getMetroid()->moveTo(getMetroid()->getX(),88);
            isFalling = false;
            canJump = true;
        }
        else {
            if(goLeft){
          //      getMetroid()->flipHorizontally(true);
                getMetroid()->setVelocity(-1, 2);
            }
            else{
           //     getMetroid()->flipHorizontally(false);
                getMetroid()->setVelocity(+1, 2);
            }
        }
    }

    if(keys & KEY_LEFT) {
        if(canJump){
            goLeft =true;
            isCrouching = false;
            if(keys & KEY_B){
                isJumping = true;
                canJump = false;
                getMetroid()->animateToFrame(7);
                getMetroid()->flipHorizontally(true);
                getMetroid()->stopAnimating();
            }
            else {
                getMetroid()->makeAnimated(6, 5);
                getMetroid()->flipHorizontally(true);
                getMetroid()->setVelocity(-1, 0);
            }
        }

    } else if(keys & KEY_RIGHT) {
        if(canJump){
            goLeft = false;
            isCrouching = false;
            if(keys & KEY_B) {
                isJumping = true;
                canJump = false;
                getMetroid()->animateToFrame(7);
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