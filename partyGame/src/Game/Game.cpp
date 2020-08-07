//
// Created by michi on 14/04/2020.
//

#include <algorithm>
#include "Game.h"

Game::Game() {

}

std::shared_ptr<Speler> Game::getSpeler() {
    return speler;
}

int Game::getHuidigVakje() {
    return bord[getSpeler()->getPosX()][getSpeler()->getPosY()];
}
/*
int Game::getTijd() {
    return tijd;
}
*/






