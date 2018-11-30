//
// Created by Wouter Groeneveld on 30/11/18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_CONWAYSEEDER_H
#define GBA_SPRITE_ENGINE_PROJECT_CONWAYSEEDER_H


#include <libgba-sprite-engine/scene.h>

class ConwaySeeder : public Scene {
private:
    int delta;
    int impl;
    int percentage;
    std::unique_ptr<Sprite> conwaySprite;

public:
    ConwaySeeder(const std::shared_ptr<GBAEngine> &engine);

    std::vector<Sprite *> sprites() override;

    std::vector<Background *> backgrounds() override;

    void load() override;

    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_CONWAYSEEDER_H
