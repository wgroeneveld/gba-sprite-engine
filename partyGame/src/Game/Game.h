//
// Created by michi on 14/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAME_H
#define GBA_SPRITE_ENGINE_PROJECT_GAME_H


#include <memory>
#include "Speler.h"

class Game {
private:
    int bord[7][7] = {{0, 0, 0, 0, 0, 0, 1},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0}};;

    std::shared_ptr<Speler> speler = std::make_shared<Speler>(Speler());
    //Speler speler;


public:
    Game();
    int getHuidigVakje();
    std::shared_ptr<Speler> getSpeler();
    //Speler getSpeler();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GAME_H
