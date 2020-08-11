//
// Created by michi on 11/08/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAME3SCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAME3SCREEN_H


#include "MinigameScreen.h"

class Minigame3Screen : public MinigameScreen {
public:
    Minigame3Screen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje, int sprite);
    void load() override;
    void zegIets() override;
    void setGehaald() override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAME3SCREEN_H
