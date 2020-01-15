//
// Created by kyles on 7/01/2020.
//

#include "DeadScene.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "../sound/SoundDeath.h"
#include "../sprites/samus_aran.h"
#include "IntroScene.h"

std::vector<Background *> DeadScene::backgrounds() {
    return {};
}

std::vector<Sprite *> DeadScene::sprites() {
    return {  metroidDood.get()};
}

void DeadScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(doodPal, sizeof(doodPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    SpriteBuilder<Sprite> builder;

    metroidDood = builder
            .withData(doodTiles, sizeof(doodTiles))
            .withAnimated(15,9)
            .withSize(SIZE_32_64)
            .withLocation(104,48)
            .buildPtr();

    engine->enqueueSound(mission_failed, mission_failed_bytes, 90000);
}

void DeadScene::tick(u16 keys) {
    if(metroidDood->getCurrentFrame() == 14){
        metroidDood->stopAnimating();
    }
    TextStream::instance().setText(std::string("MISSION FAILED"), 5, 8);

    if(keys & KEY_START) {
        if (!engine->isTransitioning()) {
            engine->transitionIntoScene(new IntroScene(engine), new FadeOutScene(6));
        }
    }

}
