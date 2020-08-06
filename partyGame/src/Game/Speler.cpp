//
// Created by michi on 14/04/2020.
//
#include <algorithm>
#include "Speler.h"

Speler::Speler() {
    score = 0;
    posX = 3;
    posY = 3;
    vakjesNogVerschuiven = 0;
    alGegooid = false;
}

int Speler::getScore() {
    return score;
}

void Speler::setScore(int extraScore) {
    score += extraScore;
}

void Speler::beweegNaarRechts() {
    if ((posY == 0 or posY == 3 or posY == 6) and posX != 6 and vakjesNogVerschuiven != 0) {
        posX++;
        vakjesNogVerschuiven--;
    }
}

void Speler::beweegNaarLinks() {
    if ((posY == 0 or posY == 3 or posY == 6) and posX != 0 and vakjesNogVerschuiven != 0) {
        posX--;
        vakjesNogVerschuiven--;
    }
}

void Speler::beweegnaarOnder() {
    if ((posX == 0 or posX == 3 or posX == 6) and posY != 6 and vakjesNogVerschuiven != 0) {
        posY++;
        vakjesNogVerschuiven--;
    }
}

void Speler::beweegNaarBoven() {
    if ((posX == 0 or posX == 3 or posX == 6) and posY != 0 and vakjesNogVerschuiven != 0) {
        posY--;
        vakjesNogVerschuiven--;
    }
}

int Speler::getPosX() {
    return posX;
}

int Speler::getPosY() {
    return posY;
}

void Speler::setAlGegooid(bool gegooid) {
    alGegooid = gegooid;
}

bool Speler::getAlGegooid() {
    return alGegooid;
}

void Speler::gooiDobbelsteen() {
    if (!alGegooid) {
        vakjesNogVerschuiven = 1 + (rand() % 3);
        alGegooid = true;
    }

}

int Speler::getVakjesNogVerschuiven() {
    return vakjesNogVerschuiven;
}





