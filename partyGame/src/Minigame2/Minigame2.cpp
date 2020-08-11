//
// Created by michi on 15/07/2020.
//

#include "Minigame2.h"
#include <algorithm>

Minigame2::Minigame2() : Minigame() {
    posX = 0;
    posY = 64;
    //minScore = 80;
    rechts = true;
    snelheid = 1;

    posBoxX = 104;
    posBoxY = 64;
}

void Minigame2::beweeg() { //beweegsnelheid aanpassen adhv getal
    if (rechts) {posX += snelheid;}
    else {posX -= snelheid;}
    if (posX == 0 or posX == 208) {rechts = !rechts;}
}

void Minigame2::berekenScore() {
    score = posBoxX-(std::abs(posBoxX-posX));
}

void Minigame2::berekenGehaald() {
    gehaald = (posX >= 98 and posX <= 110);
}
