//
// Created by michi on 14/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAMESCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_GAMESCREEN_H


#include <libgba-sprite-engine/scene.h>
#include "../src/Game/Game.h"


class GameScreen : public Scene {

private:
    std::shared_ptr<Game> game = std::make_shared<Game>(Game());

    std::unique_ptr<Sprite> spook1Sprite;
    //std::unique_ptr<Sprite> spook2Sprite;
    std::unique_ptr<Sprite> dobbelSteenSprite;

    u16 lastKeys = 0;
    bool firstTick = true;
    std::unique_ptr<Background> background;
    std::unique_ptr<Background> background2;

    bool aanHetGooien = false;
    bool aanHetSpringen = false;

    int spriteKeuze;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;
    GameScreen(std::shared_ptr<GBAEngine> engine, int sprite) : Scene(engine), spriteKeuze(sprite) {};
    GameScreen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje, int sprite) : Scene(engine), game(gamepje), spriteKeuze(sprite) {};

    void load() override;
    void tick(u16 keys) override;

    void updatePosition();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GAMESCREEN_H
