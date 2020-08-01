//
// Created by michi on 14/04/2020.
//

#include <algorithm>
#include "Game.h"


/*
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
 */
/*
Game::Game() {
    speler1 = new Speler;
    spelerAI = new Speler;
    spelerAanZet = speler1;
    bord = new Bord;
    speler1X = 3;
    speler1Y = 3;
    minigame2Gehaald = false;
    score = 0;
}
*/
/*
Bord *Game::getBord() {
    return bord;
}
*/
void Game::beweegSpelerNaarRechts() {
    if ((speler1Y == 0 or speler1Y == 3 or speler1Y == 6) and speler1X != 6) {
        speler1X++;
    }
}

void Game::beweegSpelerNaarLinks() {
    if ((speler1Y == 0 or speler1Y == 3 or speler1Y == 6) and speler1X != 0) {
        speler1X--;
    }
}
void Game::beweegSpelerNaarBoven() {
    if ((speler1X == 0 or speler1X == 3 or speler1X == 6) and speler1Y != 0) {
        speler1Y--;
    }
}
void Game::beweegSpelerNaarOnder() {
    if ((speler1X == 0 or speler1X == 3 or speler1X == 6) and speler1Y != 6) {
        speler1Y++;
    }
}

int Game::getSpeler1X() {
    return speler1X;
}

int Game::getSpeler1Y() {
    return speler1Y;
}

bool Game::getMinigame2Gehaald() {
    return minigame2Gehaald;
}

void Game::setMinigame2Gehaald(bool gehaald) {
    minigame2Gehaald = gehaald;
}

int Game::getScore() {
    return score;
}

void Game::setScore(int getal) {
    score += getal;
}

Game::Game(int posX, int posY, int scoretje, bool game1Gehaald, bool game2Gehaald, bool game3Gehaald) {
    speler1X = posX;
    speler1Y = posY;
    score = scoretje;
    minigame1Gehaald = game1Gehaald;
    minigame2Gehaald = game2Gehaald;
    minigame3Gehaald = game3Gehaald;
}

Game::Game() {
    speler1X = 3;
    speler1Y = 3;
    score = 55;
    minigame1Gehaald = false;
    minigame2Gehaald = false;
    minigame3Gehaald = false;

}

int Game::getVakje(int x, int y) {
    return bord[x][y];
}

int Game::getHuidigVakje() {
    return bord[speler1X][speler1Y];
}


