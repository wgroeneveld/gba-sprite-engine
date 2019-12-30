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
        getMetroid()->makeAnimated(6,5);
        getMetroid()->flipHorizontally(true);
        getMetroid()->setVelocity(-2, 0);
    } else if(keys & KEY_RIGHT) {
        if(getMetroid()->getX()>=158){
            getMetroid()->makeAnimated(6,5);
            getMetroid()->flipHorizontally(false);
            getMetroid()->setVelocity(0, 0);
        }
        else{
            getMetroid()->makeAnimated(6,5);
            getMetroid()->flipHorizontally(false);
            getMetroid()->setVelocity(+2, 0);
        }
    } else {
        getMetroid()->animateToFrame(7);
        getMetroid()->stopAnimating();
        getMetroid()->setVelocity(0, 0);
    }
}