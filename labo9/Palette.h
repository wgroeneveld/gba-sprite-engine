//
// Created by woute on 21/11/2019.
//

#ifndef LABO9_PALETTE_H
#define LABO9_PALETTE_H


class Palette {
private:
    unsigned short data[256];
public:
    unsigned short getData();
    void setData(unsigned short data[256]);
};


#endif //LABO9_PALETTE_H
