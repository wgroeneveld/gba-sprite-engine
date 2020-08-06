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

    std::unique_ptr<Sprite> speler1Sprite;
    u16 lastKeys = 0;
    bool firstTick = true;
    bool spelGespeeld = false;
    std::unique_ptr<Background> background;
    std::unique_ptr<Background> background2;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    //GameScreen(std::shared_ptr<GBAEngine> engine) : Scene(engine), gamePointer(new Game()) {};

    //GameScreen(std::shared_ptr<GBAEngine> engine) : Scene(engine), game(Game()) {};
    //GameScreen(std::shared_ptr<GBAEngine> engine, Game gamepje) : Scene(engine), game(gamepje) {};
    GameScreen(std::shared_ptr<GBAEngine> engine) : Scene(engine) {};
    GameScreen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje) : Scene(engine), game(gamepje) {};
    //GameScreen(std::shared_ptr<GBAEngine> engine, Game referenceGamepje) : Scene(engine), referenceGame(referenceGamepje) {};
    //GameScreen(std::shared_ptr<GBAEngine> engine, Game referenceGamepje) : Scene(engine), game(referenceGamepje) {};
    //GameScreen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamePointertje) : Scene(engine) {gamePointer = gamePointertje;};

    //GameScreen(std::shared_ptr<GBAEngine> engine, Game referenceGamepje) : Scene(engine) {game = referenceGamepje;}; //Kopiëren we dat hier nu? Kan dat de bedoeling zijn?
    void load() override;
    void tick(u16 keys) override;

    //void updateSpeler1(); //Dit misschien terug toevoegen als ik bewegende sprite heb?
    void updatePosition();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GAMESCREEN_H
