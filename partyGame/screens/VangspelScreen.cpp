//
// Created by michi on 27/04/2020.
//

#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "VangspelScreen.h"
#include "../img/hoofdpersonage.h"

std::vector<Background *> VangspelScreen::backgrounds() {
    return {/*background.get()*/}; }


std::vector<Sprite *> VangspelScreen::sprites() {
    return {vallendVoorwerp1Sprite.get()};
}

void VangspelScreen::load() {
    Minigame1 *minigame = new Minigame1(engine);
    TextStream::instance().setText("Ik speel een spel.", 1, 1);
    TextStream::instance().setText("Ik speel een spel.", 1, 1);

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(hoofdpersonagePal, sizeof(hoofdpersonagePal)));

    SpriteBuilder<Sprite> spriteBuilder;



    vallendVoorwerp1Sprite = spriteBuilder
            .withData(hoofdpersonageTiles, sizeof(hoofdpersonageTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 40)
            .withLocation(0, 0)
            .buildPtr();


}

void VangspelScreen::tick(u16 keys) {
    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }




    lastKeys = keys;


}

void VangspelScreen::updateSprite() {
    vallendVoorwerp1Sprite.get()->moveTo(minigame.getVoorwerp(1).getPositieX(),minigame.getVoorwerp(1).getPositieX());
}
