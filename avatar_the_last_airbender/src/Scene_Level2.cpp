#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>

#include "Scene_Level2.h"

#include "sprites/sprite_aang.h"
#include "sprites/sprite_enemy.h"
#include "sprites/sprite_pal.h"
#include "sprites/sprite_airball.h"

#include "background_game/background1_set.h"
#include "background_game/background1_map.h"
#include "background_game/background2_set.h"
#include "background_game/background2_map.h"
#include "background_game/background3_set.h"
#include "background_game/background3_map.h"
#include "background_game/background_pal.h"

#include "math.h"

std::vector<Background *> Scene_Level2::backgrounds() {
    return {  backgroundGround.get(), backgroundSea.get(), backgroundSun.get()};
}

std::vector<Sprite *> Scene_Level2::sprites() {
    std::vector<Sprite*> sprites;
    sprites.push_back(aang.get());
    sprites.push_back(enemy.get());
    return sprites;
}

void Scene_Level2::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(spritesPal, sizeof(spritesPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(backgroundPal, sizeof(backgroundPal)));

    backgroundGround = std::unique_ptr<Background>(new Background(1, background1Tiles, sizeof(background1Tiles),background1Map , sizeof(background1Map), 9, 1, MAPLAYOUT_32X32));
    backgroundSea = std::unique_ptr<Background>(new Background(2, background2Tiles, sizeof(background2Tiles),background2Map , sizeof(background2Map), 20, 2, MAPLAYOUT_32X32));
    backgroundSun = std::unique_ptr<Background>(new Background(3, background3Tiles, sizeof(background3Tiles),background3Map , sizeof(background3Map), 21, 3, MAPLAYOUT_32X32));

    SpriteBuilder<Sprite> builder;

    aang = builder
            .withData(aangTiles, sizeof(aangTiles))
            .withSize(SIZE_32_32)
            .withLocation(100,81)
            .buildPtr();

    enemy = builder
            .withData(enemyTiles, sizeof(enemyTiles))
            .withSize(SIZE_32_32)
            .withLocation(150,75)
            .buildPtr();
}

void Scene_Level2::tick(u16 keys) {
    if (keys & KEY_LEFT) {
        if (!isWalkingLeft) isWalkingLeft = true;
    } else {
        isWalkingLeft = false;
    }
    if (keys & KEY_RIGHT) {
        if (!isWalkingRight) isWalkingRight = true;
    } else {
        isWalkingRight = false;
    }
    if (keys & KEY_UP) {
        if (!isJumping) isJumping = true;
    }
    if (keys & KEY_DOWN) {
        if (!isAttacking && !isJumping) isAttacking = true;
    }
    if (isWalkingLeft && !isAttacking) {
        aang->flipHorizontally(true);
        //aang->moveTo(aang->getX() - xVelocity, aang->getY());
        xScrolling--;
        backgroundGround.get()->scroll(xScrolling * 2/3,0);
        backgroundSea.get()->scroll(xScrolling * 1/3,0);
        if (!aang->isAnimating()) aang->makeAnimated(1, 2, 10);

    }

    if (isWalkingRight && !isAttacking) {
        aang->flipHorizontally(false);
        //aang->moveTo(aang->getX() + xVelocity, aang->getY());
        xScrolling++;
        backgroundGround.get()->scroll(xScrolling * 2/3,0);
        backgroundSea.get()->scroll(xScrolling * 1/3,0);
        if (!aang->isAnimating()) aang->makeAnimated(1, 2, 10);
    }

    if (((!isWalkingLeft && !isWalkingRight) || isJumping || isAttacking) && aang->isAnimating() &&
        (aang->getCurrentFrame() == 1 || aang->getCurrentFrame() == 2)) {
        aang->stopAnimating();
        aang->animateToFrame(0);
    }


    if (isJumping) {
        yVelocity = -(pow(((0.25 * time) - 3), 2)) + ((2 * time) - 3) + 12;
        int yPosition = 83 - yVelocity;
        aang->moveTo(aang->getX(), yPosition);

        if (!aang->isAnimating()) aang->makeAnimated(3, 2, 15);

        if (aang->getY() != 83) {
            time++;
        } else {
            isJumping = false;
            time = 1;
            aang->stopAnimating();
            aang->animateToFrame(0);
        }
    }
}