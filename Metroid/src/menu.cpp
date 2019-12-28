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
#include "sample_sound.h"
#include "Metroid.h"

std::vector<Background *> Menu::backgrounds() {
    return {bg.get() };
}

std::vector<Sprite *> Menu::sprites() {
    return {  metroidObject->getMetroid() };
}

void Menu::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(animatie_metroidPal, sizeof(animatie_metroidPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(achtergrondPal, sizeof(achtergrondPal)));

    SpriteBuilder<Sprite> builder;

    metroidBewegen = builder
            .withData(animatie_metroidTiles, sizeof(animatie_metroidTiles))
            .withSize(SIZE_32_64)
            .withAnimated(16, 30)
            .withLocation(50, 50)
            .withinBounds()
            .buildPtr();

    metroidObject = std::unique_ptr<Metroid>(new Metroid(std::move(metroidBewegen)));

    bg = std::unique_ptr<Background>(new Background(1, achtergrondTiles, sizeof(achtergrondTiles), achtergrondMap, sizeof(achtergrondMap)));
    bg.get()->useMapScreenBlock(16);


    engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);
}

void Menu::tick(u16 keys) {
    
    metroidObject->tick(keys);
}
