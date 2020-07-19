//
// Created by michi on 27/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAME1SCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAME1SCREEN_H


#include <libgba-sprite-engine/scene.h>
#include "../src/Minigame1/Minigame1.h"

class Minigame1Screen : public Scene {
private:

    //Minigame1 minigame(std::shared_ptr<GBAEngine> engine);
    Minigame1 minigame;
    std::unique_ptr<Sprite> vallendVoorwerp1Sprite;

    std::unique_ptr<Background> background;
    u16 lastKeys = 0;
    bool firstTick = true;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    //Minigame1Screen(std::shared_ptr<GBAEngine> engine, Minigame1 minigame) : Scene(engine) {};
    Minigame1Screen(std::shared_ptr<GBAEngine> engine) : Scene(engine) {};
    void updateSprite();


    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAME1SCREEN_H
