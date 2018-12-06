//
// Created by Wouter Groeneveld on 02/08/18.
//

#ifndef GBA_SPRITE_ENGINE_SAMPLE_START_SCENE_H
#define GBA_SPRITE_ENGINE_SAMPLE_START_SCENE_H

#include <libgba-sprite-engine/scene.h>

class SampleStartScene : public Scene {
private:
    std::unique_ptr<Sprite> animation;
    std::unique_ptr<Sprite> finalFantasyGuy;
    std::unique_ptr<Sprite> smiley;
    bool pressingAorB = false;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    SampleStartScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_SAMPLE_START_SCENE_H
