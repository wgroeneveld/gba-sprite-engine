//
// Created by michi on 15/07/2020.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Minigame2Screen.h"
#include "../img/hoofdpersonage.h"
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "MainMenuScreen.h"
#include "GameScreen.h"

#include "../backgrounds/grasBackground.h"
#include "../backgrounds/gras.h"
#include "../backgrounds/gunshot.h"
#include "../backgrounds/picture1short.h"

void Minigame2Screen::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(hoofdpersonagePal, sizeof(hoofdpersonagePal)));

    SpriteBuilder<Sprite> spriteBuilder;

    ufo = spriteBuilder
            .withData(hoofdpersonageTiles, sizeof(hoofdpersonageTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 40)
            .withLocation(0, 64)
            .buildPtr();

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(grasPal, sizeof(grasPal)));
    background = std::unique_ptr<Background>(new Background(1, grasTiles, sizeof(grasTiles), grasBackground, sizeof(grasBackground)));
    background.get()->useMapScreenBlock(16);
}
std::vector<Sprite *> Minigame2Screen::sprites() {
    return {ufo.get()};

}

std::vector<Background *> Minigame2Screen::backgrounds() {
    return {background.get()};
}

void Minigame2Screen::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (bezig) { // Als ik dit blok onder het andere zet geeft de updatePosition() problemen.
        minigame.beweeg();
        updatePosition();
    }

    if (!(keys & KEY_UP) && (lastKeys & KEY_UP)) {// ENTER key, wait until released
        bezig = false;
        endScene();
    }

    lastKeys = keys;
}

void Minigame2Screen::updatePosition() {
   ufo.get()->moveTo(minigame.getPositieX(), 64);
}

void Minigame2Screen::endScene() {
    minigame.MakePicture();

    //engine->enqueueSound(gunshot, gunshot_bytes, 44100);
    TextStream::instance().setText(std::string("Gedaan"), 2, 10);
    TextStream::instance().setText(std::string("Spel Score: " + std::to_string(minigame.getScore())), 3, 10);
    game->getSpeler()->setScore(minigame.getScore());
    TextStream::instance().setText(std::string("Totaal Score: " + std::to_string(game->getSpeler()->getScore())), 4, 10);
    engine->getTimer()->stop();
    engine->getTimer()->reset();
    engine->getTimer()->start();
    while (engine->getTimer()->getTotalMsecs() < 2000) {}
    engine->getTimer()->stop();
    engine->getTimer()->reset();
    game->getSpeler()->setAlGegooid(false); //Moet dat hier of bij Minigame2.cpp

    if (game->getSpeler()->getPosX() == 0 and game->getSpeler()->getPosY() == 0) { //Hier nog rondzetten if minigameScore > 100 ofzo
        game->getSpeler()->setSpel1Gehaald(true);
    }
    else if (game->getSpeler()->getPosX() == 6 and game->getSpeler()->getPosY() == 0) { //op gameScreen ook weergeven welke je al gehaald hebt
        game->getSpeler()->setSpel2Gehaald(true);
    }
    else if (game->getSpeler()->getPosX() == 6 and game->getSpeler()->getPosY() == 6) {
        game->getSpeler()->setSpel3Gehaald(true);
    }

    engine->transitionIntoScene(new GameScreen(engine, game), new FadeOutScene(2));
}

