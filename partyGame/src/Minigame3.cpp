//
// Created by michi on 10/08/2020.
//

#include "Minigame3.h"

Minigame3::Minigame3() : Minigame() {
    posX = 24;
    posY = 10;
    minScore = 80;
    onder = true;
    rechts = true;
}

void Minigame3::beweeg() {
    if (onder) {
        posY++;
        if (posY == 128) {onder = false;};
    }
    else {
        if (rechts) {
            posY--;
            posX++;
        }
        else {
            posY--;
            posX--;
        }
        if (posY == 0) {
            onder = true;
            rechts = !rechts;
        }

    }
}

void Minigame3::berekenScore() {
    score = 100;
}


