//
// Created by kyles on 3/01/2020.
//

#include "Level1.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include "Transition.h"
#include <libgba-sprite-engine/gba/tonc_math.h>

#include "../sprites/samus_aran.h"
#include "ball.h"
#include "Mario.h"
#include "../sprites/projectiel.h"
#include "../achtergrond/AchtergrondLvl1.h"
#include "Metroid.h"
#include "Bullet.h"
#include "DeadScene.h"
#include "../sound/SoundFX.h"
#include "../sound/SoundFX2.h"
#include "../achtergrond/MapdataLvl1.h"

std::vector<Background *> Level1::backgrounds() {
    return {bg.get(), bg2.get()};
}

std::vector<Sprite *> Level1::sprites() {
    return {  metroidObject->getMetroid(), ball_projectiel.get(), enemyObject->getMario(), bulletObject->getBullet(), marioBulletObject->getBullet()};
}

void Level1::load() {
    engine->enableText();
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(sharedBackground2Pal, sizeof(sharedBackground2Pal)));

    SpriteBuilder<Sprite> builder;

    metroidBewegen = builder
            .withData(animatie_metroidTiles, sizeof(animatie_metroidTiles))
            .withSize(SIZE_32_64)
            .withAnimated(11, 1)
            .withLocation(28, 80)
            .buildPtr();

    ball_projectiel = builder
            .withData(ballTiles, sizeof(ballTiles))
            .withSize(SIZE_16_16)
            .withLocation(16, 47)
            .buildPtr();

    enemy = builder
            .withData(enemy_bigTiles, sizeof(enemy_bigTiles))
            .withSize(SIZE_16_32)
            .withLocation(430, 112)
            .buildPtr();

    projectiel = builder
            .withData(projectielTiles, sizeof(projectielTiles))
            .withAnimated(5,7)
            .withLocation(30, 121)
            .withSize(SIZE_8_8)
            .buildPtr();

    firebolt = builder
            .withData(fireboltTiles, sizeof(fireboltTiles))
            .withLocation(224, 128)
            .withSize(SIZE_8_8)
            .buildPtr();


    metroidObject = std::unique_ptr<Metroid>(new Metroid(std::move(metroidBewegen)));
    enemyObject = std::unique_ptr<Mario>(new Mario(std::move(enemy)));
    bulletObject = std::unique_ptr<Bullet>(new Bullet(std::move(projectiel)));
    marioBulletObject = std::unique_ptr<MarioBullet>(new MarioBullet(std::move(firebolt)));


    bg = std::unique_ptr<Background>(new Background(1, bricksForegroundTiles, sizeof(bricksForegroundTiles), bricksForegroundMap, sizeof(bricksForegroundMap),17,1,MAPLAYOUT_32X64));
    bg->setMapData(lvl1Map);
    bg->setScrollX(0);
    bg->setScrollY(0);
    bg2 = std::unique_ptr<Background>(new Background(2, rocksTiles, sizeof(rocksTiles), rocksMap, sizeof(rocksMap),25,2,MAPLAYOUT_32X32));


}

void Level1::tick(u16 keys) {


    if(metroidObject->getIsJumping()){
        engine->getTimer()->start();
    }

    if(engine->getTimer()->getTotalMsecs() > 500 || metroidObject->getIsFalling()){
        engine->getTimer()->reset();
        engine->getTimer()->stop();
        metroidObject->setIsFalling(true);
        metroidObject->setIsJumping(false);
    }

    if(engine->getTimer()->getTotalMsecs() < 20 && metroidObject->getIsJumping()){
        engine->enqueueSound(jump_sound,jump_sound_bytes,90000);
    }


    metroidObject->setCanGoRight(!isObstacleInFront((metroidObject->getMetroid()), bg.get()));
    metroidObject->setCanGoLeft(!isObstacleBehind(metroidObject->getMetroid(), bg.get()));
    metroidObject->setCanGoDown(!isObstacleBelow(metroidObject->getMetroid(),bg.get()));
    metroidObject->setCanGoUp(!isObstacleAbove(metroidObject->getMetroid(), bg.get()));

    enemyObject->setCanGoLeft(!isObstacleBehind(enemyObject->getMario(), bg.get()));
    enemyObject->setCanGoRight(!isObstacleInFront(enemyObject->getMario(), bg.get()));

    if (metroidObject->getMetroid()->getDx() == 1) {
            if (metroidObject->getMetroid()->getX() < 122 && metroidObject->getMetroid()->getX() > 96) {
                if (bg->getScrollX() == 272) {
                    scrollX = scrollX + 0;
                }
                else {
                    scrollX = scrollX + 2;
                    bg->setScrollX(scrollX);
                    enemyObject->getMario()->moveTo(enemyObject->getMario()->getX() - 2,
                                                    enemyObject->getMario()->getY());
                    ball_projectiel.get()->moveTo(ball_projectiel->getX() - 2, ball_projectiel->getY());
                    metroidObject->getMetroid()->moveTo(metroidObject->getMetroid()->getX() - 1,
                                                        metroidObject->getMetroid()->getY());
                    marioBulletObject->getBullet()->moveTo(marioBulletObject->getBullet()->getX()-2,marioBulletObject->getBullet()->getY());
            }
        }
    }
    else if (metroidObject->getMetroid()->getDx() == 0) {
        scrollX = scrollX + 0;
    }
    else{
        if(metroidObject->getMetroid()->getX() < 120 && metroidObject->getMetroid()->getX() > 94) {
            if (bg->getScrollX() == 0) {
                scrollX = scrollX + 0;
            }
            else {
                scrollX = scrollX - 2;
                enemyObject->getMario()->moveTo(enemyObject->getMario()->getX() + 2,
                                                enemyObject->getMario()->getY());
                ball_projectiel.get()->moveTo(ball_projectiel->getX() + 2, ball_projectiel->getY());
                metroidObject->getMetroid()->moveTo(metroidObject->getMetroid()->getX() + 1,
                                                    metroidObject->getMetroid()->getY());
                marioBulletObject->getBullet()->moveTo(marioBulletObject->getBullet()->getX()+2,marioBulletObject->getBullet()->getY());
                bg->setScrollX(scrollX);
            }
        }
    }

    bg.get()->scroll(scrollX, scrollY);

    if(bulletObject->getIsShooting()){
        if(metroidObject->getMetroid()->getX() < 94){
            if(bulletObject->getBullet()->getX() < 18){
                bulletObject->setIsShooting(false);
            }
            else if(metroidObject->getMetroid()->getX() + 102 <= bulletObject->getBullet()->getX()){
                bulletObject->setIsShooting(false);
            }
        }
        else if(metroidObject->getMetroid()->getX() + bg->getScrollX() > 388){
            if(bulletObject->getBullet()->getX() > 214){
                bulletObject->setIsShooting(false);
            }
            else if(metroidObject->getMetroid()->getX() - 70 >= bulletObject->getBullet()->getX()){
                bulletObject->setIsShooting(false);
            }
        }
        else{
            if((metroidObject->getMetroid()->getX() + 102 <= bulletObject->getBullet()->getX()) || (metroidObject->getMetroid()->getX() -70 >= bulletObject->getBullet()->getX())) {
                bulletObject->setIsShooting(false);
            }
        }
    }
    if(metroidObject->getMetroid()->getX()+36 == bulletObject->getBullet()->getX() || metroidObject->getMetroid()->getX() == bulletObject->getBullet()->getX()+9 ){
        engine->enqueueSound(laser_sound,laser_sound_bytes, 90000);
    }



    if(marioBulletObject->getIsShooting()){
        if(enemyObject->getMario()->getX() < 94){
            if(marioBulletObject->getBullet()->getX() < 18){
                marioBulletObject->getBullet()->moveTo(-50,0);
                marioBulletObject->getBullet()->setVelocity(0,0);
                marioBulletObject->setCooldown(0);
                marioBulletObject->setIsShooting(false);

            }
            else if(enemyObject->getMario()->getX() + 102 <= marioBulletObject->getBullet()->getX()){
                marioBulletObject->getBullet()->moveTo(-50,0);
                marioBulletObject->getBullet()->setVelocity(0,0);
                marioBulletObject->setCooldown(0);
                marioBulletObject->setIsShooting(false);
            }
        }
        else if(enemyObject->getMario()->getX() + bg->getScrollX() > 404){
            if(marioBulletObject->getBullet()->getX() > 214){
                marioBulletObject->getBullet()->moveTo(-50,0);
                marioBulletObject->getBullet()->setVelocity(0,0);
                marioBulletObject->setCooldown(0);
                marioBulletObject->setIsShooting(false);

            }
            else if(enemyObject->getMario()->getX() - 70 >= marioBulletObject->getBullet()->getX()){
                marioBulletObject->getBullet()->moveTo(-50,0);
                marioBulletObject->getBullet()->setVelocity(0,0);
                marioBulletObject->setCooldown(0);
                marioBulletObject->setIsShooting(false);

            }
        }
        else{
            if(((enemyObject->getMario()->getX() + 102 <= marioBulletObject->getBullet()->getX())) || (enemyObject->getMario()->getX() -70 >= marioBulletObject->getBullet()->getX())) {
                marioBulletObject->getBullet()->moveTo(-50,0);
                marioBulletObject->getBullet()->setVelocity(0,0);
                marioBulletObject->setCooldown(0);
                marioBulletObject->setIsShooting(false);

            }
        }
    }


    metroidObject->tick(keys);
    enemyObject->tick(keys);
    bulletObject->tick(keys);
    marioBulletObject->tick(keys);


    if(keys & KEY_A) {
        if (!(bulletObject->getIsShooting())) {
            if (metroidObject->getGoLeft()) {
                bulletObject->shootBulletLeft();
                if(metroidObject->getIsCrouching())
                    bulletObject->getBullet()->moveTo(metroidObject->getMetroid()->getX() - 6,
                                                      metroidObject->getMetroid()->getY() + 47);
                else bulletObject->getBullet()->moveTo(metroidObject->getMetroid()->getX() - 6,
                                                      metroidObject->getMetroid()->getY() + 33);
            } else {
                bulletObject->shootBulletRight();
                if (metroidObject->getIsCrouching())
                    bulletObject->getBullet()->moveTo(metroidObject->getMetroid()->getX() + 30,
                                                      metroidObject->getMetroid()->getY() + 47);
                 else bulletObject->getBullet()->moveTo(metroidObject->getMetroid()->getX() + 30,
                                                      metroidObject->getMetroid()->getY() + 33);
            }
        }
    }



    if (!(marioBulletObject->getIsShooting()) && marioBulletObject->getCooldown() == 50 && enemyObject->getLives() > 0) {
        if (enemyObject->getGoLeft()) {
            marioBulletObject->getBullet()->moveTo(enemyObject->getMario()->getX() - 6,
                                                   enemyObject->getMario()->getY() + 16);
            marioBulletObject->shootBulletLeft();
        }
        else{
            marioBulletObject->getBullet()->moveTo(enemyObject->getMario()->getX() + 10,
                                                   enemyObject->getMario()->getY() + 16);
            marioBulletObject->shootBulletRight();
        }
    }

    if(bulletObject->getBullet()->collidesWith(*(enemyObject->getMario()))){
        bulletObject->setIsShooting(false);
        if(metroidObject->getPowerUp()) enemyObject->reduceLives(50);
        else enemyObject->reduceLives(25);
    }

    if(metroidObject->getMetroid()->collidesWith(*(ball_projectiel))){
        engine->enqueueSound(power_up,power_up_bytes,90000);
        ball_projectiel->moveTo(0,230);
        metroidObject->setPowerUp(true);
        TextStream::instance().setText("Power up",3,2);
    }

    if(marioBulletObject->getBullet()->collidesWith(*(metroidObject->getMetroid()))){
        marioBulletObject->getBullet()->moveTo(-50,0);
        marioBulletObject->getBullet()->setVelocity(0,0);
        marioBulletObject->setIsShooting(false);
        marioBulletObject->setCooldown(0);
        metroidObject->reduceLives(25);
    }

    TextStream::instance().setText(std::to_string(metroidObject->getLives())+" health",0,2) ;
    TextStream::instance().setFontColor(0xFBE0);

    if (metroidObject->getLives() <= 0) {
        if (!engine->isTransitioning()) {
            engine->transitionIntoScene(new DeadScene(engine), new FadeOutScene(6));
        }
    }
    if (bg->getScrollX() + metroidObject->getMetroid()->getX() == 470){
        if (!engine->isTransitioning()) {
            engine->transitionIntoScene(new Transition(engine), new FadeOutScene(6));
        }
    }
}

