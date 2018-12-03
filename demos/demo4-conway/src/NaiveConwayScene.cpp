//
// Created by Wouter Groeneveld on 30/11/18.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_core.h>
#include <libgba-sprite-engine/background/text_stream.h>

#include "NaiveConwayScene.h"
#include "ConwayScene.h"


void NaiveConwayScene::tick(u16 keys) {
    generation++;
    int totalAmountAlive = 0;
    dma3_cpy(buffer, map, sizeof(buffer));

    // "Naïve" implementation:
    // 1. O(n^2) loop
    //  2. for each element, check x-1, x, x+y, y-1, y,y+1
    // totals to min. 600 * 8 = +4800 instructions, each update(), at only 16.8 MHz!

    // speed optimization: reverse x/y in loop, calculate index in outer for
    // speed optimization: (needed for gba, as we copypaste this literally into VRAM) single-depth array with * lookup
    for(int h = 0; h < MAP_HEIGHT; h++) {
        int hw = h * MAP_WIDTH;

        for(int w = 0; w < MAP_WIDTH; w++) {
            int pos = hw + w;
            u16 state = getNextState(w, h, pos);
            if(state == ALIVE) totalAmountAlive++;
            buffer[pos] = state;
        }
    }

    TextStream::instance().setText(std::string("amount alive: ") + std::to_string(totalAmountAlive) + std::string(" of ") + std::to_string(MAP_SIZE), 1, 1);
    TextStream::instance().setText(std::string("generation: ") + std::to_string(generation), 2, 1);

    dma3_cpy(map, buffer, sizeof(map));
    bg.get()->updateMap(map);
}

void NaiveConwayScene::postload() {

}
