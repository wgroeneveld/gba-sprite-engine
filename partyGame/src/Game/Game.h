//
// Created by michi on 14/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAME_H
#define GBA_SPRITE_ENGINE_PROJECT_GAME_H


#include <memory>
#include "Speler.h"

class Game {
private:
    int bord[7][7] = {{2, 1, 1, 4, 1, 1, 2}, //bord is rijen en kolommen omgedraaid :)
                     {1, 0, 0, 1, 0, 0, 1},
                     {1, 0, 0, 1, 0, 0, 1},
                     {3, 1, 1, 1, 1, 1, 3},
                     {1, 0, 0, 1, 0, 0, 1},
                     {1, 0, 0, 1, 0, 0, 1},
                     {2, 1, 1, 4, 1, 1, 2}};;

    std::shared_ptr<Speler> speler = std::make_shared<Speler>(Speler());

public:
    Game();
    int getHuidigVakje();
    std::shared_ptr<Speler> getSpeler();

};


#endif //GBA_SPRITE_ENGINE_PROJECT_GAME_H
