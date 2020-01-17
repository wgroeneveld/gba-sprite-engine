#include "AirBall.h"

void AirBall::tick() {
    if(flyingLeft) {
        airballSprite->flipHorizontally(true);
        airballSprite->moveTo(airballSprite->getX() - 2, airballSprite->getY());
    }else{
        airballSprite->flipHorizontally(false);
        airballSprite->moveTo(airballSprite->getX() + 2, airballSprite->getY());
    }
}