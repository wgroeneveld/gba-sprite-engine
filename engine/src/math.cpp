//
// Created by Wouter Groeneveld on 14/12/18.
//

#include <libgba-sprite-engine/math.h>

std::deque<VECTOR> Math::bresenhamLineBetween(VECTOR src, VECTOR dest) {
    // https://www.coranac.com/tonc/text/bitmaps.htm - Bresenham's line algorithm with fixed points
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