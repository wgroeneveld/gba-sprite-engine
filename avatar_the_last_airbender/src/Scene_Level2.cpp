#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <algorithm>

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
    std::vector<Sprite*> sprites;
    for(auto& ab : airBalls ){
        sprites.push_back(ab->getSprite());
    }
    for(auto& e : enemys ){
        sprites.push_back(e->getEnemySprite());
        sprites.push_back(e->getHealthBarSprite());
    }
    sprites.push_back(aang.get());
    sprites.push_back(someAirBallSprite.get());
    sprites.push_back(someHealthbarSprite.get());
    sprites.push_back(someEnemySprite.get());
    return sprites;
}

void Scene_Level2::removeAirBallsOffScreen() {
    airBalls.erase(
            std::remove_if(airBalls.begin(), airBalls.end(), [](std::unique_ptr<AirBall> &s) { return s->isOffScreen(); }),
            airBalls.end());
}

void Scene_Level2::load() {
    engine.get()->enableText();

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(spritePal, sizeof(spritePal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(backgroundPal, sizeof(backgroundPal)));

    backgroundGround = std::unique_ptr<Background>(new Background(1, background13Tiles, sizeof(background13Tiles),background1Map , sizeof(background1Map), 9, 1, MAPLAYOUT_32X32));
    backgroundSea = std::unique_ptr<Background>(new Background(2, background2Tiles, sizeof(background2Tiles),background2Map , sizeof(background2Map), 25, 2, MAPLAYOUT_32X32));
    backgroundSun = std::unique_ptr<Background>(new Background(3, background13Tiles, sizeof(background13Tiles),background3Map , sizeof(background3Map), 12, 1, MAPLAYOUT_32X64));

    someAirBallSprite = builder
            .withData(airballTiles, sizeof(airballTiles))
            .withSize(SIZE_16_16)
            .withAnimated(2,5)
            .withLocation( GBA_SCREEN_WIDTH+10,GBA_SCREEN_HEIGHT +10)
            .buildPtr();

    someEnemySprite = builder
            .withData(enemyTiles, sizeof(enemyTiles))
            .withSize(SIZE_32_32)
            .withLocation( GBA_SCREEN_WIDTH+10,GBA_SCREEN_HEIGHT +10)
            .buildPtr();

    someHealthbarSprite = builder
            .withData(healthbarenemyTiles, sizeof(healthbarenemyTiles))
            .withSize(SIZE_16_8)
            .withLocation( GBA_SCREEN_WIDTH+10,GBA_SCREEN_HEIGHT +10)
            .buildPtr();

    aang = builder
            .withData(aangTiles, sizeof(aangTiles))
            .withSize(SIZE_32_32)
            .withLocation(20,81)
            .buildPtr();
    aang->setStayWithinBounds(true);


    healthAang = 100;
    enemySpawn=0;
}

double attackCounter2 =0;

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
    if (keys & KEY_A) {
        if (!isJumping) isJumping = true;
    }
    if (keys & KEY_B) {
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

    ////COLLISION DETECION AANG AND ENEMY ////
    if(isAttacking) {
        for (auto &e: enemys) {
            if (attackCounter2 >= 40 && aang.get()->collidesWith(*e->getEnemySprite())) {
                e->updateHealth(e->getHealth()-1);
                if(e->getHealth()<=0) {
                    enemys.erase(enemys.begin() + 1); //TODO dit klopt nog niet, werkt alleen als er maar enen is
                    engine.get()->updateSpritesInScene();
                }
                attackCounter2 = 0;
            }
            if (!aang->isAnimating()) aang->makeAnimated(5, 4, 12);
        }
    }else {
        for(auto &e : enemys){
            if (attackCounter2 >= 40 && aang.get()->collidesWith(*e->getEnemySprite())) {
                healthAang--;
                attackCounter2 = 0;
            }
        }
    }


    ///AIRBALL-SHOOTING + END OF ATTACK ACTION///
    // TODO zorg dat tijdens het doen van de attack functie deze gegevens niet wordne opgehaald zodat aang vlotter kan slaan
    int oldAirBallsSize = airBalls.size();
    removeAirBallsOffScreen();
    TextStream::instance().setText(std::string("Amount of airBalls: ") + std::to_string(airBalls.size()), 1, 1);
    if(aang->getCurrentFrame() > 7) {
        isAttacking = false;
        aang->stopAnimating();
        aang->animateToFrame(0);

        // een airball afschieten:
        if(airBalls.size() < 10) {
            airBalls.push_back(createAirBall(isWalkingLeft));
            airBalls.at(airBalls.size()-1).get()->getSprite()->makeAnimated(0,2,10);
        }
    }


    if(oldAirBallsSize != airBalls.size()) {
        engine.get()->updateSpritesInScene();
    }

    for(auto &ab : airBalls) {
        ab->tick();
    }


    ////COLLISION DETECION ENEMY AND AIRBAL ////

    int positionToBeDeleted=-1;
    if(airBalls.size() > 0){

        int position =0;
        for(auto& ab : airBalls){
            for(auto& e : enemys) {
                if (attackCounter2 >= 40 && ab.get()->getSprite()->collidesWith(*e->getEnemySprite())) {
                    e->updateHealth(e->getHealth()-1);
                    if(e->getHealth()<=0){
                        enemys.erase(enemys.begin()+1); //dit klopt nog niet, werkt alleen als er maar enen is
                        engine.get()->updateSpritesInScene();
                    }
                    attackCounter2 = 0;
                    positionToBeDeleted = position;
                }
                position++;
            }
        }

    }

    if(positionToBeDeleted>=0) {
        airBalls.erase(airBalls.begin()+positionToBeDeleted);
        engine.get()->updateSpritesInScene();
    }

    ////// ENEMY //////
    TextStream::instance().setText(std::string("Next enemy will spawn in ") + std::to_string(enemySpawn), 1, 1);
    int oldEnemysSize = enemys.size();
    if(enemySpawn<=0){
        enemys.push_back(createNewEnemy());
        enemySpawn=400;
    }else{
        enemySpawn--;
    }

    if(oldEnemysSize != enemys.size()) {
        engine.get()->updateSpritesInScene();
    }

    for(auto &e: enemys){
        if(e.get()->getEnemySprite()->getX()>aang.get()->getX()){
            e->setDirectionIsLeft(true);
        }else e->setDirectionIsLeft(false);
        e->tick();
    }


    attackCounter2++;


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
        for(auto& e: enemys) {
            e->getEnemySprite()->moveTo(e->getEnemySprite()->getX() + xVelocity,
                                            e->getEnemySprite()->getY());
            e->getHealthBarSprite()->moveTo(e->getHealthBarSprite()->getX() + xVelocity,
                                        e->getHealthBarSprite()->getY());
        }
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
        for(auto& e: enemys) {
            e->getEnemySprite()->moveTo(e->getEnemySprite()->getX() - xVelocity,
                                            e->getEnemySprite()->getY());
            e->getHealthBarSprite()->moveTo(e->getHealthBarSprite()->getX() - xVelocity,
                                        e->getHealthBarSprite()->getY());

        }
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

std::unique_ptr<AirBall> Scene_Level2::createAirBall(bool directionTogo) {
    if(isWalkingLeft){
        return std::unique_ptr<AirBall>(new AirBall(builder
                                                            .withLocation(aang->getX() - aang->getWidth() / 2, aang->getY() + aang->getHeight() / 4)
                                                            .buildWithDataOf(*someAirBallSprite.get()), directionTogo));

    }else{
        return std::unique_ptr<AirBall>(new AirBall(builder
        .withLocation(aang->getX() + aang->getWidth() / 2, aang->getY() + aang->getHeight() / 4)
                                                            .buildWithDataOf(*someAirBallSprite.get()), directionTogo));
    }
}


std::unique_ptr<Enemy> Scene_Level2::createNewEnemy() {
    return std::unique_ptr<Enemy>(new Enemy(   builder.withSize(SIZE_32_32)
                                                       .withLocation(200,85)
                                                       .buildWithDataOf(*someEnemySprite.get()),
                                               builder.withSize(SIZE_16_8)
                                                       .withLocation(208,80)
                                                       .buildWithDataOf(*someHealthbarSprite.get())));

}