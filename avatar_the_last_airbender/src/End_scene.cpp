//
// Created by woute on 16/01/2020.
//

#include "End_scene.h"
#include "Scene_Level1.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>



std::vector<Background *> End_scene::backgrounds() {
    return { };
}

std::vector<Sprite *> End_scene::sprites() {
    return {};
}

void End_scene::load() {
    //engine.get()->enableText();

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    TextStream::instance().setText(std::string("YOU DIED!") , 2, 3);
    TextStream::instance().setText(std::string("You killed ") + std::to_string(amountEnemysKilled)+ std::string("Enemys") , 3, 2);
    TextStream::instance().setText(std::string("Click START to restart the game") , 4, 1);

}

void End_scene::tick(u16 keys) {
    if((keys & KEY_START)){
        auto scene_level1 = new Scene_Level1(engine);
        engine->transitionIntoScene(scene_level1, new FadeOutScene(2));
    }
}