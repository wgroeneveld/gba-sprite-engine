//
// Created by Wouter Groeneveld on 05/08/18.
//


#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/palette/palette_manager.h>

void CombinedPalette::increaseBrightness(PaletteManager& palette, int bank, int index, u32 intensity) {
    auto current = palette.get(bank, index);
    auto next = PaletteManager::modify(current, intensity);

    palette.change(bank, index, next);
}

void CombinedPalette::increaseBrightness(u32 intensity) {
    if(intensity > 31) {
        failure_gba(Brightness_Intensity_Too_High);
        return;
    }

    for(int bank = 0; bank < PALETTE_BANK_SIZE; bank++) {
        for(int index = 0; index < PALETTE_BANK_SIZE; index++) {
            increaseBrightness(palette1, bank, index, intensity);
            increaseBrightness(palette2, bank, index, intensity);
        }
    }
}