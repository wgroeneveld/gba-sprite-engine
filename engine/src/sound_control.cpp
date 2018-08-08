//
// Created by Wouter Groeneveld on 07/08/18.
//

#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/sound_control.h>

void SoundControl::accept(const void *data, int totalSamples, int ticksPerSample)  {
    this->data = data;
    *DMASourceAddress = (u32) data;
    *DMADestinationAddress = (u32) FiFoBuffer;
    vblanksTotal = vblanksRemaning = totalSamples * ticksPerSample * (1.0 / CYCLES_PER_BLANK);
};

void SoundControl::reset() {
    vblanksRemaning = vblanksTotal;
    *(DMAControl) = 0;
    *DMASourceAddress = (u32) data;
    enable();
}

std::unique_ptr<SoundControl> SoundControl::channelAControl() {
    return std::unique_ptr<SoundControl>(new SoundControl{
            &REG_DMA1CNT,
            &REG_DMA1SAD,
            &REG_DMA1DAD,
            &REG_FIFOA,
            // Left/Right, timed, tone 100% vol, channel A 50%, channel B 100% (only one directsound reg)
            SDS_AR | SDS_AL | SDS_ARESET | SDS_DMG100 | SDS_A50 | SDS_B100
    });
}

std::unique_ptr<SoundControl> SoundControl::channelBControl() {
    return std::unique_ptr<SoundControl>(new SoundControl{
            &REG_DMA2CNT,
            &REG_DMA2SAD,
            &REG_DMA2DAD,
            &REG_FIFOB,
            // Left/Right, timed, tone 100% vol, channel A 50%, channel B 100% (only one directsound reg)
            SDS_BR | SDS_BL | SDS_BRESET | SDS_DMG100 | SDS_A50 | SDS_B100
    });
}
