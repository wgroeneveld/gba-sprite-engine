//
// Created by kyles on 27/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_TRANSITION_H
#define GBA_SPRITE_ENGINE_PROJECT_TRANSITION_H

#include <libgba-sprite-engine/scene.h>
#include "Metroid.h"
#include "Mario.h"
#include "Bullet.h"

class Transition : public Scene {
private:
    std::unique_ptr<Background> bg;
    int scrollX, scrollY;


public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;


    Transition(std::shared_ptr<GBAEngine> engine) : Scene(engine), scrollX(0), scrollY(0) {}

    void load() override;
    void tick(u16 keys) override;

};

#endif //GBA_SPRITE_ENGINE_PROJECT_TRANSITION_H
