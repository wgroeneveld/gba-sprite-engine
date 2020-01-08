#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "Scene_Start.h"

#include "Scene_Level1.h"
#include "Scene_Level2.h"

#include "background_title/titlescreen.h"

std::vector<Background *> Scene_Start::backgrounds() {
    return { background.get()};
}

std::vector<Sprite *> Scene_Start::sprites() {
    return {};
}

void Scene_Start::load() {
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(titlescreenPal, sizeof(titlescreenPal)));

    background = std:: unique_ptr<Background>(new Background(0, titlescreenTiles, sizeof(titlescreenTiles), titlescreenMap, sizeof(titlescreenMap)));
    background.get()->useMapScreenBlock(25);
}

void Scene_Start::tick(u16 keys) {
    if((keys & KEY_START)){
        auto scene_level1 = new Scene_Level1(engine);
        //auto scene_level2 = new Scene_Level2(engine);
        engine->transitionIntoScene(scene_level1, new FadeOutScene(2));
    }
}