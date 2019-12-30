//
// Created by kyles on 27/12/2019.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include "menu.h"

#include "samus_aran.h"
#include "achtergrond.h"
#include "achtergrond2.h"
#include "achtergrond3.h"
#include "sample_sound.h"
#include "Metroid.h"

std::vector<Background *> Menu::backgrounds() {
    return {bg.get()};
}

std::vector<Sprite *> Menu::sprites() {
    return {  metroidObject->getMetroid() };
}

void Menu::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(animatie_metroidPal, sizeof(animatie_metroidPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(dungeon_backgroundPal, sizeof(dungeon_backgroundPal)));

    SpriteBuilder<Sprite> builder;

    metroidBewegen = builder
            .withData(animatie_metroidTiles, sizeof(animatie_metroidTiles))
            .withSize(SIZE_32_64)
            .withAnimated(11, 3)
            .withLocation(50, 50)
            .withinBounds()
            .buildPtr();

    metroidObject = std::unique_ptr<Metroid>(new Metroid(std::move(metroidBewegen)));

    bg = std::unique_ptr<Background>(new Background(1, dungeon_backgroundTiles, sizeof(dungeon_backgroundTiles), dungeon_backgroundMap, sizeof(dungeon_backgroundMap)));
    bg.get()->useMapScreenBlock(16);
    //bg2 = std::unique_ptr<Background>(new Background(1, wallsTiles, sizeof(wallsTiles), wallsMap, sizeof(wallsMap)));
    //bg2.get()->useMapScreenBlock(16);


    engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);
}

void Menu::tick(u16 keys) {
    
    metroidObject->tick(keys);
}
