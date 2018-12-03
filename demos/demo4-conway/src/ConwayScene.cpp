//
// Created by Wouter Groeneveld on 30/11/18.
//

#include "ConwayScene.h"
#include "bg.h"

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_core.h>
#include <libgba-sprite-engine/background/text_stream.h>


// See http://www.coranac.com/tonc/text/gfx.htm#cd-qran
int __qran_seed= 42;     // Seed / rnd holder

std::vector<Sprite *> ConwayScene::sprites() {
    return {};
}

std::vector<Background *> ConwayScene::backgrounds() {
    return { bg.get() };
}

u16 ConwayScene::getNextStateWithCount(int currentState, int amountAlive) {
    // speed optimization: skip the ifs. "? ALIVE : DEAD" can also be skipped if you're sure they are 1 and 0.
    return (amountAlive == 3 || (amountAlive == 2 && (currentState == ALIVE))) ? ALIVE : DEAD;
}

u16 ConwayScene::getNextState(int x, int y, int pos) {
    int amountAlive = countAmountOfNeighbouringCellsAlive(pos, x, y);

    int currentState = map[pos];
    return getNextStateWithCount(currentState, amountAlive);
}

int ConwayScene::countAmountOfNeighbouringCellsAlive(int pos, int x, int y) {
    int amountOfNeightbouringCellsAlive = 0;

    for(int x_i = x - 1; x_i <= x + 1; x_i++) {
        for(int y_j = y - 1; y_j <= y + 1; y_j++) {
            int toCheckPos = y_j * MAP_WIDTH + x_i;
            if(toCheckPos >= 0 && toCheckPos < MAP_SIZE - 1 && pos != toCheckPos && map[toCheckPos] == ALIVE) {
                amountOfNeightbouringCellsAlive++;
            }
        }
    }

    return amountOfNeightbouringCellsAlive;
}

void ConwayScene::load() {
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(conway_palette, sizeof(conway_palette)));

    seedRandomMap(((MAP_WIDTH * MAP_HEIGHT) / 100) * percentageSeed);

    bg = std::unique_ptr<Background>(new Background(1, conway_data, sizeof(conway_data), map, sizeof(map)));
    bg.get()->useMapScreenBlock(16);

    postload();
}

void ConwayScene::seedRandomMap(int seedcount) {
    for(int i = 0; i < seedcount; i++) {
        int x = qran_range(0, MAP_WIDTH);
        int y = qran_range(0, MAP_HEIGHT);
        map[y * MAP_WIDTH + x] = ALIVE;
    }
}

