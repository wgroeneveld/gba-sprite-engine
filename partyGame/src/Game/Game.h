//
// Created by michi on 14/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAME_H
#define GBA_SPRITE_ENGINE_PROJECT_GAME_H


#include <memory>
#include "Speler.h"
#include "../Minigames/Minigame1.h"
#include "../Minigames/Minigame2.h"
#include "../Minigames/Minigame3.h"

class Game {
private:
    int bord[7][7] = {{1, 7, 7, 5, 7, 7, 7}, //bord is rijen en kolommen omgedraaid :)
                     {7, 0, 0, 7, 0, 0, 7},
                     {7, 0, 0, 7, 0, 0, 7},
                     {4, 7, 7, 6, 7, 7, 4},
                     {7, 0, 0, 7, 0, 0, 7},
                     {7, 0, 0, 7, 0, 0, 7},
                     {2, 7, 7, 5, 7, 7, 3}};;

    std::shared_ptr<Speler> speler = std::make_shared<Speler>(Speler());

public:
    Game();
    int getHuidigVakje();
    std::shared_ptr<Speler> getSpeler();

};


#endif //GBA_SPRITE_ENGINE_PROJECT_GAME_H
