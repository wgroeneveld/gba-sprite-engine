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
#include "sprites/sprite_healthbarenemy.h"

#include "background_game/backgroundGround/background13_set.h"
#include "background_game/backgroundGround/background1_map.h"
#include "background_game/backgroundSea/background2_set.h"
#include "background_game/backgroundSea/background2_map.h"
#include "background_game/backgroundSun/background3_map.h"
#include "background_game/background_pal.h"

#include "math.h"
#include "../../engine/include/libgba-sprite-engine/background/text_stream.h"

std::vector<Background *> Scene_Level2::backgrounds() {
    return {  backgroundGround.get(), backgroundSea.get(), backgroundSun.get()};
}

std::vector<Sprite *> Scene_Level2::sprites() {
    enemy = createNewEnemy();
    std::vector<Sprite*> sprites;
    sprites.push_back(aang.get());
    sprites.push_back(enemy->getEnemySprite());
    sprites.push_back(enemy->getHealthBarSprite());
    return sprites;
}

void Scene_Level2::load() {
    engine.get()->enableText();

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(spritePal, sizeof(spritePal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(backgroundPal, sizeof(backgroundPal)));

    backgroundGround = std::unique_ptr<Background>(new Background(1, background13Tiles, sizeof(background13Tiles),background1Map , sizeof(background1Map), 9, 1, MAPLAYOUT_32X32));
    backgroundSea = std::unique_ptr<Background>(new Background(2, background2Tiles, sizeof(background2Tiles),background2Map , sizeof(background2Map), 25, 2, MAPLAYOUT_32X32));
    backgroundSun = std::unique_ptr<Background>(new Background(3, background13Tiles, sizeof(background13Tiles),background3Map , sizeof(background3Map), 12, 1, MAPLAYOUT_32X64));

    aang = builder
            .withData(aangTiles, sizeof(aangTiles))
            .withSize(SIZE_32_32)
            .withLocation(100,90)
            .buildPtr();



    healthbarenemy = builder
            .withData(healthbarenemyTiles, sizeof(healthbarenemyTiles))
            .withSize(SIZE_16_8)
            .withLocation(158,80)
            .buildPtr();
}

void Scene_Level2::tick(u16 keys) {
    //TextStream::instance().setText( std::string(" x: ") + std::to_string(aang->getX()), 3, 1);

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
        if (!aang->isAnimating()) aang->makeAnimated(1, 2, 10);
        if(aang->getX() > 30) {
            moveAang();
        }
        else {
            moveOthers();
        }
    }

    if (isWalkingRight && !isAttacking) {
        aang->flipHorizontally(false);
        if (!aang->isAnimating()) aang->makeAnimated(1, 2, 10);
        if(aang->getX() < 190) {
            moveAang();
        }
        else {
            moveOthers();
        }
    }

    if (((!isWalkingLeft && !isWalkingRight) || isJumping || isAttacking) && aang->isAnimating() &&
        (aang->getCurrentFrame() == 1 || aang->getCurrentFrame() == 2)) {
        aang->stopAnimating();
        aang->animateToFrame(0);
    }


    if (isJumping) {
        if (!aang->isAnimating()) aang->makeAnimated(3, 2, 15);

        yVelocity = -(pow(((0.25 * time) - 3), 2)) + ((2 * time) - 3) + 12;
        int yPosition = 83 - yVelocity;
        aang->moveTo(aang->getX(), yPosition);

        if (aang->getY() != 90) {
            time++;
        } else {
            isJumping = false;
            time = 1;
            aang->stopAnimating();
            aang->animateToFrame(0);
        }
    }
}


void Scene_Level2::moveAang() {
    if (isWalkingLeft && !isAttacking) {
        aang->moveTo(aang->getX() - xVelocity, aang->getY());
    }

    if (isWalkingRight && !isAttacking) {
        aang->moveTo(aang->getX() + xVelocity, aang->getY());
    }
}


void Scene_Level2::moveOthers() {
    if (isWalkingLeft && !isAttacking) {
        enemy->getEnemySprite()->moveTo(enemy->getEnemySprite()->getX() + xVelocity, enemy->getEnemySprite()->getY());
        xScrollingGround--;
        backgroundGround.get()->scroll(xScrollingGround,0);
        if(xScrollingGround%3 == 0) {
            xScrollingSea--;
            backgroundSea.get()->scroll(xScrollingSea,0);
        }
        if(xScrollingGround%10 == 0) {
            xScrollingSun--;
            if(xScrollingSun > -190) backgroundSun.get()->scroll(xScrollingSun,0);
        }
    }

    if (isWalkingRight && !isAttacking) {
        enemy->getEnemySprite()->moveTo(enemy->getEnemySprite()->getX() - xVelocity, enemy->getEnemySprite()->getY());
        xScrollingGround++;
        backgroundGround.get()->scroll(xScrollingGround, 0);
        if (xScrollingGround % 3 == 0) {
            xScrollingSea++;
            backgroundSea.get()->scroll(xScrollingSea, 0);
        }
        if (xScrollingGround % 10 == 0) {
            xScrollingSun++;
            if (xScrollingSun < 80) backgroundSun.get()->scroll(xScrollingSun, 0);
        }
    }
}

std::unique_ptr<Enemy> Scene_Level2::createNewEnemy() {
    return std::unique_ptr<Enemy>(new Enemy(   builder.withSize(SIZE_32_32)
                                                       .withLocation(150,85)
                                                       .buildWithDataOf(*enemy->getEnemySprite()),
                                               builder.withSize(SIZE_16_8)
                                                       .withLocation(158,80)
                                                       .buildWithDataOf(*enemy->getHealthBarSprite())));

}