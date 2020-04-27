//
// Created by michi on 14/04/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BORD_H
#define GBA_SPRITE_ENGINE_PROJECT_BORD_H

#include "Vakje.h"

class Bord {
private:
    Vakje *vakjes[20];
public:
    Bord();
    Vakje* getVakje(int nummer);

};


#endif //GBA_SPRITE_ENGINE_PROJECT_BORD_H
