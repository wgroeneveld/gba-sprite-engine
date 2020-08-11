//
// Created by michi on 11/08/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAME1SCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAME1SCREEN_H


#include "MinigameScreen.h"

class Minigame1Screen : public MinigameScreen {

public:
    Minigame1Screen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje, int sprite);
    void load() override;
    void setGehaald() override;
    void setBegintekst() override;
    void setEindtekst() override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAME1SCREEN_H
