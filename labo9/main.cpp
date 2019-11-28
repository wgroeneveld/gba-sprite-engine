#include <iostream>
#include "GBA.h"

int main() {
    GBA gba;
    int teller = 0;
    gba.init();
    while(true){
        gba.vblank();
        gba.run();
        teller++;
        if(teller == 205){
            return 1;
        }
    }
    return 0;
}