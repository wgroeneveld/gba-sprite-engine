//
// Created by woute on 27/12/2019.
// With a lot of inspiration from demo 3
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_bios.h>
#include <cmath>
#include <libgba-sprite-engine/gbavector.h>
#include "AirBall.h"




void AirBall::setDestination(VECTOR destination) {
    auto currentPos = sprite->getPosAsVector();
    this->dest = destination;

    this->coords = currentPos.bresenhamLineTo(destination);

    TextStream::instance().setText(std::string(" in setDest"), 7,1);
}

void AirBall::tick() {
    if(coords.empty()) {
        return;
    }

    sprite->moveTo(coords.front());
    coords.pop_front();
}