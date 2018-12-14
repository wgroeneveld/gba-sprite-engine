//
// Created by Wouter Groeneveld on 09/08/18.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_bios.h>
#include "bullet.h"

#define FIXED_POINT_BASE 1000
#define SPEED_DELTA 1

void Bullet::setDestination(VECTOR destination) {
    auto currentPos = sprite->getPos();
    this->dest = destination;

    diff.x = (destination.x - currentPos.x);
    diff.y = (destination.y - currentPos.y);
    directionToCover.x = diff.x * FIXED_POINT_BASE;
    directionToCover.y = diff.y * FIXED_POINT_BASE;

    TextStream::instance().setText(std::string("covering: ") + std::to_string(directionToCover.x) + std::string(",") + std::to_string(directionToCover.y), 15, 1);
}

void Bullet::tick() {
    auto x = sprite->getX(), y = sprite->getY();

    if(directionToCover.x != 0) {
        if(directionToCover.x > 0) {
            directionToCover.x -= FIXED_POINT_BASE;
            x += SPEED_DELTA;
        } else {
            directionToCover.x += FIXED_POINT_BASE;
            x -= SPEED_DELTA;
        }
    }
    if(directionToCover.y != 0) {
        if(directionToCover.y > 0) {
            directionToCover.y -= FIXED_POINT_BASE;
            y += SPEED_DELTA;
        } else {
            directionToCover.y += FIXED_POINT_BASE;
            y -= SPEED_DELTA;
        }
    }

    sprite->moveTo(x, y);
}
