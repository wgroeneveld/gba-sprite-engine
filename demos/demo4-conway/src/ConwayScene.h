//
// Created by Wouter Groeneveld on 30/11/18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_CONWAYSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_CONWAYSCENE_H


#define MAP_WIDTH 64
#define MAP_HEIGHT 64
#define MAP_SIZE 64 * 64

#define ALIVE 0x0001
#define DEAD  0x0002

#include <libgba-sprite-engine/scene.h>


class ConwayScene : public Scene {
protected:
    u8 percentageSeed;
    u16 generation;
    std::unique_ptr<Background> bg;
    u16 map[MAP_SIZE], buffer[MAP_SIZE];

    void seedRandomMap(int seedcount);
    int countAmountOfNeighbouringCellsAlive(int pos, int x, int y);
    u16 getNextState(int x, int y);

public:
    ConwayScene(const std::shared_ptr<GBAEngine> &engine, u8 percentageSeed) : Scene(engine), percentageSeed(percentageSeed) {}

    std::vector<Sprite *> sprites() override;

    std::vector<Background *> backgrounds() override;

    void load() override;

    virtual void postload() = 0;

    virtual void tick(u16 keys) = 0;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_CONWAYSCENE_H
