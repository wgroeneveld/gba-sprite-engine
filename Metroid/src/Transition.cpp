//
// Created by kyles on 27/12/2019.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include "Transition.h"

#include "samus_aran.h"
#include "ball.h"
#include "Mario.h"
#include "projectiel.h"
#include "achtergrond.h"
#include "achtergrond2.h"
#include "achtergrond3.h"
#include "sample_sound.h"
#include "Metroid.h"
#include "Bullet.h"
#include "Level1.h"
#include "IntroScene.h"
#include "VictoryScene.h"
#include "Level2.h"

std::vector<Background *> Transition::backgrounds() {
    return {bg.get()/*, bg2.get(), bg3.get()*/};
}

std::vector<Sprite *> Transition::sprites() {
    return {  /*metroidObject->getMetroid(), ball_projectiel.get(), enemyObject->getMario(), bulletObject->getBullet(), firebolt.get()*/ };
}

void Transition::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(tussenschermMapPal, sizeof(tussenschermMapPal)));

    bg = std::unique_ptr<Background>(new Background(1, tussenschermTiles, sizeof(tussenschermTiles), tussenschermMap, sizeof(tussenschermMap)));
    bg.get()->useMapScreenBlock(29);



    engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);
}


void Transition::tick(u16 keys) {


    if (keys & KEY_START) {
        if (!engine->isTransitioning()) {
            engine->enqueueSound(zelda_secret_16K_mono, zelda_secret_16K_mono_bytes);

            engine->transitionIntoScene(new Level2(engine), new FadeOutScene(8));
        }
    }
}