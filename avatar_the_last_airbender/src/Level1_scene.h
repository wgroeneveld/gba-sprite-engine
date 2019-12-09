//
// Created by woute on 9/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_LEVEL1_SCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_LEVEL1_SCENE_H

#include <libgba-sprite-engine/scene.h>

class Level1_scene: public Scene {
private:
    std::unique_ptr<Sprite> aang;
    std::unique_ptr<Background> background;
    bool pressingAorB = false;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    Level1_scene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_LEVEL1_SCENE_H
