//
// Created by SDM Technics on 28/12/2019.
//

#include "Metroid.h"
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/gba/tonc_math.h>

void Metroid::tick(u16 keys) {
    getMetroid()->stopAnimating();
    if(keys & KEY_LEFT) {
        getMetroid()->animate();
        getMetroid()->flipHorizontally(true);
        getMetroid()->setVelocity(-2, 0);
    } else if(keys & KEY_RIGHT) {
        getMetroid()->animate();
        getMetroid()->flipHorizontally(false);
        getMetroid()->setVelocity(+2, 0);
    } else {
        getMetroid()->animateToFrame(0);
        getMetroid()->setVelocity(0, 0);
    }
}