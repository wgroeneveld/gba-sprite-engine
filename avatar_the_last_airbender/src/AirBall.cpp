//
// Created by woute on 27/12/2019.
// With a lot of inspiration from demo 3
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_bios.h>
#include <cmath>
#include <libgba-sprite-engine/gbavector.h>
#include "AirBall.h"




void AirBall::setLeft(bool left) {
    this->left = left;
}

void AirBall::tick() {
    if(left) {
        airballSprite->flipHorizontally(true);
       airballSprite->moveTo(airballSprite->getX() - 2, airballSprite->getY());
    }else{
        airballSprite->moveTo(airballSprite->getX() + 2, airballSprite->getY());
    }
}