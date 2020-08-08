//
// Created by michi on 14/04/2020.
//
#include <algorithm>
#include "Speler.h"
#include <ctime>
#include <random>
#include <iostream>
#include <libgba-sprite-engine/gba_engine.h>

Speler::Speler() {
    score = 0;
    posX = 3;
    posY = 3;
    vakjesNogVerschuiven = 0;
    alGegooid = false;
    magNaarRechts = true;
    magNaarLinks = true;
    magNaarBoven = true;
    magNaarOnder = true;
    //tijd = 3;
}

int Speler::getScore() {
    return score;
}

void Speler::setScore(int extraScore) {
    score += extraScore;
}

void Speler::beweegNaarRechts() {
    if ((posY == 0 or posY == 3 or posY == 6) and posX != 6 and vakjesNogVerschuiven != 0 and magNaarRechts) {
        posX++;
        vakjesNogVerschuiven--;
        magNaarLinks = false;
        magNaarBoven = true;
        magNaarOnder = true;
    }
}

void Speler::beweegNaarLinks() {
    if ((posY == 0 or posY == 3 or posY == 6) and posX != 0 and vakjesNogVerschuiven != 0 and magNaarLinks) {
        posX--;
        vakjesNogVerschuiven--;
        magNaarRechts = false;
        magNaarBoven = true;
        magNaarOnder = true;
    }
}

void Speler::beweegNaarOnder() {
    if ((posX == 0 or posX == 3 or posX == 6) and posY != 6 and vakjesNogVerschuiven != 0 and magNaarOnder) {
        posY++;
        vakjesNogVerschuiven--;
        magNaarBoven = false;
        magNaarRechts = true;
        magNaarLinks = true;
    }
}

void Speler::beweegNaarBoven() {
    if ((posX == 0 or posX == 3 or posX == 6) and posY != 0 and vakjesNogVerschuiven != 0 and magNaarBoven) {
        posY--;
        vakjesNogVerschuiven--;
        magNaarOnder = false;
        magNaarRechts = true;
        magNaarLinks = true;
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

void Speler::gooiDobbelsteen(int seed) {
    if (!alGegooid or alGegooid) {

        std::uniform_int_distribution<unsigned> u(1,3);
        std::default_random_engine e(seed*seed); //anders kwam je denk ik te vaak op hetzelfde. Nog eens fatsoenlijk uitzoeken hoe dit zit.
        vakjesNogVerschuiven = u(e);

        //tijd = timer.getSecs();
        //vakjesNogVerschuiven = 1 + (rand() % 3);
        alGegooid = true;
        magNaarBoven = true;
        magNaarOnder = true;
        magNaarLinks = true;
        magNaarRechts = true;
    }

}

int Speler::getVakjesNogVerschuiven() {
    return vakjesNogVerschuiven;
}

void Speler::springNaarRechts() {
    posX = posX + 3;
}

void Speler::springNaarLinks() {
    posX = posX - 3;
}

void Speler::springNaarOnder() {
    posY = posY + 3;
}

void Speler::springNaarBoven() {
    posY = posY - 3;
}
/*
void Speler::setMagNaarOnder(bool nietNaarBovenGeweest) {
    magNaarOnder = nietNaarBovenGeweest;
}

void Speler::setMagNaarBoven(bool nietNaarOnderGeweest) {
    magNaarBoven = nietNaarOnderGeweest;
}

void Speler::setMagNaarLinks(bool nietNaarRechtsGeweest) {
    magNaarLinks = nietNaarRechtsGeweest;
}

void Speler::setMagNaarRechts(bool nietNaarLinksGeweest) {
    magNaarRechts = nietNaarLinksGeweest;
}*/
/*
void Speler::startTimer() {
    timer.start();
}

int Speler::getTijd() {
    return tijd;
}
*/




