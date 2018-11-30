//
// Created by Wouter Groeneveld on 30/11/18.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_core.h>
#include "ActiveTrackingConwayScene.h"

ActiveTrackingConwayScene::ActiveTrackingConwayScene(const std::shared_ptr<GBAEngine> &engine, u8 percentageSeed)
        : ConwayScene(engine, percentageSeed) {}

void ActiveTrackingConwayScene::tick(u16 keys) {
    generation++;
    int totalAmountAlive = 0;
    dma3_cpy(buffer, map, sizeof(buffer));

    // "Active Tracking" implementation:
    // 1. O(active*8*9) loop
    // when starting slow (100 active), this totals to 100 * 9 * 8 = +7200 instructions VS +30k in the naive impl
    // when starting high, this will too slow down, worst case even slower than naive (SIZE*9*8 instead of only *8)

    // 1. loop through all "active" cells, initially gathered outside tick()
    for(int i = 0; i < MAP_SIZE; i++) {
        auto cell = activeCellIndex[i];
        if(!cell.taken) {
            break;
        }
        int x = cell.x, y = cell.y;

        // 2. process those _AND_ the neighbours (9 checks) (could be dead ones becoming alive)
        for(int y_j = y - 1; y_j <= y + 1; y_j++) {
            int y_jw = y_j * MAP_WIDTH;

            for(int x_i = x - 1; x_i <= x + 1; x_i++) {
                int toCheckPos = y_jw + x_i;
                if(toCheckPos >= 0 && toCheckPos < MAP_SIZE - 1) {
                    // 3. Remember the following statement expands into 8 neighbour-checks
                    u16 state = getNextState(x_i, y_j, toCheckPos);
                    if(state == ALIVE) {
                        // 3. Save the cell metadata if active for the next generation
                        activeCellIndex[totalAmountAlive].taken = true;
                        activeCellIndex[totalAmountAlive].x = x_i;
                        activeCellIndex[totalAmountAlive].y = y_j;
                        totalAmountAlive++;
                    }
                    buffer[toCheckPos] = state;
                }
            }
        }
    }
    activeCellIndexBuffer[totalAmountAlive].taken = false;

    TextStream::instance().setText(std::string("amount alive: ") + std::to_string(totalAmountAlive) + std::string(" of ") + std::to_string(MAP_SIZE), 1, 1);
    TextStream::instance().setText(std::string("generation: ") + std::to_string(generation), 2, 1);
    //dma3_cpy(activeCellIndex, activeCellIndexBuffer, sizeof(activeCellIndex));

    dma3_cpy(map, buffer, sizeof(map));
    bg.get()->updateMap(map);
}


void ActiveTrackingConwayScene::postload() {
    // speed optimization: save active cells in a separate array, to be reused (that's why the taken bool is there)
    int i = 0;
    for(int w = 0; w < MAP_WIDTH; w++) {
        for(int h = 0; h < MAP_HEIGHT; h++) {
            u8 index = h * MAP_WIDTH + w;

            if(map[index] == ALIVE) {
                activeCellIndex[i].taken = true;
                activeCellIndex[i].x = w;
                activeCellIndex[i].y = h;
                i++;
            }
        }
    }
}