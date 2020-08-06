//
// Created by michi on 14/04/2020.
//

#include <algorithm>
#include "Game.h"

Game::Game() {

}

std::shared_ptr<Speler> Game::getSpeler() { //Moet dit een pointer worden?
    return speler;
}

/*
Speler Game::getSpeler() {
    return speler;
}
 */
int Game::getHuidigVakje() {
    //Speler blub = getSpeler();
    //return bord[getSpeler().getPosX()][getSpeler().getPosY()];
    return bord[getSpeler()->getPosX()][getSpeler()->getPosY()];
}


