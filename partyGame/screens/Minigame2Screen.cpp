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
            .withData(greenEnemyCenterTiles, sizeof(greenEnemyCenterTiles))
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

void Minigame2Screen::setBegintekst() {
    TextStream::instance().setText(std::string("Gregory Green isn't very fast, but he is very strong! Make sure you got the box completely on top of him!"), 2, 10);
}

void Minigame2Screen::setEindtekst() {
    if (minigame->getGehaald()) {
        TextStream::instance().setText(std::string("Yay! You did it! Gregory is captured!"), 2, 10);
    }
    else {
        TextStream::instance().setText(std::string("Oh no! Gregory escaped!"), 2, 10);
    }
}
void Minigame2Screen::setGehaald() {
    if (minigame->getGehaald()) {
        game->getSpeler()->setSpel2Gehaald(true);
    }
}