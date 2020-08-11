//
// Created by michi on 28/04/2020.
//

#include "Minigame1.h"
#include <libgba-sprite-engine/gba_engine.h>



Minigame1::Minigame1() : Minigame() {
    posX = 104;
    posY = 0;
    onder = true;
    snelheid = 2;
    posBoxX = 104;
    posBoxY = 64;
}


void Minigame1::beweeg() { //beweegsnelheid aanpassen adhv getal
    if (onder) {posY += snelheid;}
    else {posY -= snelheid;}
    if (posY == 0 or posY == 128) {onder = !onder;}
}


void Minigame1::berekenScore() {
    score = posBoxY-(std::abs(posBoxY-posY));
}

void Minigame1::berekenGehaald() {

    gehaald = (posY >= 49 and posY <= 79);
}
