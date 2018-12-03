//
// Created by Wouter Groeneveld on 30/11/18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ACTIVETRACKINGCONWAYSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_ACTIVETRACKINGCONWAYSCENE_H


#include "ConwayScene.h"

struct cell {
    bool taken;
    int x, y, pos;
    u8 futureState;
};

class ActiveTrackingConwayScene : public ConwayScene {
private:
    int totalAmountAlive = 0;
    int neighbourCount[MAP_SIZE] = {0};
    cell activeCellIndex[MAP_SIZE + 1] = {0}, activeCellIndexBuffer[MAP_SIZE + 1] = {0};

public:
    ActiveTrackingConwayScene(const std::shared_ptr<GBAEngine> &engine, u8 percentageSeed);

    void tick(u16 keys) override;

    void postload() override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_ACTIVETRACKINGCONWAYSCENE_H
