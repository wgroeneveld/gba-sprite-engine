//
// Created by michi on 28/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINIGAME1_H
#define GBA_SPRITE_ENGINE_PROJECT_MINIGAME1_H


#include <libgba-sprite-engine/gba_engine.h>
#include "VallendVoorwerp.h"

class Minigame1 {
private:
    int positieMannetjeX;
    int positieMannetjeY; // Maak ik hier best static van ofzo?
    VallendVoorwerp* voorwerpen[4];
    int score;
    int beginTijd;
public:

    //Minigame1(std::shared_ptr<GBAEngine> engine);
    Minigame1(std::shared_ptr<GBAEngine> engine);
    int getPositieMannetjeX();
    int getPositieMannetjeY();
    void beweegMannetje(int x);
    VallendVoorwerp getVoorwerp(int nummer);
    int getScore;
    void MannetjeVangt();
    void spelGedaan(); //timer implementeren

};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINIGAME1_H
