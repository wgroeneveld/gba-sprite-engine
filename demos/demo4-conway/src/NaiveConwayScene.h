//
// Created by Wouter Groeneveld on 30/11/18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_NAIVE_CONWAYSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_NAIVE_CONWAYSCENE_H


#include "ConwayScene.h"

class NaiveConwayScene : public ConwayScene {
private:

    int countAmountOfNeighbouringCellsAlive(int pos, int x, int y);

public:
    NaiveConwayScene(const std::shared_ptr<GBAEngine> &engine, u8 percentageSeed) : ConwayScene(engine, percentageSeed) {}

    void tick(u16 keys) override;

    void postload() override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_CONWAYSCENE_H
