//
// Created by woute on 21/11/2019.
//

#ifndef LABO9_BASEBGLAYER_H
#define LABO9_BASEBGLAYER_H


#include "Palette.h"

class BaseBGLayer {
private:
    int scrollX, scrollY;
    unsigned short tileset[256]; // (komt uit tile generator)
    unsigned short tilemap[256]; //(komt uit tile generator)
    Palette palette;
    unsigned short address;

public:
    virtual void scroll(int x, int y);



};


#endif //LABO9_BASEBGLAYER_H
