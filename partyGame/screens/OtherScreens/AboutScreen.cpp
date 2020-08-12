//
// Created by michi on 22/03/2020.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "AboutScreen.h"
#include "MainMenuScreen.h"

#include "../../Sprites/wit_spook_1.h"
#include "../../Sprites/wit_spook_2.h"

#include "../../Sprites/redEnemyCenter.h"
#include "../../Sprites/greenEnemyCenter.h"
#include "../../Sprites/blueEnemyCenter.h"

#include "../../Sprites/pijl.h"
#include "../../Sprites/dobbelsteen.h"
#include "../../Sprites/box.h"

#include "../../Sprites/red_stone_with_border.h"
#include "../../Sprites/green_stone_with_border.h"
#include "../../Sprites/blue_stone_with_border.h"

#include "../../Sprites/shared.h"
#include "../../Sprites/alleKleuren.h"



std::vector<Background *> AboutScreen::backgrounds() {
    return {/*background.get()*/}; //als ik hier dat laat staan, crasht ie, omdat dat zelfde naam is als bij de andere? Of gewoon omdat er geen background gecreeerd wordt? Het tweede.
}


std::vector<Sprite *> AboutScreen::sprites() { return {/*spookBlauwSprite.get(), spookGroenSprite.get(),spookRoodSprite.get(),
                                                       spook1Sprite.get(), spook2Sprite.get(), boxSprite.get(), pijlSprite.get(), alleKleurenSprite.get()/*,
                                                       dobbelsteenSprite.get(), */steenRoodSprite.get(), steenGroenSprite.get(),
                                                       steenBlauwSprite.get()};}

void AboutScreen::load() {

    TextStream::instance().setText("AboutScreen", 1, 1);
    TextStream::instance().setText("UP go to the main screen", 3, 1);

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    SpriteBuilder<Sprite> spriteBuilder;

/*
    spook1Sprite = spriteBuilder
            .withData(wit_spook_1Tiles, sizeof(wit_spook_1Tiles))
            .withSize(SIZE_32_32)
            .withAnimated(6, 8)
            .withLocation(0, 0)
            .buildPtr();


    spook2Sprite = spriteBuilder
            .withData(wit_spook_2Tiles, sizeof(wit_spook_2Tiles))
            .withSize(SIZE_32_32)
            .withAnimated(6, 8)
            .withLocation(32, 0)
            .buildPtr();


    spookRoodSprite = spriteBuilder
            .withData(redEnemyCenterTiles, sizeof(redEnemyCenterTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 8)
            .withLocation(64, 0)
            .buildPtr();
    spookGroenSprite = spriteBuilder
            .withData(greenEnemyCenterTiles, sizeof(greenEnemyCenterTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 8)
            .withLocation(0, 32)
            .buildPtr();
    spookBlauwSprite = spriteBuilder
            .withData(blueEnemyCenterTiles, sizeof(blueEnemyCenterTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 8)
            .withLocation(32, 32)
            .buildPtr();

    dobbelsteenSprite = spriteBuilder
            .withData(dobbelsteenTiles, sizeof(dobbelsteenTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 8)
            .withLocation(64, 32)
            .buildPtr();
    pijlSprite = spriteBuilder
            .withData(pijlTiles, sizeof(pijlTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 8)
            .withLocation(0, 64)
            .buildPtr();
    boxSprite = spriteBuilder
            .withData(boxTiles, sizeof(boxTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 8)
            .withLocation(96, 0)
            .buildPtr();*/


    steenRoodSprite = spriteBuilder
            .withData(red_stone_with_borderTiles, sizeof(red_stone_with_borderTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 8)
            .withLocation(32, 64)
            .buildPtr();
    steenRoodSprite->stopAnimating();
    steenGroenSprite = spriteBuilder
            .withData(green_stone_with_borderTiles, sizeof(green_stone_with_borderTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 8)
            .withLocation(64, 64)
            .buildPtr();
    steenGroenSprite->stopAnimating();
    steenBlauwSprite = spriteBuilder
            .withData(blue_stone_with_borderTiles, sizeof(blue_stone_with_borderTiles))
            .withSize(SIZE_32_32)
            .withAnimated(2, 3)
            .withLocation(96, 64)
            .buildPtr();
    steenBlauwSprite->stopAnimating();
/*
    alleKleurenSprite = spriteBuilder
            .withData(alleKleurenTiles, sizeof(alleKleurenTiles))
            .withSize(SIZE_32_32)
            .withAnimated(1, 8)
            .withLocation(130, 100)
            .buildPtr();
*/
}

void AboutScreen::tick(u16 keys) {
    if (firstTick) {
        firstTick = false;
        lastKeys = keys;
        return;
    }

    if (booltje) {// ENTER key, wait until released
        steenBlauwSprite->animateToFrame(1);
        steenRoodSprite->animateToFrame(1);
        steenGroenSprite->animateToFrame(1);
    }
    else {
        steenBlauwSprite->animateToFrame(0);
        steenRoodSprite->animateToFrame(0);
        steenGroenSprite->animateToFrame(0);
    }

    if (!(keys & KEY_START) && (lastKeys & KEY_START)) {
        booltje = !booltje;
    }

        lastKeys = keys;
}