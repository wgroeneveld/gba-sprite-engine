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

    bool magNaarLinks;
    bool magNaarRechts;
    bool magNaarBoven;
    bool magNaarOnder;


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

    void setMagNaarOnder(bool nietNaarBovenGeweest);
    void setMagNaarBoven (bool nietNaarOnderGeweest);
    void setMagNaarLinks (bool nietNaarRechtsGeweest);
    void setMagNaarRechts (bool nietNaarLinksGeweest);

};


#endif //GBA_SPRITE_ENGINE_PROJECT_SPELER_H
