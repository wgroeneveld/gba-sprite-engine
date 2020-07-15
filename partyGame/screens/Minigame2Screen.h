//
// Created by michi on 15/07/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAME2SCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAME2SCREEN_H


#include <libgba-sprite-engine/scene.h>
#include "../src/Minigame2/Minigame2.h"


class Minigame2Screen : public Scene {
private:
    Minigame2 game;
    std::unique_ptr<Sprite> ufo;
    u16 lastKeys = 0;
    bool firstTick = true;
    std::unique_ptr<Background> background;
    bool bezig = true;
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

   Minigame2Screen(std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}; //Kijken of ik hier &engine ofzo moet doen

    void load() override;
    void tick(u16 keys) override;

    void updatePosition();
    void endScene();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAME2SCREEN_H
