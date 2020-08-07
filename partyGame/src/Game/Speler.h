//
// Created by michi on 14/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SPELER_H
#define GBA_SPRITE_ENGINE_PROJECT_SPELER_H


#include <ctime>
#include <libgba-sprite-engine/timer.h>

class Speler {
private:
    int score;
    int posX;
    int posY;
    int vakjesNogVerschuiven;
    bool alGegooid;

    bool magNaarLinks;
    bool magNaarRechts;
    bool magNaarBoven;
    bool magNaarOnder;
    //Timer timer;
    //int tijd;


public:
    Speler();
    int getScore();
    void setScore(int extraScore);
    int getPosX();
    int getPosY();
    void beweegNaarRechts();
    void beweegNaarLinks();
    void beweegNaarOnder();
    void beweegNaarBoven();
    void springNaarRechts();
    void springNaarLinks();
    void springNaarOnder();
    void springNaarBoven();

    void setAlGegooid(bool gegooid);
    bool getAlGegooid();
    void gooiDobbelsteen(int seed);
    int getVakjesNogVerschuiven();

    //void setMagNaarOnder(bool nietNaarBovenGeweest);
    //void setMagNaarBoven (bool nietNaarOnderGeweest);
    //void setMagNaarLinks (bool nietNaarRechtsGeweest);
    //void setMagNaarRechts (bool nietNaarLinksGeweest);

    //void startTimer();
    //int getTijd();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SPELER_H
