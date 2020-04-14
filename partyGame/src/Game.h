//
// Created by michi on 14/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAME_H
#define GBA_SPRITE_ENGINE_PROJECT_GAME_H

#include "Bord.h"
#include "Speler.h"

class Game {
private:
    Speler *spelerAanZet;
    Speler *speler1;
    Speler *spelerAI;
    Bord bord;
    int speler1PositieX;
    int speler1PositieY;
    int spelerAIPositieX;
    int spelerAIpositieY;

public:
    Game();
    Speler* getSpeler1();
    Speler* getSpelerAI();
    Speler* getSelectedPlayer();
    void switchSelectedPlayer();



};


#endif //GBA_SPRITE_ENGINE_PROJECT_GAME_H
