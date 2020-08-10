//
// Created by michi on 14/04/2020.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include "GameScreen.h"
//#include "../img/shared.h"
//#include "../img/speler1.h"
//#include "../img/spelerAI.h"
//#include "../img/hoofdpersonage.h"
#include "MainMenuScreen.h"

#include "../backgrounds/Tiles8x8.h"
#include "../backgrounds/eerste7x7Map.h"
#include "../backgrounds/Background8x8Map.h"
#include "EndScreen.h"
#include "Minigame2Screen.h"
#include "../backgrounds/hallo.h"
#include "../backgrounds/blubikbeneenvis.h"
#include "../backgrounds/gameScreenFull.h"
#include "../backgrounds/gameScreenFull.c"
#include "../backgrounds/gameScreenMap.h"
#include "../backgrounds/gameScreenBorder.h"
#include "../backgrounds/tiles10_08.h"
#include "../backgrounds/tiles10_08.c"
#include "../backgrounds/blackAndTransparantMap.h"
#include "../backgrounds/red_green.c"
#include "../backgrounds/red_green.h"

#include "../backgrounds/dobbelsteen.h"
#include "../backgrounds/witspook1.h"
#include "../backgrounds/witspook2.h"
#include "../backgrounds/shared10_08.h"

//#include "Minigame1Screen.h"


#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <random>


void GameScreen::load() {
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(Tiles8x8Pal, sizeof(Tiles8x8Pal)));
    background = std::unique_ptr<Background>(new Background(2, Tiles8x8Tiles, sizeof(Tiles8x8Tiles), eerste7x7Map, sizeof(eerste7x7Map)));
    background.get()->useMapScreenBlock(4);
    background2 = std::unique_ptr<Background>(new Background(1, Tiles8x8Tiles, sizeof(Tiles8x8Tiles), Background8x8Map, sizeof(Background8x8Map)));
    background2.get()->useMapScreenBlock(20);

    //backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(gameScreenFullPal, sizeof(gameScreenFullPal)));
    //background = std::unique_ptr<Background>(new Background(1, gameScreenFullTiles, sizeof(gameScreenFullTiles), gameScreenFull, sizeof(gameScreenFull)));
    //background.get()->useMapScreenBlock(4);
    //background2 = std::unique_ptr<Background>(new Background(2, gameScreenFullTiles, sizeof(gameScreenFullTiles), Background8x8Map, sizeof(Background8x8Map)));
    //background2.get()->useMapScreenBlock(20);



    //TextStream::instance().setFontColor(0xF800); //https://ee-programming-notepad.blogspot.com/2016/10/16-bit-color-generator-picker.html

    TextStream::instance().setText(std::string("Score"), 1, 25);
    TextStream::instance().setText(std::string(std::to_string(game->getSpeler()->getScore())), 2, 25);
    TextStream::instance().setText(std::string("Moves"), 3, 25);
    TextStream::instance().setText(std::string(std::to_string(game->getSpeler()->getVakjesNogVerschuiven())), 4, 25);

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));

    SpriteBuilder<Sprite> spriteBuilder;

    spook1Sprite = spriteBuilder
            .withData(witspook1Tiles, sizeof(witspook1Tiles))
            .withSize(SIZE_32_32)
            .withAnimated(6, 8)
            .withLocation(0, 0)
            .buildPtr();

    spook2Sprite = spriteBuilder
            .withData(witspook2Tiles, sizeof(witspook2Tiles))
            .withSize(SIZE_32_32)
            .withAnimated(6, 8)
            .withLocation(40, 0)
            .buildPtr();
    dobbelSteenSprite = spriteBuilder
            .withData(dobbelsteenTiles, sizeof(dobbelsteenTiles))
            .withSize(SIZE_32_32)
            .withAnimated(3, 8)
            .withLocation(80, 0)
            .buildPtr();



    updatePosition();
    engine->getTimer()->start();
}

std::vector<Sprite *> GameScreen::sprites() {return {spook1Sprite.get(), spook2Sprite.get(), dobbelSteenSprite.get()};}

std::vector<Background *> GameScreen::backgrounds() {return {background.get(), background2.get()};}

void GameScreen::tick(u16 keys) {
    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }
    if (aanHetGooien) {
        if (!(keys & KEY_START) && (lastKeys & KEY_START)) {
            int seed = engine->getTimer()->getTotalMsecs();
            game->getSpeler()->gooiDobbelsteen(seed);
            TextStream::instance().setText(std::string("gegooid"), 5, 25);
            aanHetGooien = false;
            updatePosition();
        }
    }
    else {
        if (!(keys & KEY_RIGHT) && (lastKeys & KEY_RIGHT)) {
            game->getSpeler()->beweegNaarRechts();
            updatePosition();
        } else if (!(keys & KEY_LEFT) && (lastKeys & KEY_LEFT)) {
            game->getSpeler()->beweegNaarLinks();
            updatePosition();
        } else if (!(keys & KEY_UP) && (lastKeys & KEY_UP)) {
            game->getSpeler()->beweegNaarBoven();
            updatePosition();
        } else if (!(keys & KEY_DOWN) && (lastKeys & KEY_DOWN)) {
            game->getSpeler()->beweegNaarOnder();
            updatePosition();
        } else if (!(keys & KEY_START) && (lastKeys & KEY_START)) {
            aanHetGooien = true;
            TextStream::instance().setText(std::string("gooiend"), 5, 25);
        }
    }
    if (aanHetSpringen and (game->getHuidigVakje() == 3 or game->getHuidigVakje() == 4)) {
        int seed = engine->getTimer()->getTotalMsecs();
        std::uniform_int_distribution<unsigned> u(1, 2);
        std::default_random_engine e(seed * seed); //anders kwam je denk ik te vaak op hetzelfde. Nog eens fatsoenlijk uitzoeken hoe dit zit.
        int random = u(e);

        engine->getTimer()->stop();
        engine->getTimer()->reset();
        engine->getTimer()->start();
        while (engine->getTimer()->getTotalMsecs() < 1000) {}

        if (game->getHuidigVakje() == 3) {
            if (random == 1) {game->getSpeler()->springNaarLinks();}
            else {game->getSpeler()->springNaarRechts();}
        }
        else {
            if (random == 1) {game->getSpeler()->springNaarBoven();}
            else {game->getSpeler()->springNaarOnder();}
        }
        updatePosition();
        aanHetSpringen = false;
    }
    else {
        if (game->getSpeler()->getAlGegooid() and game->getSpeler()->getVakjesNogVerschuiven() == 0) { // nog eens gooien
            if (game->getHuidigVakje() == 1) {game->getSpeler()->setAlGegooid(false);}
            else if (game->getHuidigVakje() == 2) { //Minigame 2
                if (!engine->isTransitioning()) {
                    engine->transitionIntoScene(new Minigame2Screen(engine, game), new FadeOutScene(2));
                }
            }
            else if (game->getHuidigVakje() == 3 or game->getHuidigVakje() == 4) {aanHetSpringen = true;}
            else if (game->getHuidigVakje() == 5) {
                if (game->getSpeler()->getSpel1Gehaald() and game->getSpeler()->getSpel2Gehaald() and game->getSpeler()->getSpel3Gehaald()) {
                    if (!engine->isTransitioning()) {
                        engine->transitionIntoScene(new EndScreen(engine), new FadeOutScene(2));
                    }
                }
                else {
                    game->getSpeler()->setAlGegooid(false);
                }
            }
        }
    }
    lastKeys = keys;
}
// Zoveel logica mag eigenlijk nooit in een update staan, wordt veel te vaak aangeroepen?
void GameScreen::updatePosition() {
    int bgX = 0; //Functies hieronder efficiënter schrijven!!
    int spX = 0;
    int bgY = 0;
    int spY = 0;

    switch (game->getSpeler()->getPosX()) {
        case 0: case 1: case 2:
            bgX = 0;
            break;
        case 3: case 4: case 5: case 6:
            bgX = 1;
            break;
    }
    switch (game->getSpeler()->getPosX()) {
        case 0:
            spX = 0;
            break;
        case 1:
            spX = 1;
            break;
        case 2: case 3:
            spX = 2;
            break;
        case 4:
            spX = 3;
            break;
        case 5:
            spX = 4;
            break;
        case 6:
            spX = 5;
            break;
    }
    switch (game->getSpeler()->getPosY()) {
        case 0: case 1: case 2:
            bgY = 0;
            break;
        case 3:
            bgY = 1;
            break;
            case 4: case 5: case 6:
            bgY = 2;
            break;
    }
    switch (game->getSpeler()->getPosY()) {
        case 0:
            spY = 0;
            break;
        case 1:
            spY = 1;
            break;
        case 2: case 3: case 4:
            spY = 2;
            break;
        case 5:
            spY = 3;
            break;
        case 6:
            spY = 4;
            break;
    }
    spook1Sprite->moveTo(spX*32, spY*32);
    background->scroll(bgX * 32,bgY*32);
    TextStream::instance().setText(std::string(std::to_string(game->getSpeler()->getVakjesNogVerschuiven())), 4, 25);
    TextStream::instance().setText(std::string("#1 " + std::to_string(game->getSpeler()->getSpel1Gehaald())), 6, 25);
    TextStream::instance().setText(std::string("#2 " + std::to_string(game->getSpeler()->getSpel2Gehaald())), 7, 25);
    TextStream::instance().setText(std::string("#3 " + std::to_string(game->getSpeler()->getSpel3Gehaald())), 8, 25);
    engine.get()->enqueueSound(blubikbeneenvis, sizeof(blubikbeneenvis), 64000);

}




