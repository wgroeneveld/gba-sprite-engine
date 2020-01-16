//
// Created by woute on 16/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_END_SCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_END_SCENE_H


#include <libgba-sprite-engine/scene.h>

class End_scene : public Scene {
private:
    int amountEnemysKilled;
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    End_scene(std::shared_ptr<GBAEngine> engine, int amountKilled) : Scene(engine), amountEnemysKilled(amountKilled) {}

    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_END_SCENE_H
