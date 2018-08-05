//
// Created by Wouter Groeneveld on 04/08/18.
//

#include "fade_out_scene.h"

FadeOutScene::FadeOutScene(int speed) : timesUpdated(0), speed(speed) {
}

void FadeOutScene::update() {
    if(!this->palette.get()) {
        auto bgPalette = sceneToAffect->getBackgroundPalette();
        if(!bgPalette) {
            BackgroundPaletteManager defaultBg({});
            bgPalette = &defaultBg;
        }

        auto combined = (*sceneToAffect->getForegroundPalette() + *bgPalette);
        this->palette = std::unique_ptr<CombinedPalette>(combined);

    }

    this->palette.get()->increaseBrightness(speed);
    timesUpdated++;
}