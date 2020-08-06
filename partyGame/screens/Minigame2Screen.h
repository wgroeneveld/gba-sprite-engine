//
// Created by michi on 15/07/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAME2SCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAME2SCREEN_H


#include <libgba-sprite-engine/scene.h>
#include "../src/Minigame2/Minigame2.h"
#include "../src/Game/Game.h"


class Minigame2Screen : public Scene {
private:
    //Game *game;
    //Game game;
    //Game &referenceGame = game;
    //Game &referenceGame;
    //Game game;
    std::shared_ptr<Game> game;
    //Game &game;
    Minigame2 minigame;
    std::unique_ptr<Sprite> ufo;
    u16 lastKeys = 0;
    bool firstTick = true;
    std::unique_ptr<Background> background;
    bool bezig = true;

    bool game1Gehaald;
    bool game2Gehaald;
    bool game3gehaald;
    int posX;
    int posY;
    int spelscore;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    //Minigame2Screen(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}; //Kijken of ik hier &engine ofzo moet doen
    //Minigame2Screen(std::shared_ptr<GBAEngine> engine, Game referenceGamepje) : Scene(engine), referenceGame(referenceGamepje){};
    //Minigame2Screen(std::shared_ptr<GBAEngine> engine, Game referenceGamepje) : Scene(engine), game(referenceGamepje){};
    //Minigame2Screen(std::shared_ptr<GBAEngine> engine, Game &referenceGamepje)
           // : Scene(engine), referenceGame(referenceGamepje) {};
    //Minigame2Screen(std::shared_ptr<GBAEngine> engine, Game gamepje) : Scene(engine) {game = gamepje;};

    //Minigame2Screen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamePointertje) : Scene(engine) {gamePointer = gamePointertje;};
    Minigame2Screen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje) : Scene(engine), game(gamepje){};
    void load() override;
    void tick(u16 keys) override;

    void updatePosition();
    void endScene();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAME2SCREEN_H
