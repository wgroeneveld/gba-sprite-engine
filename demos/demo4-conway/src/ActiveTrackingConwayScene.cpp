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

    // when starting slow (100 active), this totals to 100 * 9 = +900 instructions VS +30k in the naive impl
    // when starting high, this will too slow down, worst case slightly slower than naive (SIZE * 9 instead of * 8)
    // 1. loop through all "active" cells.
    for(int i = 0; i < MAP_SIZE; i++) {
        auto cell = activeCellIndex[i];
        if(!cell.taken) {
            break;
        }
        int x = cell.x, y = cell.y;

        // 2. process those _AND_ the neighbours (could be dead ones becoming alive)
        for(int x_i = x - 1; x_i <= x + 1; x_i++) {
            for(int y_j = y - 1; y_j <= y + 1; y_j++) {
                int toCheckPos = y_j * MAP_WIDTH + x_i;
                if(toCheckPos >= 0 && toCheckPos < MAP_SIZE - 1) {
                    u16 state = getNextState(x_i, y_j);
                    if(state == ALIVE) {
                        // 3. Save the cell metadata if active for the next generation
                        activeCellIndexBuffer[totalAmountAlive].taken = true;
                        activeCellIndexBuffer[totalAmountAlive].x = x_i;
                        activeCellIndexBuffer[totalAmountAlive].y = y_j;
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
    dma3_cpy(activeCellIndex, activeCellIndexBuffer, sizeof(activeCellIndex));

    dma3_cpy(map, buffer, sizeof(map));
    bg.get()->updateMap(map);
}


void ActiveTrackingConwayScene::postload() {
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