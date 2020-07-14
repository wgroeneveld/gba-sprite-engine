//
// Created by michi on 28/04/2020.
//

#include "Minigame1.h"
#include <libgba-sprite-engine/gba_engine.h>


Minigame1::Minigame1(std::shared_ptr<GBAEngine> engine) {
    score = 0;
    positieMannetjeX = 120;
    positieMannetjeY = 230;
    voorwerpen[0] = new VallendVoorwerp(false);
    voorwerpen[1] = new VallendVoorwerp(false);
    voorwerpen[2] = new VallendVoorwerp(false);
    voorwerpen[3] = new VallendVoorwerp(false);
    beginTijd = engine.get()->getTimer()->getSecs();
}

