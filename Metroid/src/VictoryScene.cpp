//
// Created by kyles on 8/01/2020.
//

#include "VictoryScene.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "SoundIntro.h"
#include "achtergrondIntro.h"
#include "Level2.h"
#include "achtergrondVictory.h"
#include "SoundVictory.h"

VictoryScene::VictoryScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> VictoryScene::sprites() {
    return {};
}

std::vector<Background *> VictoryScene::backgrounds() {
    return {
            bg.get()
    };
}

void VictoryScene::tick(u16 keys) {
    //engine->getTimer()->start();
    if(/*engine->getTimer()->getSecs() > 7*/ keys & KEY_START) {
        if (!engine->isTransitioning()) {
            engine->transitionIntoScene(new Level2(engine), new FadeOutScene(6));
        }
    }
}

void VictoryScene::load() {
    engine.get()->disableText();
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(victoryPalPal, sizeof(victoryPalPal)));

    bg = std::unique_ptr<Background>(new Background(0, victoryTiles, sizeof(victoryTiles), victoryMap, sizeof(victoryMap),24,0,MAPLAYOUT_32X32));
    engine->enqueueSound(victory_sound,victory_sound_bytes,90000);

}
