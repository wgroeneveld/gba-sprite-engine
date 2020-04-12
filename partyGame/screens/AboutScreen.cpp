//
// Created by michi on 22/03/2020.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "AboutScreen.h"
#include "MainMenuScreen.h"

#include "../backgrounds/testtest2.h"

std::vector<Background *> AboutScreen::backgrounds() {
    return {/*background.get()*/}; //als ik hier dat laat staan, crasht ie, omdat dat zelfde naam is als bij de andere? Of gewoon omdat er geen background gecreeerd wordt?
}


std::vector<Sprite *> AboutScreen::sprites() { return {};}

void AboutScreen::load() {
    //foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(spritesPal, sizeof(spritesPal)));
    // backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());
    //backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bg_palette, sizeof(bg_palette)));

    TextStream::instance().setText("AboutScreen", 3, 8);

    //backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(testPal, sizeof(testPal)));
    //background = std::unique_ptr<Background>(new Background(1, testTiles, sizeof(testTiles), testMap, sizeof(testMap)));
    //background->useMapScreenBlock(8);


}

void AboutScreen::tick(u16 keys) {
    if (keys & KEY_START) {
        engine->setScene(new MainMenuScreen(engine));
    }

}