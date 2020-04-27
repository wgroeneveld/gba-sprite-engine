//
// Created by michi on 14/04/2020.
//

#include "Bord.h"

Bord::Bord() {
    vakjes[0] = new Vakje(1);
    vakjes[1] = new Vakje(2);
    vakjes[2] = new Vakje(3);
    vakjes[3] = new Vakje(1);
    vakjes[4] = new Vakje(2);
    vakjes[5] = new Vakje(3);
    vakjes[6] = new Vakje(1);
    vakjes[7] = new Vakje(2);
    vakjes[8] = new Vakje(3);
    vakjes[9] = new Vakje(1);
    vakjes[10] = new Vakje(2);
    vakjes[11] = new Vakje(3);
    vakjes[12] = new Vakje(1);
    vakjes[13] = new Vakje(2);
    vakjes[14] = new Vakje(3);
    vakjes[15] = new Vakje(1);
    vakjes[16] = new Vakje(2);
    vakjes[17] = new Vakje(3);
    vakjes[18] = new Vakje(1);
    vakjes[19] = new Vakje(2);

}

Vakje* Bord::getVakje(int nummer) {
    return vakjes[nummer];
}

