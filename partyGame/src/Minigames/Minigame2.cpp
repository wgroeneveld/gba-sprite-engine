//
// Created by michi on 15/07/2020.
//

#include "Minigame2.h"
#include <algorithm>

Minigame2::Minigame2() : Minigame() {
    posBoxX = 104;
    posBoxY = 64;
    posX = 0;
    posY = 64;
    snelheid = 1;

    rechts = true;
}

void Minigame2::beweeg() {
    if (rechts) {posX += snelheid;}
    else {posX -= snelheid;}
    if (posX == 0 or posX == 208) {rechts = !rechts;}
}

void Minigame2::berekenScore() {
    score = posBoxX-(std::abs(posBoxX-posX));
}

void Minigame2::berekenGehaald() {
    gehaald = (posX >= (posBoxX - 6) and posX <= (posBoxX + 6));
}
