//
// Created by michi on 10/08/2020.
//

#include "Minigame3.h"
#include <algorithm>

Minigame3::Minigame3() : Minigame() {
    posX = 40;
    posY = 10;
    onder = true;
    rechts = true;
    snelheid = 1;

    posBoxX = 104;
    posBoxY = 64;
}

void Minigame3::beweeg() {
    if (onder) {
        posY = posY + snelheid;
        if (posY >= 128) {onder = false;};
    }
    else {
        if (rechts) {
            posY = posY - snelheid;
            posX = posX + snelheid;
        }
        else {
            posY = posY - snelheid;
            posX = posX - snelheid;
        }
        if (posY <= 0) {
            onder = true;
            rechts = !rechts;
        }
    }
}

void Minigame3::berekenScore() {
    score = posBoxX - (std::abs(posBoxX-posX));
    score = posBoxY - (std::abs(posBoxY-posY));
}

void Minigame3::berekenGehaald() {
    gehaald = (posX >= (posBoxX - 15) and posX <= (posBoxX + 15) and posBoxY >= (posY -15) and posBoxY <= (posBoxY + 15));
}