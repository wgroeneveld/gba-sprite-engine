//
// Created by michi on 10/08/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_PLAYERSELECTSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_PLAYERSELECTSCREEN_H


#include <memory>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/background/background.h>
#include <libgba-sprite-engine/scene.h>

class PlayerSelectScreen : public Scene {

private:
    std::unique_ptr<Sprite> pijl;
    std::unique_ptr<Sprite> spook1;
    std::unique_ptr<Sprite> spook2;
    std::unique_ptr<Background> background;

    u16 lastKeys = 0;
    bool firstTick = true;

    int spelerKeuze = 0;

public:
    PlayerSelectScreen(std::shared_ptr<GBAEngine> engine) : Scene(engine) {};

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;

    void updatePijl();

};


#endif //GBA_SPRITE_ENGINE_PROJECT_PLAYERSELECTSCREEN_H
