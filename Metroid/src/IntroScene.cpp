//
// Created by kyles on 8/01/2020.
//

#include "IntroScene.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "../sound/SoundIntro.h"
#include "../achtergrond/achtergrondIntro.h"
#include "Level1.h"
#include "Level2.h"
#include "VictoryScene.h"


IntroScene::IntroScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine),scrollX(0),scrollY(0) {}

std::vector<Sprite *> IntroScene::sprites() {
    return {};
}

std::vector<Background *> IntroScene::backgrounds() {
    return {
            bg.get()
    };
}

void IntroScene::tick(u16 keys) {
    if(keys & KEY_START) {
        if (!engine->isTransitioning()) {
            engine->transitionIntoScene(new Level1(engine), new FadeOutScene(6));
        }
    }
}

void IntroScene::load() {
    engine.get()->disableText();
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(openingCreditsPalPal, sizeof(openingCreditsPalPal)));

    bg = std::unique_ptr<Background>(new Background(0, openingCreditsTiles, sizeof(openingCreditsTiles), openingCreditsMap, sizeof(openingCreditsMap),24,0,MAPLAYOUT_32X32));
    engine->enqueueMusic(leaving_earth,leaving_earth_bytes,90000);

}

