//
// Created by Wouter Groeneveld on 09/08/18.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_bios.h>
#include "bullet.h"

// in 1/256 pixels
#define SPEED 50

u32 length(VECTOR a) {
    return Sqrt(a.x * a.x + a.y * a.y);
}

u32 distance(VECTOR a, VECTOR b) {
    return length({a.x - b.x, a.y - b.y});
}

VECTOR normalize(VECTOR a) {
    u32 l = length(a);
    return { a.x / l, a.y / l };
}

void Bullet::setDestination(VECTOR vec) {
    this->dest = vec;
}

// TODO https://gamedev.stackexchange.com/questions/23447/moving-from-ax-y-to-bx1-y1-with-constant-speed
void Bullet::tick() {
    auto pos = sprite->getPos();
    int xdiff = 1, ydiff = 1;

    if(abs(pos.x - dest.x) > abs(pos.y - dest.y)) {
        xdiff += 1;
    } else {
        ydiff += 1;
    }

    if(pos.x > dest.x) {
        vel.x -= 1 * xdiff;
    } else if(pos.x < dest.x) {
        vel.x = 1 * xdiff;
    }
    if(pos.y > dest.y) {
        vel.y -= 1 * ydiff;
    } else if(pos.y < dest.y) {
        vel.y = 1 * ydiff;
    }

    TextStream::instance().setText(std::string("pos/dest: (") + std::to_string(pos.x) + std::string(",") + std::to_string(pos.y) + std::string(") (") + std::to_string(dest.x) + std::string(",") + std::to_string(dest.y) + std::string(")"), 16, 1);

    sprite->setVelocity(vel.x, vel.y);
}