//
// Created by michi on 11/08/2020.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "Minigame1Screen.h"

#include "../../backgrounds/Minigame/box.h"
#include "../../backgrounds/Minigame/redEnemy.h"

#include "../../backgrounds/Minigame/sharedMinigame.h"
#include "../GameScreen/GameScreen.h"

#include "../../backgrounds/gras.h"
#include "../../backgrounds/grasBackground.h"

#include "../../sound/firstLaugh.h"
#include "../../sound/scream2.h"


Minigame1Screen::Minigame1Screen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje, int sprite) : MinigameScreen(engine, gamepje, sprite) {
    minigame = std::make_shared<Minigame1>();
}

void Minigame1Screen::load() {
    MinigameScreen::load();

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
    //updatePosition();
}

void Minigame1Screen::setGehaald() {
    if (minigame->getGehaald()) {
        game->getSpeler()->setSpel1Gehaald(true);
    }
}

void Minigame1Screen::setBegintekst() {
    TextStream::instance().setText(std::string("Rodrick Red is very fast!"), 2, 1);
    TextStream::instance().setText(std::string("But he isn't strong enough"), 3, 1);
    TextStream::instance().setText(std::string("to lift the box if it falls"), 4, 1);
    TextStream::instance().setText(std::string("partially on top of him!"), 5, 1);
}

void Minigame1Screen::setEindtekst() {
    if (minigame->getGehaald()) {
        TextStream::instance().setText(std::string("Yay! You did it!"), 2, 2);
        TextStream::instance().setText(std::string("Rodrick is captured!"), 3, 2);
        engine.get()->enqueueSound(scream2, sizeof(scream2), 44100);

    }
    else {
        TextStream::instance().setText(std::string("Oh no! Rodrick escaped!"), 2, 2);
        engine.get()->enqueueSound(firstLaugh, sizeof(firstLaugh), 44100);
    }
}




