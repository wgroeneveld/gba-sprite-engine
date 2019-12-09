//
// Created by woute on 28/11/2019.
//

#ifndef AVATAR_THE_LAST_AIRBENDER_LEVEL1_SCENE_H
#define AVATAR_THE_LAST_AIRBENDER_LEVEL1_SCENE_H


#include <libgba-sprite-engine/scene.h>

class Titlescreen_scene: public Scene {
private:
    std::unique_ptr<Background> background;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    Titlescreen_scene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;

};



#endif //AVATAR_THE_LAST_AIRBENDER_LEVEL1_SCENE_H
