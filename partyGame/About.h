//
// Created by michi on 22/03/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ABOUT_H
#define GBA_SPRITE_ENGINE_PROJECT_ABOUT_H


#include <libgba-sprite-engine/scene.h>

class About : public Scene {
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    About(std::shared_ptr<GBAEngine> engine) : Scene(engine) {};
    //~MainMenu(){};


    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ABOUT_H

// moet hier ergens explicit ofzo komen? Zie vorige taak (minions vs zombies)