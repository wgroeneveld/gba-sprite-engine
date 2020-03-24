//
// Created by michi on 21/03/2020.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "MainMenuScreen.h"
#include "AboutScreen.h"
#include "boardScreen.h"
#include "../img/minion_image.h"


std::vector<Background *> MainMenuScreen::backgrounds() {
    return {};
}

std::vector<Sprite *> MainMenuScreen::sprites() {
    return {minion.get()};
}

void MainMenuScreen::updateSelect() {
    minion->moveTo(70, 360);
}

void MainMenuScreen::load() {
    //foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(spritesPal, sizeof(spritesPal)));
   // backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(minion_palette, sizeof(minion_palette)));

    TextStream::instance().setText("WELCOME TO PARTY GAME", 3, 3);
    TextStream::instance().setText("BoardScreen", 7, 8);
    TextStream::instance().setText("AboutScreen", 11, 8);

    SpriteBuilder<Sprite> spriteBuilder;

    minion = spriteBuilder
            .withData(minion_data, sizeof(minion_data))
            .withSize(SIZE_32_32)
            .withAnimated(2, 20)
            .withLocation(70, 320)
            .buildPtr();
}

void MainMenuScreen::tick(u16 keys) {
    if (keys & KEY_START) { //KEY_START = enter
        engine->setScene(new AboutScreen(engine));
    }
    if (keys & KEY_UP) { //KEY_START = enter
        engine->setScene(new boardScreen(engine));
    }
    if (keys & KEY_DOWN) { //KEY_START = enter
        updateSelect();
    }

}
