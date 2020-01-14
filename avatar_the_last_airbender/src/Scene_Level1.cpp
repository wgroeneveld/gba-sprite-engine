#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <algorithm>

#include "Scene_Level1.h"

#include "data/sprites/sprite_aangdown.h"
#include "data/sprites/sprite_aangup.h"
#include "data/sprites/sprite_enemy.h"
#include "data/sprites/sprite_pal.h"
#include "data/sprites/sprite_airball.h"
#include "data/sprites/sprite_healthbarenemy.h"

#include "data/background_game/backgroundGround/background13_set.h"
#include "data/background_game/backgroundGround/background1_map.h"
#include "data/background_game/backgroundSea/background2_set.h"
#include "data/background_game/backgroundSea/background2_map.h"
#include "data/background_game/backgroundSun/background3_map.h"
#include "data/background_game/background_pal.h"

#include "math.h"
#include "../../engine/include/libgba-sprite-engine/background/text_stream.h"

std::vector<Background *> Scene_Level1::backgrounds() {
    return {  backgroundGround.get(), backgroundSea.get(), backgroundSun.get()};
}

std::vector<Sprite *> Scene_Level1::sprites() {
    std::vector<Sprite*> sprites;
    for(auto& ab : airBalls ){
        sprites.push_back(ab->getSprite());
    }
    for(auto& e : enemys ){
        sprites.push_back(e->getEnemySprite());
        sprites.push_back(e->getHealthBarSprite());
    }
    sprites.push_back(aangDown.get());
    sprites.push_back(aangUp.get());
    sprites.push_back(someAirBallSprite.get());
    sprites.push_back(someHealthbarSprite.get());
    sprites.push_back(someEnemySprite.get());
    return sprites;
}

void Scene_Level1::removeAirBallsOffScreen() {
    airBalls.erase(
            std::remove_if(airBalls.begin(), airBalls.end(), [](std::unique_ptr<AirBall> &s) { return s->isOffScreen(); }),
            airBalls.end());
}

void Scene_Level1::load() {
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
            .withSize(SIZE_32_64)
            .withLocation( GBA_SCREEN_WIDTH+10,GBA_SCREEN_HEIGHT +10)
            .buildPtr();

    someHealthbarSprite = builder
            .withData(healthbarenemyTiles, sizeof(healthbarenemyTiles))
            .withSize(SIZE_16_8)
            .withLocation( GBA_SCREEN_WIDTH+10,GBA_SCREEN_HEIGHT +10)
            .buildPtr();

    aangDown = builder
            .withData(aangDownTiles, sizeof(aangDownTiles))
            .withSize(SIZE_64_32)
            .withLocation(20,86)
            .buildPtr();
    aangDown->setStayWithinBounds(true);

    aangUp = builder
            .withData(aangUpTiles, sizeof(aangUpTiles))
            .withSize(SIZE_64_32)
            .withLocation(GBA_SCREEN_WIDTH+10,GBA_SCREEN_HEIGHT+10)
            .buildPtr();
    aangDown->setStayWithinBounds(true);


    healthAang = 100;
    enemySpawn=0;
}

double attackCounter2 =0;

void Scene_Level1::tick(u16 keys) {
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
        if (!isJumping) {
            isJumping = true;
            aangUp->setBeginFrame(0);
        }
    }
    if (keys & KEY_B) {
        if (!isAttacking && !isJumping) {
            isAttacking = true;
            aangUp->setBeginFrame(3);
        }
    }
    if (isWalkingLeft && !isAttacking) {
        aangDown->flipHorizontally(true);
        aangUp->flipHorizontally(true);
        if (!aangDown->isAnimating()) {
            aangDown->makeAnimated(1, 2, 10);
        }
        if (aangDown->getX() > 30) {
            moveAang();
        } else {
            moveOthers();
        }
    }

    if (isWalkingRight && !isAttacking) {
        aangDown->flipHorizontally(false);
        aangUp->flipHorizontally(false);
        if (!aangDown->isAnimating()) {
            aangDown->makeAnimated(1, 2, 10);
        }
        if (aangDown->getX() < 190) {
            moveAang();
        } else {
            moveOthers();
        }
    }

    if (((!isWalkingLeft && !isWalkingRight) || isJumping || isAttacking) && aangDown->isAnimating() &&
        (aangDown->getCurrentFrame() == 1 || aangDown->getCurrentFrame() == 2)) {
        aangDown->stopAnimating();
        aangDown->animateToFrame(0);
    }


    if (isJumping) {
        if (!aangDown->isAnimating()) {
            aangDown->makeAnimated(3, 2, 15);
            aangUp->makeAnimated(2, 15);
        }

        yVelocity = -(pow(((0.25 * time) - 3), 2)) + ((2 * time) - 3) + 12;
        int yPosition = 83 - yVelocity;
        aangDown->moveTo(aangDown->getX(), yPosition);
        aangUp->moveTo(aangDown->getX(), yPosition - 32);

        if (aangDown->getY() != 86) {
            time++;
        } else {
            isJumping = false;
            time = 1;
            aangDown->stopAnimating();
            aangDown->animateToFrame(0);
            aangUp->stopAnimating();
            aangUp->moveTo(GBA_SCREEN_WIDTH + 10, GBA_SCREEN_HEIGHT + 10);
        }
    }

    ////COLLISION DETECION AANG AND ENEMY ////
    if (isAttacking) {
        for (auto &e: enemys) {
            if (attackCounter2 >= 40 && aangDown.get()->collidesWith(*e->getEnemySprite())) {
                e->updateHealth(e->getHealth() - 1);
                if (e->getHealth() <= 0) {
                    enemys.erase(enemys.begin() + 1); //TODO dit klopt nog niet, werkt alleen als er maar enen is
                    engine.get()->updateSpritesInScene();
                }
                attackCounter2 = 0;
            }
        }
        if (!aangDown->isAnimating()) {
            aangDown->makeAnimated(5, 4, 20);
        }
    } else {
        for (auto &e : enemys) {
            if (attackCounter2 >= 40 && aangDown.get()->collidesWith(*e->getEnemySprite())) {
                healthAang--;
                attackCounter2 = 0;
            }
        }
    }

    if (isAttacking && aangDown->getCurrentFrame() == 6) {
        aangUp->animateToFrame(2);
    }
    if (isAttacking && aangUp->getCurrentFrame() == 2) {
        aangUp->makeAnimated(2, 20);
        aangUp->moveTo(aangDown->getX(), aangDown->getY() - 32);
    }




    ///AIRBALL-SHOOTING + END OF ATTACK ACTION///
    // TODO zorg dat tijdens het doen van de attack functie deze gegevens niet wordne opgehaald zodat aang vlotter kan slaan
    int oldAirBallsSize = airBalls.size();
    removeAirBallsOffScreen();
    TextStream::instance().setText(std::string("Amount of airBalls: ") + std::to_string(airBalls.size()), 1, 1);
    if (aangDown->getCurrentFrame() > 7) {
        aangDown->animateToFrame(7);
        isAttacking = false;
        aangDown->stopAnimating();
        aangDown->animateToFrame(0);
        aangUp->moveTo(GBA_SCREEN_WIDTH + 10, GBA_SCREEN_HEIGHT + 10);



        // een airball afschieten:
        if (airBalls.size() < 10) {
            airBalls.push_back(createAirBall(isWalkingLeft));

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
        enemySpawn=5000;
    }else{
        enemySpawn--;
    }

    if(oldEnemysSize != enemys.size()) {
        engine.get()->updateSpritesInScene();
    }

    for(auto &e: enemys){
        if(e.get()->getEnemySprite()->getX()>aangDown.get()->getX()){
            e->setDirectionIsLeft(true);
        }else e->setDirectionIsLeft(false);
        e->tick();
    }


    attackCounter2++;


}


void Scene_Level1::moveAang() {
    if (isWalkingLeft && !isAttacking) {
        aangDown->moveTo(aangDown->getX() - xVelocity, aangDown->getY());
        if(isJumping) {
            aangUp->moveTo(aangDown->getX() - xVelocity, aangDown->getY()-32);
        }
    }

    if (isWalkingRight && !isAttacking) {
        aangDown->moveTo(aangDown->getX() + xVelocity, aangDown->getY());
        if(isJumping) {
            aangUp->moveTo(aangDown->getX() + xVelocity, aangDown->getY()-32);
        }
    }
}


void Scene_Level1::moveOthers() {
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

std::unique_ptr<AirBall> Scene_Level1::createAirBall(bool directionTogo) {
    if(isWalkingLeft){
        return std::unique_ptr<AirBall>(new AirBall(builder
                                                            .withLocation(aangDown->getX() - aangDown->getWidth() / 2, aangDown->getY() + aangDown->getHeight() / 4)
                                                            .buildWithDataOf(*someAirBallSprite.get()), directionTogo));

    }else{
        return std::unique_ptr<AirBall>(new AirBall(builder
        .withLocation(aangDown->getX() + aangDown->getWidth() / 2, aangDown->getY() + aangDown->getHeight() / 4)
                                                            .buildWithDataOf(*someAirBallSprite.get()), directionTogo));
    }
}


std::unique_ptr<Enemy> Scene_Level1::createNewEnemy() {
    return std::unique_ptr<Enemy>(new Enemy(   builder.withSize(SIZE_32_32)
                                                       .withLocation(200,60)
                                                       .buildWithDataOf(*someEnemySprite.get()),
                                               builder.withSize(SIZE_16_8)
                                                       .withLocation(208,65)
                                                       .buildWithDataOf(*someHealthbarSprite.get())));

}