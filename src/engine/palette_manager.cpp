//
// Created by Wouter Groeneveld on 27/07/18.
//

#include <engine/gba/tonc_core.h>
#include "palette_manager.h"

void PaletteManager::persist() {
    dma3_cpy(this->paletteAddress(), this->data, this->size);
}

COLOR PaletteManager::change(int bank, int index, COLOR newColor) {
    auto palBank = this->paletteBank();
    COLOR oldColor = palBank[bank][index];
    palBank[bank][index] = newColor;
    return oldColor;
}

COLOR PaletteManager::color(u32 red, u32 green, u32 blue) {
    return red | (green<<5) | (blue<<10);
}

void PaletteManager::persistToBank(int bank) {
    auto palBank = this->paletteBank();
    dma3_cpy(palBank[bank], this->data, PALETTE_BANK_SIZE);
}