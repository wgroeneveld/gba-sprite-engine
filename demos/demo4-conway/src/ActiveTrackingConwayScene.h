//
// Created by Wouter Groeneveld on 30/11/18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ACTIVETRACKINGCONWAYSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_ACTIVETRACKINGCONWAYSCENE_H


#include "ConwayScene.h"

struct cell {
    bool taken;
    int x, y;
};

class ActiveTrackingConwayScene : public ConwayScene {
private:
    cell activeCellIndex[MAP_SIZE] = {0}, activeCellIndexBuffer[MAP_SIZE] = {0};

public:
    ActiveTrackingConwayScene(const std::shared_ptr<GBAEngine> &engine, u8 percentageSeed);

    void tick(u16 keys) override;

    void postload() override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_ACTIVETRACKINGCONWAYSCENE_H
