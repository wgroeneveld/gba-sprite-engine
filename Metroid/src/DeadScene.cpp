//
// Created by kyles on 7/01/2020.
//

#include "DeadScene.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include "menu.h"

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
#include "DeadScene.h"

std::vector<Background *> DeadScene::backgrounds() {
    return {};
}

std::vector<Sprite *> DeadScene::sprites() {
    return {  /*metroidObject->getMetroid(), ball_projectiel.get(), enemyObject->getMario(), bulletObject->getBullet(), firebolt.get() */};
}

void DeadScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(/*new ForegroundPaletteManager(sharedPal, sizeof(sharedPal))*/);
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>();
    /*
    SpriteBuilder<Sprite> builder;

    ball_projectiel = builder
            .withData(ballTiles, sizeof(ballTiles))
            .withSize(SIZE_16_16)
            .withLocation(60, 60)
            .withinBounds()
            .buildPtr();*/


    engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);
}


void DeadScene::tick(u16 keys) {


}
