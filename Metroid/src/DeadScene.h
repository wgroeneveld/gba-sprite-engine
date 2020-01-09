//
// Created by kyles on 7/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_DEADSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_DEADSCENE_H


#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/scene.h>

class DeadScene : public Scene {
private:
    //std::unique_ptr<Sprite> animation;
    std::unique_ptr<Sprite> metroidDood;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    DeadScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_DEADSCENE_H
