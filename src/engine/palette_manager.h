//
// Created by Wouter Groeneveld on 27/07/18.
//

#ifndef GBA_SPRITE_ENGINE_PALETTE_MANAGER_H
#define GBA_SPRITE_ENGINE_PALETTE_MANAGER_H


#include <engine/gba/tonc_types.h>

#define PALETTE_BANK_SIZE 16
#define PALETTE_MAX_SIZE 256


class PaletteManager {
protected:
    const u16 *data;
    int size;

    virtual void* palletteAddress() = 0;
public:
    PaletteManager(const u16 paletteData[]) : data(paletteData), size(PALETTE_MAX_SIZE) {}
    PaletteManager(const u16 paletteData[], int size) : data(paletteData), size(size) {}

    void persist();
};

class BackgroundPaletteManager : public PaletteManager {
protected:
    void *palletteAddress() override {
        return pal_bg_mem;
    }
public:
    BackgroundPaletteManager(const u16 paletteData[]) : PaletteManager(paletteData) {}
    BackgroundPaletteManager(const u16 paletteData[], int size) : PaletteManager(paletteData, size) {}
};


class ForegroundPaletteManager : public PaletteManager {
protected:
    void *palletteAddress() override {
        return pal_obj_mem;
    }
public:
    ForegroundPaletteManager(const u16 paletteData[]) : PaletteManager(paletteData) {}
    ForegroundPaletteManager(const u16 paletteData[], int size) : PaletteManager(paletteData, size) {}
};

#endif //GBA_SPRITE_ENGINE_PALETTE_MANAGER_H
