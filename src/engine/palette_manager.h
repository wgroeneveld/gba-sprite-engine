//
// Created by Wouter Groeneveld on 27/07/18.
//

#ifndef GBA_SPRITE_ENGINE_PALETTE_MANAGER_H
#define GBA_SPRITE_ENGINE_PALETTE_MANAGER_H

#include <engine/gba/tonc_memmap.h>
#include <engine/gba/tonc_types.h>

#define PALETTE_BANK_SIZE 16
#define PALETTE_MAX_SIZE 256

int getBits(int number, int k, int p);

class PaletteManager {
protected:
    const u16 *data;
    int size;

    virtual void* paletteAddress() = 0;
    virtual PALBANK* paletteBank() = 0;
public:
    PaletteManager(const u16 paletteData[]) : data(paletteData), size(PALETTE_MAX_SIZE) {}
    PaletteManager(const u16 paletteData[], int size) : data(paletteData), size(size) {}

    void persist();
    void persistToBank(int bank);
    COLOR change(int bank, int index, COLOR newColor);
    void increaseBrightness(u32 intensity);

    static COLOR color(u32 r, u32 g, u32 b);
    static u32 red(COLOR r);
    static u32 green(COLOR r);
    static u32 blue(COLOR r);
};

class BackgroundPaletteManager : public PaletteManager {
protected:
    void *paletteAddress() override {
        return pal_bg_mem;
    }

    PALBANK *paletteBank() override {
        return pal_bg_bank;
    }

public:
    BackgroundPaletteManager() : PaletteManager(nullptr) {}
    BackgroundPaletteManager(const u16 paletteData[]) : PaletteManager(paletteData) {}
    BackgroundPaletteManager(const u16 paletteData[], int size) : PaletteManager(paletteData, size) {}
};


class ForegroundPaletteManager : public PaletteManager {
protected:
    void *paletteAddress() override {
        return pal_obj_mem;
    }

    PALBANK *paletteBank() override {
        return pal_obj_bank;
    }

public:
    ForegroundPaletteManager(const u16 paletteData[]) : PaletteManager(paletteData) {}
    ForegroundPaletteManager(const u16 paletteData[], int size) : PaletteManager(paletteData, size) {}
};

#endif //GBA_SPRITE_ENGINE_PALETTE_MANAGER_H
