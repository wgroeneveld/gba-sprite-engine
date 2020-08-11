//
// Created by michi on 28/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAME1_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAME1_H


#include <libgba-sprite-engine/gba_engine.h>
#include "../Minigame.h"

class Minigame1 : public Minigame {
private:
    bool onder;
public:
    Minigame1();
    void beweeg() override;
    void berekenScore() override;
    void berekenGehaald() override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAME1_H
