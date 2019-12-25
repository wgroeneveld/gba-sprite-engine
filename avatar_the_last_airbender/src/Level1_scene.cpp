//
// Created by woute on 9/12/2019.
//

#include "Level1_scene.h"
#include "background_game/background_water.h"
#include "background_game/background_earth_tilemap.h"
#include "background_game/background_earth_data.h"

#include "grit/aang.h"
#include "grit/enemy.h"
#include "grit/shared.h"

#include "math.h"
#include "grit/air_ball.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>

std::vector<Background *> Level1_scene::backgrounds() {
    //return { background.get()};
    return {};
}

std::vector<Sprite *> Level1_scene::sprites() {
    std::vector<Sprite*> sprites;


    sprites.push_back(airBall.get());
    sprites.push_back(enemy.get());
    sprites.push_back(aang.get());
    return { sprites};
}

void Level1_scene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal2, sizeof(sharedPal2)));

   //backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(background_earth_data2Pal, sizeof(background_earth_data2Pal)));

    //background = std:: unique_ptr<Background>(new Background(0, background_earth_data2Tiles, sizeof(background_earth_data2Tiles),background_earth_tilemap , sizeof(background_earth_tilemap)));
    //background.get()->useMapScreenBlock(64);

    SpriteBuilder<Sprite> builder;
    SpriteBuilder<AffineSprite> affBuilder;


    airBall = affBuilder
            .withData(air_setTiles, sizeof(air_setTiles))
            .withSize(SIZE_32_32)
            .withLocation(100,80)
            .buildPtr();

    enemy = builder
            .withData(enemyTiles2, sizeof(enemyTiles2))
            .withSize(SIZE_64_64)
            .withLocation(150,80)
            .buildPtr();

    aang = builder
            .withData(aangTiles2, sizeof(aangTiles2))
            .withSize(SIZE_64_64)
            .withLocation(50, 80)
            .buildPtr();
    aang->setStayWithinBounds(true);


    //enemy->makeAnimated(1, 2, 15);



    airBall->makeAnimated(2, 15);
    airBall.get()->rotate(90);


}

int xVelocity = 1;
double yVelocity;
int time = 1;
int countEnemy = 1;

bool isWalkingLeft;
bool isWalkingRight;
bool isJumping;
bool isAttacking;

void Level1_scene::tick(u16 keys) {

    if(keys & KEY_LEFT) {
        if(!isWalkingLeft) isWalkingLeft = true;
    }
    else {
        isWalkingLeft = false;
    }
    if(keys & KEY_RIGHT) {
        if(!isWalkingRight) isWalkingRight = true;
    }
    else {
        isWalkingRight = false;
    }
    if(keys & KEY_UP) {
        if(!isJumping) isJumping = true;
    }
    if(keys & KEY_DOWN) {
        if(!isAttacking && !isJumping) isAttacking = true;
    }

    if(isWalkingLeft && !isAttacking) {
        aang->flipHorizontally(true);
        aang->moveTo(aang->getX() - xVelocity, aang->getY());
        if(!aang->isAnimating()) aang->makeAnimated(1,2,10);
    }

    if(isWalkingRight && !isAttacking) {
        aang->flipHorizontally(false);
        aang->moveTo(aang->getX() + xVelocity, aang->getY());
        if(!aang->isAnimating()) aang->makeAnimated(1,2,10);
    }

    if(((!isWalkingLeft && !isWalkingRight) || isJumping || isAttacking) && aang->isAnimating() && (aang->getCurrentFrame() == 1 || aang->getCurrentFrame() == 2)) {
        aang->stopAnimating();
        aang->animateToFrame(0);
    }


    if(isJumping) {
        yVelocity = -(pow(((0.2 * time) - 3),2))+((2*time)-3)+12;
        int yPosition = 83 - yVelocity;
        aang->moveTo(aang->getX(), yPosition);

        if(!aang->isAnimating()) aang->makeAnimated(3, 2, 15);

        if(aang->getY() != 83) {
            time++;
        }
        else {
            isJumping = false;
            time = 1;
            aang->stopAnimating();
            aang->animateToFrame(0);
        }
    }

    if(isAttacking) {
        if(!aang->isAnimating()) aang->makeAnimated(5, 4, 12);
    }

    if(aang->getCurrentFrame() > 7) {
        isAttacking = false;
        aang->stopAnimating();
        aang->animateToFrame(0);
    }


    ///////////
    ///ENEMY///
    ///////////

    if(countEnemy>=100){
        countEnemy =0;
        enemy->moveTo(enemy->getX() -5, enemy->getY());
        enemy->flipHorizontally(true);

        //if(aang->collidesWith(enemy.get())){

        //}
    } else{
        countEnemy++;
    }
}