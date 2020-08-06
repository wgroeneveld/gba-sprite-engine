//
// Created by michi on 14/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SPELER_H
#define GBA_SPRITE_ENGINE_PROJECT_SPELER_H


class Speler {
private:
    int score;
    int posX;
    int posY;


public:
    Speler();
    int getScore();
    void setScore(int extraScore);
    int getPosX();
    int getPosY();
    void beweegNaarRechts();
    void beweegNaarLinks();
    void beweegnaarOnder();
    void beweegNaarBoven();


};


#endif //GBA_SPRITE_ENGINE_PROJECT_SPELER_H
