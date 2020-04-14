//
// Created by michi on 14/04/2020.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include "GameScreen.h"
#include "../img/shared.h"
#include "../img/speler1.h"
#include "../img/spelerAI.h"
#include "MainMenuScreen.h"

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>



void GameScreen::load() {
    TextStream::instance().setText("Game Screen", 3, 3);
    TextStream::instance().setText(std::string(std::to_string(game.getSpeler1()->getScore())), 5, 3);

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    SpriteBuilder<Sprite> spriteBuilder;

    speler1Sprite = spriteBuilder
            .withData(speler1Tiles, sizeof(speler1Tiles))
            .withSize(SIZE_32_32)
            .withAnimated(4, 40)
            .withLocation(70, 300)
            .buildPtr();

    spelerAISprite = spriteBuilder
            .withData(spelerAITiles, sizeof(spelerAITiles))
            .withSize(SIZE_32_32)
            .withAnimated(4, 40)
            .withLocation(70, 100)
            .buildPtr();
}

std::vector<Sprite *> GameScreen::sprites() {
    return {speler1Sprite.get(), spelerAISprite.get()};
}

std::vector<Background *> GameScreen::backgrounds() {
    return {};
}

void GameScreen::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (!(keys & KEY_START) && (lastKeys & KEY_START)) {// ENTER key, wait until released
        engine->setScene(new MainMenuScreen(engine));
    }

    if (keys & KEY_DOWN) {
        if (game.getSelectedPlayer() == game.getSpeler1()) {
            speler1Sprite.get()->moveTo(speler1Sprite.get()->getX(), speler1Sprite.get()->getY()+1);
        }
        else {
            spelerAISprite.get()->moveTo(spelerAISprite.get()->getX(), spelerAISprite.get()->getY()+1);
        }
    }
    if (keys & KEY_UP) {
        if (game.getSelectedPlayer() == game.getSpeler1()) {
            speler1Sprite.get()->moveTo(speler1Sprite.get()->getX(), speler1Sprite.get()->getY()-1);
        }
        else {
            spelerAISprite.get()->moveTo(spelerAISprite.get()->getX(), spelerAISprite.get()->getY()-1);
        }
    }
    if (!(keys & KEY_RIGHT) && (lastKeys & KEY_RIGHT)) {
        game.switchSelectedPlayer();
    }


    lastKeys = keys;

}


