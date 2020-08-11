//
// Created by michi on 11/08/2020.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Minigame2Screen.h"

#include "../../backgrounds/Minigame/box.h"
#include "../../backgrounds/Minigame/greenEnemy.h"

#include "../../backgrounds/Minigame/sharedMinigame.h"

#include "../../sound/secondLaugh.h"
#include "../../sound/scream3.h"


Minigame2Screen::Minigame2Screen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje, int sprite) : MinigameScreen(engine, gamepje, sprite) {
    minigame = std::make_shared<Minigame2>();
}

void Minigame2Screen::load() {

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
    TextStream::instance().setText(std::string("Gregory Green isn't very fast,"), 2, 1);
    TextStream::instance().setText(std::string("but he is very strong!"), 3, 1);
    TextStream::instance().setText(std::string("Make sure you get the box"), 4, 1);
    TextStream::instance().setText(std::string("completely on top of him!"), 5, 1);

}

void Minigame2Screen::setEindtekst() {
    if (minigame->getGehaald()) {
        TextStream::instance().setText(std::string("Yay! You did it!"), 2, 2);
        TextStream::instance().setText(std::string("Gregory is captured!"), 3, 2);
        engine.get()->enqueueSound(scream3, sizeof(scream3), 44100);


    }
    else {
        TextStream::instance().setText(std::string("Oh no! Gregory escaped!"), 2, 2);
        engine.get()->enqueueSound(secondLaugh, sizeof(secondLaugh), 44100);

    }
}
void Minigame2Screen::setGehaald() {
    if (minigame->getGehaald()) {
        game->getSpeler()->setSpel2Gehaald(true);
    }
}