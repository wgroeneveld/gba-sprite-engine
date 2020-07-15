//
// Created by michi on 15/07/2020.
//

#include "Minigame2.h"
#include <algorithm>

Minigame2::Minigame2() {
    score = 0;
    positieX = 0;
    rechts = true;
}

int Minigame2::getScore() {
    return score;
}

void Minigame2::MakePicture() {
    int positie = positieX; //Checken of ik deze tussenstap eigenlijk wel moet doen.
    score = std::abs(104-positie);
}

void Minigame2::beweeg() {
    if (rechts) {
        positieX += 2;   //beweegsnelheid aanpassen adhv dit getal
    }
    else {
        positieX -= 2;
    }

    if (positieX == 0 or positieX == 208) {
        wisselRichting();
    }
}


int Minigame2::getPositieX() {
    return positieX;
}

void Minigame2::wisselRichting() {
    rechts = !rechts;
}
