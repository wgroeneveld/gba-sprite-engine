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
#include "data/sprites/sprite_healthbaraang.h"

#include "data/background_game/backgroundGround/background13_set.h"
#include "data/background_game/backgroundGround/background1_map.h"
#include "data/background_game/backgroundSea/background2_set.h"
#include "data/background_game/backgroundSea/background2_map.h"
#include "data/background_game/backgroundSun/background3_map.h"
#include "data/background_game/background_pal.h"

#include "math.h"
#include "End_scene.h"

std::vector<Background *> Scene_Level1::backgrounds() {
    return {  backgroundGround.get(), backgroundSea.get(), backgroundSun.get()};
}

std::vector<Sprite *> Scene_Level1::sprites() {
    std::vector<Sprite*> sprites;


    for(auto& ab : airBalls ){  // lijst van Airballs afgaan en elke sprite renderen
        sprites.push_back(ab->getSprite());
    }

    for(auto& e : enemys ){  // lijst van Enenmys afgaan en elke sprite renderen
        sprites.push_back(e->getEnemySprite());
        sprites.push_back(e->getHealthBarSprite());
    }
     // Aang + dd healthbar van aang renderen
        sprites.push_back(aang->getAangDownSprite());
        sprites.push_back(aang->getAangUpSprite());
        sprites.push_back(aang->getHealthBarSprite());

    //Een voorbeeld sprite laden voor airbal en enemy zodat hier instances van genomen kunnen worden
    sprites.push_back(someAirBallSprite.get());
    sprites.push_back(someHealthbarEnemySprite.get());
    sprites.push_back(someEnemySprite.get());


    return sprites;
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

    someHealthbarEnemySprite = builder
            .withData(healthbarenemyTiles, sizeof(healthbarenemyTiles))
            .withSize(SIZE_16_8)
            .withLocation( GBA_SCREEN_WIDTH+10,GBA_SCREEN_HEIGHT +10)
            .buildPtr();


    aang = std::unique_ptr<Aang>(new Aang(   builder
                                                     .withData(aangDownTiles, sizeof(aangDownTiles))
                                                     .withSize(SIZE_64_32)
                                                     .withLocation( 20,83)
                                                     .buildPtr(),
                                             builder
                                                     .withData(aangUpTiles, sizeof(aangUpTiles))
                                                     .withSize(SIZE_64_32)
                                                     .withLocation( GBA_SCREEN_WIDTH+10,GBA_SCREEN_HEIGHT +10)
                                                     .buildPtr(),
                                             builder
                                                     .withData(healthbarAangTiles, sizeof(healthbarAangTiles))
                                                     .withSize(SIZE_32_16)
                                                     .withLocation( 10,10)
                                                     .buildPtr()
                                                     ));

    //healthAang = 100;
    enemySpawn=0;
}

double attackCounter2 =0;

void Scene_Level1::tick(u16 keys) {
    aang->tick(keys);

    if (aang->isMoveOthers()) {
        moveOthers();
    }

    ////COLLISION DETECION AANG AND ENEMY ////
    if (aang->isAttacking()) {
        for (auto &e: enemys) {
            if (attackCounter2 >= 40 && aang->getAangDownSprite()->collidesWith(*e->getEnemySprite())) {
                e->updateHealth(e->getHealth() - 1);
                if (e->getHealth() <= 0) {
                    enemys.erase(enemys.begin() + 1); //TODO dit klopt nog niet, werkt alleen als er maar enen is
                    engine.get()->updateSpritesInScene();
                    amountEnemysKilled++;
                }
                attackCounter2 = 0;
            }
        }
        if (!aang->getAangDownSprite()->isAnimating()) {
            aang->getAangDownSprite()->makeAnimated(5, 4, 20);
        }
    } else {
        for (auto &e : enemys) {
            if (attackCounter2 >= 40 && aang->getAangDownSprite()->collidesWith(*e->getEnemySprite())) {
                aang->setHealth(aang->getHealth()-1);
                if(aang->getHealth()<=0){
                    auto End_scene = new ::End_scene(engine, amountEnemysKilled);
                    engine->transitionIntoScene(End_scene, new FadeOutScene(2));
                }
                attackCounter2 = 0;
            }
        }
    }

    if (aang->isAttacking() && aang->getAangDownSprite()->getCurrentFrame() == 6) {
        aang->getAangUpSprite()->animateToFrame(2);
    }
    if (aang->isAttacking() && aang->getAangUpSprite()->getCurrentFrame() == 2) {
        aang->getAangUpSprite()->makeAnimated(2, 20);
        aang->getAangUpSprite()->moveTo(aang->getAangDownSprite()->getX(), aang->getAangDownSprite()->getY() - 32);
    }




    ///AIRBALL-SHOOTING + END OF ATTACK ACTION///
    // TODO zorg dat tijdens het doen van de attack functie deze gegevens niet wordne opgehaald zodat aang vlotter kan slaan
    int oldAirBallsSize = airBalls.size();
    removeAirBallsOffScreen();
    if (aang->getAangDownSprite()->getCurrentFrame() > 7) {
        // een airball afschieten:
        if (airBalls.size() < 10) { //max 10 ballen op het scherm
            airBalls.push_back(createAirBall(aang->isWalkingLeft()));
        }
        aang->getAangDownSprite()->animateToFrame(7);
        aang->stopAttacking();
        aang->getAangDownSprite()->stopAnimating();
        aang->getAangDownSprite()->animateToFrame(0);
        aang->getAangUpSprite()->stopAnimating();
        aang->getAangUpSprite()->moveTo(GBA_SCREEN_WIDTH + 10, GBA_SCREEN_HEIGHT + 10);
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
                        amountEnemysKilled++;
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
    TextStream::instance().setText(std::string("New enemy in ") + std::to_string(enemySpawn), 1, 1);
    int oldEnemysSize = enemys.size();
    if(enemySpawn<=0){
        enemys.push_back(createNewEnemy());
        enemySpawn=100;
    }else{
        enemySpawn--;
    }

    if(oldEnemysSize != enemys.size()) {
        engine.get()->updateSpritesInScene();
    }

    for(auto &e: enemys){
        e->setDirectionIsLeft(e.get()->getEnemySprite()->getX() > aang->getAangDownSprite()->getX());
        e->tick();
    }


    attackCounter2++;
}


void Scene_Level1::moveOthers() {
    if (aang->isWalkingLeft() && !aang->isAttacking()) {
        for(auto& e: enemys) {
            e->getEnemySprite()->moveTo(e->getEnemySprite()->getX() + aang->getXVelocity(),
                                            e->getEnemySprite()->getY());
            e->getHealthBarSprite()->moveTo(e->getHealthBarSprite()->getX() + aang->getXVelocity(),
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

    if (aang->isWalkingRight() && !aang->isAttacking()) {
        for(auto& e: enemys) {
            e->getEnemySprite()->moveTo(e->getEnemySprite()->getX() - aang->getXVelocity(),
                                            e->getEnemySprite()->getY());
            e->getHealthBarSprite()->moveTo(e->getHealthBarSprite()->getX() - aang->getXVelocity(),
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
    if(aang->isWalkingLeft()){
        return std::unique_ptr<AirBall>(new AirBall(builder
                                                            .withLocation(aang->getAangDownSprite()->getX() - aang->getAangDownSprite()->getWidth() / 2, aang->getAangDownSprite()->getY() + aang->getAangDownSprite()->getHeight() / 4)
                                                            .buildWithDataOf(*someAirBallSprite), directionTogo));

    }else{
        return std::unique_ptr<AirBall>(new AirBall(builder
        .withLocation(aang->getAangDownSprite()->getX() + aang->getAangDownSprite()->getWidth() / 2, aang->getAangDownSprite()->getY() + aang->getAangDownSprite()->getHeight() / 4)
                                                            .buildWithDataOf(*someAirBallSprite), directionTogo));
    }
}


std::unique_ptr<Enemy> Scene_Level1::createNewEnemy() {
    return std::unique_ptr<Enemy>(new Enemy(   builder.withSize(SIZE_32_64)
                                                       .withLocation(200,60)
                                                       .buildWithDataOf(*someEnemySprite),
                                               builder.withSize(SIZE_16_8)
                                                       .withLocation(208,65)
                                                       .buildWithDataOf(*someHealthbarEnemySprite)));

}


void Scene_Level1::removeAirBallsOffScreen() {
    airBalls.erase(
            std::remove_if(airBalls.begin(), airBalls.end(), [](std::unique_ptr<AirBall> &s) { return s->isOffScreen(); }),
            airBalls.end());
}

