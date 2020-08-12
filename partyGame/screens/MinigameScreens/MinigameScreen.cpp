//
// Created by michi on 15/07/2020.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "MinigameScreen.h"
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "../GameScreen/GameScreen.h"

#include "../../backgrounds/grasBackground.h"
#include "../../backgrounds/gras.h"
#include "../../sound/minigame.h"


MinigameScreen::MinigameScreen(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Game> gamepje, int sprite) : Scene(engine), game(gamepje), spriteKeuze(sprite) {}

void MinigameScreen::load() {
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(grasPal, sizeof(grasPal)));
    background = std::unique_ptr<Background>(new Background(1, grasTiles, sizeof(grasTiles), grasBackground, sizeof(grasBackground)));
    background.get()->useMapScreenBlock(16);
    engine->enqueueMusic(minigameSound, sizeof(minigameSound), 44100);

}

std::vector<Sprite *> MinigameScreen::sprites() {return {badGuy.get(), box.get()};}

std::vector<Background *> MinigameScreen::backgrounds() {return {background.get()};}

void MinigameScreen::tick(u16 keys) {

    if (firstTick) {
        setBegintekst();
        wachtEven(2000);
        removeTekst();
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (bezig) { // Als ik dit blok onder het andere zet geeft de updatePosition() problemen.
        minigame->beweeg();
        updatePosition();
    }

    if (!(keys & KEY_START) && (lastKeys & KEY_START)) {// ENTER key, wait until released
        bezig = false;
        endScene();
    }
    lastKeys = keys;
}

void MinigameScreen::updatePosition() {
    badGuy->moveTo(minigame->getPosX(), minigame->getPosY());
    box->moveTo(minigame->getPosBoxX(), minigame->getPosBoxY());
}


void MinigameScreen::endScene() {
    minigame->makePicture();
    engine->dequeueAllSounds();
    setGehaald();
    setEindtekst();
    wachtEven(5000);
    game->getSpeler()->setScore(minigame->getScore());
    game->getSpeler()->setAlGegooid(false);
    engine->setScene(new GameScreen(engine, game, spriteKeuze));
}

void MinigameScreen::wachtEven(int tijd) {
    engine->getTimer()->stop();
    engine->getTimer()->reset();
    engine->getTimer()->start();
    while (engine->getTimer()->getTotalMsecs() < tijd) {}
    engine->getTimer()->stop();
    engine->getTimer()->reset();
}

void MinigameScreen::removeTekst() {
    TextStream::instance().clear();
}



