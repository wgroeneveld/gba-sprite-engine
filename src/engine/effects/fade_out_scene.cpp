//
// Created by Wouter Groeneveld on 04/08/18.
//

#include "fade_out_scene.h"


void FadeOutScene::update() {
    sceneToAffect->getForegroundPalette()->increaseBrightness(speed);

    auto bgPalette = sceneToAffect->getBackgroundPalette();
    if(bgPalette) {
        bgPalette->increaseBrightness(speed);
    } else {
        BackgroundPaletteManager defaultBg({});
        defaultBg.increaseBrightness(speed);
    }
    timesUpdated++;
}