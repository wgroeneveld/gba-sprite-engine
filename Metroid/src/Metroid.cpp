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

    if(keys & KEY_LEFT) {
        goLeft =true;
        isCrouching = false;
        if(keys & KEY_B){
            
        }
        else {
            getMetroid()->makeAnimated(6, 5);
            getMetroid()->flipHorizontally(true);
            getMetroid()->setVelocity(-2, 0);
        }
    } else if(keys & KEY_RIGHT) {
        goLeft = false;
        isCrouching = false;
        getMetroid()->makeAnimated(6,5);
        getMetroid()->flipHorizontally(false);
        getMetroid()->setVelocity(+2, 0);
    }
    else if(keys & KEY_DOWN){
        isCrouching = true;
        if(goLeft){
            getMetroid()->animateToFrame(10);
            getMetroid()->flipHorizontally(true);
            getMetroid()->setVelocity(0, 0);
        }
        else{
            getMetroid()->animateToFrame(10);
            getMetroid()->flipHorizontally(false);
            getMetroid()->setVelocity(0, 0);
        }
    }
    else {
        getMetroid()->animateToFrame(7);
        getMetroid()->stopAnimating();
        getMetroid()->setVelocity(0, 0);
        isCrouching = false;
    }



    if(isJumping){
        if(getMetroid()->getY() <= 40){
            if(goLeft){
                getMetroid()->setVelocity(-2,2);
            }
            else{
                getMetroid()->setVelocity(2,2);
            }
        }
    }
}