//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_BACKGROUND_H
#define GBA_SPRITE_ENGINE_BACKGROUND_H


#include <libgba-sprite-engine/gba/tonc_types.h>

class Background {
private:
    void buildRegister();
    u32 getBgControlRegisterIndex();

protected:
    const void *data;
    const void *map;
    int size, bgIndex;
    int mapSize;
    int screenBlockIndex, charBlockIndex;

public:
    const int getScreenBlock() { return screenBlockIndex; }
    const int getCharBlock() { return charBlockIndex; }
    void useMapScreenBlock(int block) { screenBlockIndex = block; }
    void scroll(int x, int y);

    Background(int bgIndex, const void *data, int size, const void* map, int mapSize) : data(data), bgIndex(bgIndex), size(size), map(map),
                                                                       screenBlockIndex(0), charBlockIndex(0), mapSize(mapSize) {}
    virtual void persist();
    void clearMap();
};


#endif //GBA_SPRITE_ENGINE_BACKGROUND_H
