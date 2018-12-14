//
// Created by Wouter Groeneveld on 14/12/18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MATH_H
#define GBA_SPRITE_ENGINE_PROJECT_MATH_H

#include <deque>
#include <libgba-sprite-engine/gba/tonc_math.h>

class Math {
public:
    static std::deque<VECTOR> bresenhamLineBetween(VECTOR src, VECTOR dest);
};

#endif //GBA_SPRITE_ENGINE_PROJECT_MATH_H
