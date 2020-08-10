//
// Created by michi on 15/07/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAME2_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAME2_H


#include "../Minigame.h"

class Minigame2 : public Minigame {
private:
    bool rechts;
public:
    Minigame2();
    void beweeg() override;
    void berekenScore() override;
    //void wisselRichting();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAME2_H
