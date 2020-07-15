//
// Created by michi on 14/04/2020.
//

#include <algorithm>
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
    bord = new Bord;
    speler1X = 3;
    speler1Y = 3;
}

Bord *Game::getBord() {
    return bord;
}

void Game::beweegSpelerNaarRechts() {
    if ((speler1Y == 0 or speler1Y == 3 or speler1Y == 6) and speler1X != 6) {
        speler1X++;
    }
    //speler1X = std::min(speler1X+1, 8);
}

void Game::beweegSpelerNaarLinks() {
    if ((speler1Y == 0 or speler1Y == 3 or speler1Y == 6) and speler1X != 0) {
        speler1X--;
    }
    //speler1X = std::max(speler1X-1, 0);
}
void Game::beweegSpelerNaarBoven() {
    if ((speler1X == 0 or speler1X == 3 or speler1X == 6) and speler1Y != 0) {
        speler1Y--;
    }
    //speler1Y = std::max(speler1Y-1, 0);
}
void Game::beweegSpelerNaarOnder() {
    if ((speler1X == 0 or speler1X == 3 or speler1X == 6) and speler1Y != 6) {
        speler1Y++;
    }
    //speler1Y = std::min(speler1Y+1, 8);
}

int Game::getSpeler1X() {
    return speler1X;
}

int Game::getSpeler1Y() {
    return speler1Y;
}