//
// Created by Wouter Groeneveld on 14/12/18.
//

#include <libgba-sprite-engine/gbavector.h>

VECTOR GBAVector::rotateAsCenter(VECTOR point, uint angle) {
    auto center = this->v;
    s32 centerx = center.x, centery = center.y;
    s32 defaultx = point.x, defaulty = point.y;

    s32 cos = lu_cos(angle) >> 4;
    s32 sin = lu_sin(angle) >> 4;

    // affine matriches are 8.8 fixed point numbers, so shift all input 8 spaces up and forth
    // possibilities: instead of between [-1.0, 1.0] it's between [-256, +256]
    // 90° rotation in inversed y-axis needs to flip sin sign
    return {
            ( cos * (defaultx - centerx) + sin * (defaulty - centery) + (centerx << 8)) >> 8,
            (-sin * (defaultx - centerx) + cos * (defaulty - centery) + (centery << 8)) >> 8};
}

std::deque<VECTOR> GBAVector::bresenhamLineTo(VECTOR dest) {
    // https://www.coranac.com/tonc/text/bitmaps.htm - Bresenham's line algorithm with fixed points
    VECTOR src = this->v;
    VECTOR step, delta;

    std::deque<VECTOR> coords;

    if(src.x > dest.x) {
        step.x = -1;
        delta.x = (src.x - dest.x);
    } else {
        step.x = +1;
        delta.x = (dest.x - src.x);
    }
    if(src.y > dest.y) {
        step.y = -1;
        delta.y = (src.y - dest.y);
    } else {
        step.y = +1;
        delta.y = (dest.y - src.y);
    }

    int dd, x = src.x, y = src.y, ii;

    if(delta.y == 0) {
        // horizontal
        for(ii = 0; ii <= delta.x; ii++) {
            coords.push_back({x, y});
            x += step.x;
        }
    } else if(delta.x == 0) {
        // vertical
        for(ii = 0; ii <= delta.y; ii++) {
            coords.push_back({x, y});
            y += step.y;
        }
    } else if(delta.x >= delta.y) {
        // Diagonal, slope <= 1
        dd = 2 * delta.y - delta.x;

        for(ii = 0; ii <= delta.x; ii++) {
            coords.push_back({x, y});
            if(dd >= 0) {
                dd -= 2 * delta.x;
                y += step.y;
            }
            dd += 2 * delta.y;
            x += step.x;
        }
    } else {
        // Diagonal, slope > 1
        dd = 2 * delta.x - delta.y;

        for(ii = 0; ii <= delta.y; ii++) {
            coords.push_back({x, y});
            if(dd >= 0) {
                dd -= 2 * delta.y;
                x += step.x;
            }
            dd += 2 * delta.x;
            y += step.y;
        }
    }

    return coords;
}