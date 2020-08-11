//
// Created by michi on 10/08/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAME3_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAME3_H


#include "Minigame.h"

class Minigame3 : public Minigame {
    bool rechts;
    bool onder;
public:
    Minigame3();
    void berekenScore() override;
    void beweeg() override;
    void berekenGehaald() override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAME3_H
