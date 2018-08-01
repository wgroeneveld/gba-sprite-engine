//
// Created by Wouter Groeneveld on 27/07/18.
//

#include <engine/gba/tonc_core.h>
#include "palette_manager.h"

void PaletteManager::persist() {
    dma3_cpy(this->palletteAddress(), this->data, this->size);
}
