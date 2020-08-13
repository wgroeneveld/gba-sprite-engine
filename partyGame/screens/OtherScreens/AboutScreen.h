//
// Created by michi on 22/03/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ABOUTSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_ABOUTSCREEN_H


#include <libgba-sprite-engine/scene.h>

class AboutScreen : public Scene {
private:

    std::unique_ptr<Background> background;
    std::unique_ptr<Sprite> pijl;
    std::unique_ptr<Sprite> spook;

    u16 lastKeys = 0;
    bool firstTick = true;

public:
    AboutScreen(std::shared_ptr<GBAEngine> engine) : Scene(engine) {};

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ABOUTSCREEN_H

// moet hier ergens explicit ofzo komen? Zie vorige taak (minions vs zombies)