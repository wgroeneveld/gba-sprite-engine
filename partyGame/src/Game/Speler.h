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
    int vakjesNogVerschuiven;
    bool alGegooid;


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

    void setAlGegooid(bool gegooid);
    bool getAlGegooid();
    void gooiDobbelsteen();
    int getVakjesNogVerschuiven();


};


#endif //GBA_SPRITE_ENGINE_PROJECT_SPELER_H
