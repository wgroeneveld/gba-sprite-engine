//
// Created by michi on 11/08/2020.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Minigame3Screen.h"
#include "../backgrounds/Minigame/box.h"
#include "../backgrounds/Minigame/blueEnemy.h"

#include "../backgrounds/Minigame/sharedMinigame.h"

Minigame3Screen::Minigame3Screen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje, int sprite) : MinigameScreen(engine, gamepje, sprite) {
    minigame = std::make_shared<Minigame3>();
}

void Minigame3Screen::load() {
    TextStream::instance().setText(std::string("Test"), 4, 10);

    MinigameScreen::load();

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedMinigamePal, sizeof(sharedMinigamePal)));

    SpriteBuilder<Sprite> spriteBuilder;

    badGuy = spriteBuilder
            .withData(blueEnemyCenterTiles, sizeof(blueEnemyCenterTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 40)
            .withLocation(minigame->getPosX(), minigame->getPosY())
            .buildPtr();

    box = spriteBuilder
            .withData(boxTiles, sizeof(boxTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 40)
            .withLocation(minigame->getPosBoxX(), minigame->getPosBoxY())
            .buildPtr();

}

void Minigame3Screen::setBegintekst() {
    TextStream::instance().setText(std::string("Begin Spel 3"), 2, 10);
}

void Minigame3Screen::setEindtekst() {
    TextStream::instance().setText(std::string("Einde Spel 3"), 2, 10);
}

void Minigame3Screen::setGehaald() {
    if (minigame->getGehaald()) {
        game->getSpeler()->setSpel3Gehaald(true);
    }
}
/*
void Minigame3Screen::tick(u16 keys) {
    MinigameScreen::tick(keys);

    if (bezig) {
        if (!(keys & KEY_RIGHT) && (lastKeys & KEY_RIGHT)) {
            minigame->moveBoxRight();
        }
        else if (!(keys & KEY_LEFT) && (lastKeys & KEY_LEFT)) {
            minigame->moveBoxLeft();
        }
        else if (!(keys & KEY_UP) && (lastKeys & KEY_UP)) {
            minigame->moveBoxUp();
        }
        else if (!(keys & KEY_DOWN) && (lastKeys & KEY_DOWN)) {
            minigame->moveBoxDown();
        }
    }
    updatePosition();


}*/




