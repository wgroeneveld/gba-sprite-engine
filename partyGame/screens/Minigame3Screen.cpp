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
            .withData(blue_enemyTiles, sizeof(blue_enemyTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 40)
            .withLocation(minigame->getPosX(), minigame->getPosY())
            .buildPtr();

    box = spriteBuilder
            .withData(boxTiles, sizeof(boxTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 40)
            .withLocation(104, 64)
            .buildPtr();

}

void Minigame3Screen::zegIets() {
    TextStream::instance().setText(std::string("Spel 3 gehaald"), 2, 10);
    TextStream::instance().setText(std::string("Spel Score: " + std::to_string(minigame->getScore())), 3, 10);
    game->getSpeler()->setScore(minigame->getScore());
    TextStream::instance().setText(std::string("Totaal Score: " + std::to_string(game->getSpeler()->getScore())), 4, 10);
}

void Minigame3Screen::setGehaald() {
    if (minigame->getGehaald()) {
        game->getSpeler()->setSpel3Gehaald(true);
    }
}

