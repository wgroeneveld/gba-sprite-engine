//
// Created by kyles on 8/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_VICTORYSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_VICTORYSCENE_H

#include <libgba-sprite-engine/scene.h>

class VictoryScene : public Scene {
private:
    std::unique_ptr<Background> bg;

public:
    VictoryScene(const std::shared_ptr<GBAEngine> &engine);

    std::vector<Sprite *> sprites() override;

    std::vector<Background *> backgrounds() override;

    void load() override;

    void tick(u16 keys) override;
};



#endif //GBA_SPRITE_ENGINE_PROJECT_VICTORYSCENE_H
