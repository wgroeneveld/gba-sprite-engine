//
// Created by kyles on 9/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_OVERGANGSCENE1_H
#define GBA_SPRITE_ENGINE_PROJECT_OVERGANGSCENE1_H

#include <libgba-sprite-engine/scene.h>

class OvergangScene1 : public Scene {
private:

    std::unique_ptr<Background> bg;

public:
    OvergangScene1(const std::shared_ptr<GBAEngine> &engine);

    std::vector<Sprite *> sprites() override;

    std::vector<Background *> backgrounds() override;

    void load() override;

    void tick(u16 keys) override;
};



#endif //GBA_SPRITE_ENGINE_PROJECT_OVERGANGSCENE1_H
