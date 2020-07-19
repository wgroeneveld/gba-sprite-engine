//
// Created by michi on 14/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAME_H
#define GBA_SPRITE_ENGINE_PROJECT_GAME_H

#include "Bord.h"
#include "Speler.h"

class Game {
private:
    //Speler *spelerAanZet;
    //Speler *speler1;
    //Speler *spelerAI;
   // Bord *bord;
    int bord[7][7] = {{0, 0, 0, 0, 0, 0, 1}, //Waarom kan die niet in de .cpp?
                      {0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0},
                      {1, 0, 0, 0, 0, 0, 0}};


    int speler1X;
    int speler1Y;
    bool minigame1Gehaald;
    bool minigame2Gehaald;
    bool minigame3Gehaald;
    int score;


public:
    Game();
    Game(int posX, int posY, int score, bool game1Gehaald, bool game2Gehaald, bool game3Gehaald);
    //Speler* getSpeler1();
    //Speler* getSpelerAI();
    //Speler* getSelectedPlayer();
    //void switchSelectedPlayer();
    void beweegSpelerNaarRechts();
    void beweegSpelerNaarLinks();
    void beweegSpelerNaarBoven();
    void beweegSpelerNaarOnder();
    int getSpeler1X();
    int getSpeler1Y();
    //Bord* getBord();
    bool getMinigame2Gehaald();
    void setMinigame2Gehaald(bool gehaald);
    int getScore();
    void setScore(int getal);
    int getVakje(int X, int Y);
    int getHuidigVakje();



};


#endif //GBA_SPRITE_ENGINE_PROJECT_GAME_H
