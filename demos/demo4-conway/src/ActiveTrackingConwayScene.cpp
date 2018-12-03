//
// Created by Wouter Groeneveld on 30/11/18.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_core.h>
#include "ActiveTrackingConwayScene.h"

ActiveTrackingConwayScene::ActiveTrackingConwayScene(const std::shared_ptr<GBAEngine> &engine, u8 percentageSeed)
        : ConwayScene(engine, percentageSeed) {}

void ActiveTrackingConwayScene::tick(u16 keys) {
    generation++;;
    dma3_cpy(buffer, map, sizeof(buffer));

    // "Active Tracking" implementation:
    // 1. O(changing*(8*2)) loop
    // when starting slow (100 active), this totals to 100 * (8*2) = +1600 instructions VS +4800 in the naive impl
    // when starting high, this will too slow down, worst case even slower than naive (SIZE(*8+2) instead of only *8)

    // 1. loop through all "active" cells, initially gathered outside tick()
    int j = 0;
    u8 futureState, currState;
    for(int i = 0; i < MAP_SIZE; i++) {
        auto cell = activeCellIndex[i];
        if(!cell.taken) {
            break;
        }
        int x = cell.x, y = cell.y, pos = cell.pos;

        // 2. process only those which will change state: update neighbour count. x8
        int delta = cell.futureState == ALIVE ? +1 : -1;
        totalAmountAlive += delta;
        buffer[cell.pos] = cell.futureState;
        for(int x_i = x - 1; x_i <= x + 1; x_i++) {
            for(int y_j = y - 1; y_j <= y + 1; y_j++) {
                int toCheckPos = y_j * MAP_WIDTH + x_i;
                if(toCheckPos >= 0 && toCheckPos < MAP_SIZE - 1 && pos != toCheckPos) {
                    neighbourCount[toCheckPos] += delta;
                }
            }
        }

        // 3. if neighbours (and own cell) will possibly change, add them to the next run. x9
        for(int x_i = x - 1; x_i <= x + 1; x_i++) {
            for(int y_j = y - 1; y_j <= y + 1; y_j++) {
                int toCheckPos = y_j * MAP_WIDTH + x_i;
                if(toCheckPos >= 0 && toCheckPos < MAP_SIZE - 1) {
                    currState = buffer[toCheckPos];
                    futureState = getNextStateWithCount(currState, neighbourCount[toCheckPos]);
                    if(futureState != currState) {
                        activeCellIndexBuffer[j].taken = true;
                        activeCellIndexBuffer[j].x = x_i;
                        activeCellIndexBuffer[j].y = y_j;
                        activeCellIndexBuffer[j].pos = toCheckPos;
                        activeCellIndexBuffer[j].futureState = futureState;
                        j++;
                    }
                }
            }
        }
    }
    activeCellIndexBuffer[j].taken = false;

    TextStream::instance().setText(std::string("amount alive: ") + std::to_string(totalAmountAlive) + std::string(" of ") + std::to_string(MAP_SIZE), 1, 1);
    TextStream::instance().setText(std::string("generation: ") + std::to_string(generation), 2, 1);
    dma3_cpy(activeCellIndex, activeCellIndexBuffer, sizeof(activeCellIndexBuffer));

    dma3_cpy(map, buffer, sizeof(map));
    bg.get()->updateMap(map);
}


void ActiveTrackingConwayScene::postload() {
    // speed optimization: save active cells in a separate array, to be reused (that's why the taken bool is there)
    int i = 0;
    for(int h = 0; h < MAP_HEIGHT; h++) {
        int h_w = h * MAP_WIDTH;
        for(int w = 0; w < MAP_WIDTH; w++) {
            int pos = h_w + w;
            int count = countAmountOfNeighbouringCellsAlive(pos, w, h);
            u8 currentState = map[pos];
            u8 futureState = getNextStateWithCount(currentState, count);

            if(currentState == ALIVE) {
                totalAmountAlive++;
            }

            neighbourCount[pos] = count;
            if(currentState != futureState) {
                activeCellIndex[i].taken = true;
                activeCellIndex[i].x = w;
                activeCellIndex[i].y = h;
                activeCellIndex[i].pos = pos;
                activeCellIndex[i].futureState = futureState;
                i++;
            }
        }
    }
    activeCellIndex[i].taken = false;
}