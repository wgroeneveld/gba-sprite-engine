//
// Created by michi on 15/07/2020.
//

#include "Minigame2.h"
#include <algorithm>

Minigame2::Minigame2() : Minigame() {
    posX = 0;
    posY = 64;
    minScore = 80;
    rechts = true;
    snelheid = 2;
}

void Minigame2::beweeg() { //beweegsnelheid aanpassen adhv getal
    if (rechts) {posX += snelheid;}
    else {posX -= snelheid;}
    if (posX == 0 or posX == 208) {rechts = !rechts;}
}

void Minigame2::berekenScore() {
    score = 104-(std::abs(104-posX));
}

void Minigame2::berekenGehaald() {
    gehaald = (score >= minScore);
}
