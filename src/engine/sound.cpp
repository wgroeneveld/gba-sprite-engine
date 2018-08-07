//
// Created by Wouter Groeneveld on 07/08/18.
//

#include <engine/gba/tonc_memmap.h>
#include "sound.h"

void SoundControl::accept(const void *data, int totalSamples, int ticksPerSample)  {
    *DMASourceAddress = (u32) data;
    *DMADestinationAddress = (u32) FiFoBuffer;
    vblanksTotal = vblanksRemaning = totalSamples * ticksPerSample * (1.0 / CYCLES_PER_BLANK);
};

SoundControl* SoundControl::channelAControl() {
    return new SoundControl{
            &REG_DMA1CNT,
            &REG_DMA1SAD,
            &REG_DMA1DAD,
            &REG_FIFOA,
            SDS_AR | SDS_AL | SDS_ARESET
    };
}

SoundControl* SoundControl::channelBControl() {
    return new SoundControl{
            &REG_DMA2CNT,
            &REG_DMA2SAD,
            &REG_DMA2DAD,
            &REG_FIFOB,
            SDS_BR | SDS_BL | SDS_BRESET
    };
}
