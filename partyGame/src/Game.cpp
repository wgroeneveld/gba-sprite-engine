//
// Created by michi on 14/04/2020.
//

#include "Game.h"



Speler* Game::getSpeler1() {
    return speler1;
}

Speler* Game::getSpelerAI() {
    return spelerAI;
}

Speler* Game::getSelectedPlayer() {
    return spelerAanZet;
}

void Game::switchSelectedPlayer() {
    if (spelerAanZet == speler1) {
        spelerAanZet = spelerAI;
    }
    else {
        spelerAanZet = speler1;
    }
}

Game::Game() {
    speler1 = new Speler;
    spelerAI = new Speler;
    spelerAanZet = speler1;
}
