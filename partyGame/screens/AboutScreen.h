//
// Created by michi on 22/03/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ABOUTSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_ABOUTSCREEN_H


#include <libgba-sprite-engine/scene.h>

class AboutScreen : public Scene {
private:

    std::unique_ptr<Background> background;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    AboutScreen(std::shared_ptr<GBAEngine> engine) : Scene(engine) {};



    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ABOUTSCREEN_H

// moet hier ergens explicit ofzo komen? Zie vorige taak (minions vs zombies)