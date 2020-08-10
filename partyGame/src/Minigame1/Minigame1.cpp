//
// Created by michi on 28/04/2020.
//

#include "Minigame1.h"
#include <libgba-sprite-engine/gba_engine.h>



Minigame1::Minigame1() : Minigame() {
    posX = 64;
    posY = 0;
    minScore = 80;
    onder = true;
    snelheid = 2;
}


void Minigame1::beweeg() { //beweegsnelheid aanpassen adhv getal
    if (onder) {posY += snelheid;}
    else {posY -= snelheid;}
    if (posY == 0 or posY == 128) {onder = !onder;}
}


void Minigame1::berekenScore() {
    //int positie = posX; //Checken of ik deze tussenstap eigenlijk wel moet doen.
    //score = 104-(std::abs(104-positie));
    score = 90;
}
