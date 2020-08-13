//
// Created by michi on 15/07/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAMESCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAMESCREEN_H


#include <libgba-sprite-engine/scene.h>
#include "../../src/Minigames/Minigame2.h"

#include "../../src/Game/Game.h"
#include "../../src/Minigames/Minigame3.h"
#include "../../src/Minigames/Minigame1.h"


class MinigameScreen : public Scene {
private:
    bool firstTick = true;
protected:
    u16 lastKeys = 0;

    std::shared_ptr<Game> game;
    std::shared_ptr<Minigame> minigame;
    std::unique_ptr<Sprite> badGuy;
    std::unique_ptr<Sprite> box;
    std::unique_ptr<Background> background;

    bool bezig = true;
    int spriteKeuze;

public:
    MinigameScreen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje, int sprite);
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override = 0;
    void tick(u16 keys) override;

    void updatePosition();
    void endScene();

    virtual void setBegintekst() = 0;
    virtual void setEindtekst() = 0;
    void removeTekst();

    virtual void setGehaald() = 0;
    void wachtEven(int tijd);

};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAMESCREEN_H
