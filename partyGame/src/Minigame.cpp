//
// Created by michi on 10/08/2020.
//

#include "Minigame.h"
Minigame::Minigame() {
    score = 0;
}

int Minigame::getScore() {return score;}

int Minigame::getPosX() {return posX;}

int Minigame::getPosY() {return posY;}

bool Minigame::getGehaald() {return gehaald;}

void Minigame::makePicture() {
    berekenScore();
    berekenGehaald();
}

void Minigame::berekenGehaald() {gehaald = score > minScore;}




