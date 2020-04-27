//
// Created by michi on 27/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_VANGSPELSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_VANGSPELSCREEN_H


#include <libgba-sprite-engine/scene.h>

class VangspelScreen : public Scene {
private:

    std::unique_ptr<Background> background;

    u16 lastKeys = 0;
    bool firstTick = true;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    VangspelScreen(std::shared_ptr<GBAEngine> engine) : Scene(engine) {};



    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_VANGSPELSCREEN_H
