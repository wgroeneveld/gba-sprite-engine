//
// Created by woute on 28/11/2019.
//

#include "Titlescreen_scene.h"
#include "aang_jump_old/aang_jump (1).h"
#include "background_title/titlescreen.h"
#include "Level1_scene.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

std::vector<Background *> Titlescreen_scene::backgrounds() {
    return { background.get()};
}

std::vector<Sprite *> Titlescreen_scene::sprites() {
    return { };
}

void Titlescreen_scene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(aang_jump__1_Pal, sizeof(aang_jump__1_Pal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(titlescreenPal, sizeof(titlescreenPal)));

    background = std:: unique_ptr<Background>(new Background(0, titlescreenTiles, sizeof(titlescreenTiles), titlescreenMap, sizeof(titlescreenMap)));
    background.get()->useMapScreenBlock(24);
}

void Titlescreen_scene::tick(u16 keys) {
    if((keys & KEY_START)){
        engine->transitionIntoScene(new Level1_scene(engine), new FadeOutScene(2));
    }
}