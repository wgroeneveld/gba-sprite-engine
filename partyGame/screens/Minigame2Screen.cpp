//
// Created by michi on 15/07/2020.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Minigame2Screen.h"
#include "../img/hoofdpersonage.h"
#include <libgba-sprite-engine/gba/tonc_memdef.h>

void Minigame2Screen::load() {
    TextStream::instance().setText(std::string("Score"), 1, 25);
    TextStream::instance().setText(std::string(std::to_string(game.getPositieX())), 2, 25);
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(hoofdpersonagePal, sizeof(hoofdpersonagePal)));

    SpriteBuilder<Sprite> spriteBuilder;

    ufo = spriteBuilder
            .withData(hoofdpersonageTiles, sizeof(hoofdpersonageTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 40)
            .withLocation(0, 64)
            .buildPtr();
}
std::vector<Sprite *> Minigame2Screen::sprites() {
    return {ufo.get()};

}

std::vector<Background *> Minigame2Screen::backgrounds() {
    return {/*background.get()*/};
}

void Minigame2Screen::tick(u16 keys) {

    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (!(keys & KEY_UP) && (lastKeys & KEY_UP)) {// ENTER key, wait until released
        bezig = false;
        TextStream::instance().setText(std::string("Gedaan"), 2, 25);
    }

    if (bezig) {
        game.beweeg();
        updatePosition();
        TextStream::instance().setText(std::string(std::to_string(game.getPositieX())), 2, 25);
    }
    else {
        TextStream::instance().setText(std::string("Gedaan"), 2, 10);
    }

    lastKeys = keys;

}
void Minigame2Screen::updatePosition() {
   ufo.get()->moveTo(game.getPositieX(), 64);
}