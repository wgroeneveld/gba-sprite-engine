//
// Created by michi on 11/08/2020.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "Minigame1Screen.h"

#include "../backgrounds/Minigame/box.h"
#include "../backgrounds/Minigame/redEnemy.h"

#include "../backgrounds/Minigame/sharedMinigame.h"
#include "GameScreen.h"

#include "../backgrounds/gras.h"
#include "../backgrounds/grasBackground.h"

Minigame1Screen::Minigame1Screen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje, int sprite) : MinigameScreen(engine, gamepje, sprite) {
    minigame = std::make_shared<Minigame1>();
}

void Minigame1Screen::load() {
    TextStream::instance().setText(std::string("Test"), 4, 10);

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedMinigamePal, sizeof(sharedMinigamePal)));

    SpriteBuilder<Sprite> spriteBuilder;

    badGuy = spriteBuilder
            .withData(redEnemyCenterTiles, sizeof(redEnemyCenterTiles))
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

    MinigameScreen::load();

}



void Minigame1Screen::setGehaald() {
    if (minigame->getGehaald()) {
        game->getSpeler()->setSpel1Gehaald(true);
    }
}

void Minigame1Screen::setBegintekst() {
    TextStream::instance().setText(std::string("Rodrick is a very fast, luckily he isn't strong enough to lift the box if it falls partially on top of him!"), 2, 10);
}

void Minigame1Screen::setEindtekst() {
    if (minigame->getGehaald()) {
        TextStream::instance().setText(std::string("Yay! You did it! Rodrick is captured!"), 2, 10);
    }
    else {
        TextStream::instance().setText(std::string("Oh no! Rodrick escaped!"), 2, 10);
    }
}




