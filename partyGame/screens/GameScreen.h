//
// Created by michi on 14/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAMESCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_GAMESCREEN_H


#include <libgba-sprite-engine/scene.h>
#include "../src/Game.h"

class GameScreen : public Scene {

private:
    Game game;
    std::unique_ptr<Sprite> speler1Sprite;
    u16 lastKeys = 0;
    bool firstTick = true;
    std::unique_ptr<Background> background;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    GameScreen(std::shared_ptr<GBAEngine> engine) : Scene(engine) {};

    void load() override;
    void tick(u16 keys) override;

    void updateSpeler1();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GAMESCREEN_H
