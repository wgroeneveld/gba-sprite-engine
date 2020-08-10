//
// Created by michi on 15/07/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAMESCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAMESCREEN_H


#include <libgba-sprite-engine/scene.h>
#include "../src/Minigame2/Minigame2.h"

#include "../src/Game/Game.h"
#include "../src/Minigame3.h"


class MinigameScreen : public Scene {
private:
    std::shared_ptr<Game> game;
    int spriteKeuze;
    Minigame3 minigame;
    std::unique_ptr<Sprite> ufo;
    u16 lastKeys = 0;
    bool firstTick = true;
    std::unique_ptr<Background> background;
    bool bezig = true;
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    MinigameScreen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje, int sprite) : Scene(engine), game(gamepje), spriteKeuze(sprite){};
    void load() override;
    void tick(u16 keys) override;

    void updatePosition();
    void endScene();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAMESCREEN_H
