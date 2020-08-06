//
// Created by michi on 14/04/2020.
//

#include "Speler.h"

Speler::Speler() {
    score = 0;
    posX = 3;
    posY = 3;
}

int Speler::getScore() {
    return score;
}

void Speler::setScore(int extraScore) {
    score += extraScore;
}

void Speler::beweegNaarRechts() {
    if ((posY == 0 or posY == 3 or posY == 6) and posX != 6) {
        posX++;
    }
}

void Speler::beweegNaarLinks() {
    if ((posY == 0 or posY == 3 or posY == 6) and posX != 0) {
        posX--;
    }
}

void Speler::beweegnaarOnder() {
    if ((posX == 0 or posX == 3 or posX == 6) and posY != 6) {
        posY++;
    }
}

void Speler::beweegNaarBoven() {
    if ((posX == 0 or posX == 3 or posX == 6) and posY != 0) {
        posY--;
    }
}

int Speler::getPosX() {
    return posX;
}

int Speler::getPosY() {
    return posY;
}




