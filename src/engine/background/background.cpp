//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <engine/gba/tonc_memmap.h>
#include <stdexcept>
#include <engine/allocator.h>
#include <engine/gba/tonc_core.h>
#include "background.h"
#include "text_stream.h"

#define TRANSPARENT_TILE_NUMBER 192     // as shown in mGBA, next "free" tile after text. Hardcoded indeed.

// WHY using this instead of Allocation?
// Because each char block seems to be 16K and there are 4 - there are also 4 backgrounds.
// Use the bgIndex as a hardcoded char block and let the background decide on the map screen block.
void* screen_block(unsigned long block) {
    return (void*) (0x6000000 + (block * 0x800));
}

void* char_block(unsigned long block) {
    return (void*) (0x6000000 + (block * 0x4000));
}

void Background::persist() {
    dma3_cpy(char_block(bgIndex), this->data, this->size);

    if(this->map) {
        dma3_cpy(screen_block(screenBlockIndex), this->map, this->mapSize);
    }

    buildRegister();
}

void Background::clearMap() {
    volatile auto ptr = &se_mem[screenBlockIndex][0];
    for (int i = 0; i < this->mapSize; i++) {
        ptr[i] = TRANSPARENT_TILE_NUMBER;
    }
}

u32 Background::getBgControlRegisterIndex() {
    switch(bgIndex) {
        case 0: return 0x0008;
        case 1: return 0x000A;
        case 2: return 0x000C;
        case 3: return 0x000E;
    }
    throw std::runtime_error("unknown bg index");
}

void Background::buildRegister() {
    *(vu16*)(REG_BASE+getBgControlRegisterIndex()) =
                 bgIndex |        /* priority, 0 is highest, 3 is lowest */
                 (bgIndex << 2) |    /* the char block the image data is stored in */
                 (0 << 6)  |       /* the mosaic flag */
                 (1 << 7)  |       /* color mode, 0 is 16 colors, 1 is 256 colors */
                 (screenBlockIndex << 8) |       /* the screen block the tile data is stored in */
                 (1 << 13) |       /* wrapping flag */
                 (0 << 14);
}

void Background::scroll(int x, int y) {
    REG_BG_OFS[bgIndex].x = x;
    REG_BG_OFS[bgIndex].y = y;
}