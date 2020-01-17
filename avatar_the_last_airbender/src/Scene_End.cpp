#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "Scene_End.h"

#include "Scene_Level1.h"

#include "data/background_game/backgroundGround/background13_set.h"
#include "data/background_game/backgroundGround/background1_map.h"
#include "data/background_game/backgroundSea/background2_set.h"
#include "data/background_game/backgroundSea/background2_map.h"
#include "data/background_game/backgroundSun/background3_map.h"
#include "data/background_game/background_pal.h"

std::vector<Background *> Scene_End::backgrounds() {
    return { backgroundGround.get(),
             backgroundSea.get(),
             backgroundSun.get()};
}

std::vector<Sprite *> Scene_End::sprites() {
    return {};
}

void Scene_End::load() {
    engine.get()->enableText();

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(backgroundPal, sizeof(backgroundPal)));

    backgroundGround = std::unique_ptr<Background>(new Background(1, background13Tiles, sizeof(background13Tiles),background1Map , sizeof(background1Map), 9, 1, MAPLAYOUT_32X32));
    backgroundSea = std::unique_ptr<Background>(new Background(2, background2Tiles, sizeof(background2Tiles),background2Map , sizeof(background2Map), 25, 2, MAPLAYOUT_32X32));
    backgroundSun = std::unique_ptr<Background>(new Background(3, background13Tiles, sizeof(background13Tiles),background3Map , sizeof(background3Map), 12, 1, MAPLAYOUT_32X64));
    backgroundSun->scroll(0,-64);

    TextStream::instance().setText(std::string("YOU DIED!") , 2, 10);
    TextStream::instance().setText(std::string("You killed ") + std::to_string(amountEnemiesKilled)+ std::string(" enemies") , 3, 6);
    TextStream::instance().setText(std::string("Click START to restart!") , 4, 4);
}

void Scene_End::tick(u16 keys) {
    if((keys & KEY_START)){
        auto scene_level1 = new Scene_Level1(engine);
        engine->transitionIntoScene(scene_level1, new FadeOutScene(2));
    }
}