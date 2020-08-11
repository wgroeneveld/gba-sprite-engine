//
// Created by michi on 11/08/2020.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Minigame2Screen.h"

#include "../backgrounds/Minigame/box.h"
#include "../backgrounds/Minigame/greenEnemy.h"

#include "../backgrounds/Minigame/sharedMinigame.h"

Minigame2Screen::Minigame2Screen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje, int sprite) : MinigameScreen(engine, gamepje, sprite) {
    minigame = std::make_shared<Minigame2>();
}

void Minigame2Screen::load() {
    TextStream::instance().setText(std::string("Test"), 4, 10);

    MinigameScreen::load();

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedMinigamePal, sizeof(sharedMinigamePal)));

    SpriteBuilder<Sprite> spriteBuilder;

    badGuy = spriteBuilder
            .withData(green_enemyTiles, sizeof(green_enemyTiles))
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

void Minigame2Screen::zegIets() {
    TextStream::instance().setText(std::string("Spel 2 gehaald!"), 2, 10);
    TextStream::instance().setText(std::string("Spel Score: " + std::to_string(minigame->getScore())), 3, 10);
    game->getSpeler()->setScore(minigame->getScore());
    TextStream::instance().setText(std::string("Totaal Score: " + std::to_string(game->getSpeler()->getScore())), 4, 10);
}

void Minigame2Screen::setGehaald() {
    if (minigame->getGehaald()) {
        game->getSpeler()->setSpel2Gehaald(true);
    }
}