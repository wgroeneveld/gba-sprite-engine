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
}


void Minigame2::beweeg() { //beweegsnelheid aanpassen adhv getal
    if (rechts) {posX += 2;}
    else {posX -= 2;}
    if (posX == 0 or posX == 208) {wisselRichting();}
}

void Minigame2::wisselRichting() {
    rechts = !rechts;
}

void Minigame2::berekenScore() {
    int positie = posX; //Checken of ik deze tussenstap eigenlijk wel moet doen.
    score = 104-(std::abs(104-positie));
}
