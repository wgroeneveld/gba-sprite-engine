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
#include "menu.h"
#include <libgba-sprite-engine/gba/tonc_math.h>

#include "samus_aran.h"
#include "ball.h"
#include "Mario.h"
#include "projectiel.h"
#include "achtergrond.h"
#include "achtergrond2.h"
#include "achtergrond3.h"
#include "sample_sound.h"
#include "Metroid.h"
#include "Bullet.h"
#include "test.h"
#include "SoundDeath.h"
#include "DeadScene.h"
#include "SoundIntro.h"
#include "SoundFX.h"
#include "SoundFX2.h"
#include "VictoryScene.h"

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
          //  .withinBounds()
            .buildPtr();

    enemy = builder
            .withData(enemy_bigTiles, sizeof(enemy_bigTiles))
            .withSize(SIZE_16_32)
                    // .withAnimated(7, 30)
            .withLocation(430, 112)
         //   .withinBounds()
            .buildPtr();

    projectiel = builder
            .withData(projectielTiles, sizeof(projectielTiles))
            .withAnimated(5,7)
            .withLocation(30, 121)
            .withSize(SIZE_8_8)
                    // .withinBounds()
            .buildPtr();

    firebolt = builder
            .withData(fireboltTiles, sizeof(fireboltTiles))
            .withLocation(224, 128)
            .withSize(SIZE_8_8)
           // .withinBounds()
            .buildPtr();


    metroidObject = std::unique_ptr<Metroid>(new Metroid(std::move(metroidBewegen)));
    enemyObject = std::unique_ptr<Mario>(new Mario(std::move(enemy)));
    bulletObject = std::unique_ptr<Bullet>(new Bullet(std::move(projectiel)));
    marioBulletObject = std::unique_ptr<MarioBullet>(new MarioBullet(std::move(firebolt)));
  //  bulletObject2 = std::unique_ptr<Bullet>(new Bullet(std::move(projectiel2)));


    bg = std::unique_ptr<Background>(new Background(1, bricksForegroundTiles, sizeof(bricksForegroundTiles), bricksForegroundMap, sizeof(bricksForegroundMap),17,1,MAPLAYOUT_32X64));
    //bg.get()->useMapScreenBlock(29);
    bg->setMapData(lvl1Map);
    bg2 = std::unique_ptr<Background>(new Background(2, rocksTiles, sizeof(rocksTiles), rocksMap, sizeof(rocksMap),25,2,MAPLAYOUT_32X32));
    //bg2.get()->useMapScreenBlock(26);


    //engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);
    //engine->enqueueMusic(leaving_earth,leaving_earth_bytes,90000);

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

 //   bulletObject->setCanGoLeft(!isObstacleBehind(bulletObject->getBullet(), bg.get()));
   // bulletObject->setCanGoRight(!isObstacleInFront(bulletObject->getBullet(), bg.get()));

    //TextStream::instance().setText(engine->getTimer()->to_string(), 12, 0);


   // TextStream::instance().setText(std::to_string(left),9,1);
  //  TextStream::instance().setText(std::to_string(right),11,1);
    //int placeOnScreen = isObstacleInFrontInt(metroidObject->getMetroid(), bg.get());
    //TextStream::instance().setText(std::to_string((metroidObject->getMetroid()->getX()+metroidObject->getMetroid()->getWidth()+bg.get()->getScrollX())/8) + std::string("Xreal"), 16, 1);
    //TextStream::instance().setText(std::to_string((metroidObject->getMetroid()->getY()+metroidObject->getMetroid()->getHeight()+bg.get()->getScrollY())/8) + std::string("Yreal"), 17, 1);
    //TextStream::instance().setText(std::to_string(isObstacleInFrontInt(metroidObject->getMetroid(), bg.get())) + std::string("PosOnScreen"), 18, 1);
    //TextStream::instance().setText(std::to_string(isObstacleInFrontIntVector(metroidObject->getMetroid(),bg.get())) + std::string("obstacleOnScreen"), 19, 1);
    //TextStream::instance().setText(std::to_string(bla) + std::string("bla"), 10, 1);
    //TextStream::instance().setText(std::to_string(up) + std::string("up"), 5, 1);
    //TextStream::instance().setText(std::to_string((metroidObject->getMetroid()->getDx())) + std::string("dx"), 16, 1);


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




    //TextStream::instance().setText(std::to_string(metroidObject->getMetroid()->getX()) + std::string("Pos X"), 1, 1);
    //TextStream::instance().setText(std::to_string(metroidObject->getMetroid()->getY()) + std::string("Pos Y"), 3, 1);
    //TextStream::instance().setText(std::to_string(scrollX) + std::string("Pos bgX"), 5, 1);
    //TextStream::instance().setText(std::to_string(scrollY) + std::string("Pos bgY"), 7, 1);


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



    if (!(marioBulletObject->getIsShooting()) && marioBulletObject->getCooldown() == 50 && !(enemyObject->getLives() <=0)) {
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
        TextStream::instance().setText("Power up",3,19);
    }

    if(marioBulletObject->getBullet()->collidesWith(*(metroidObject->getMetroid()))){
        marioBulletObject->getBullet()->moveTo(-50,0);
        marioBulletObject->getBullet()->setVelocity(0,0);
        marioBulletObject->setIsShooting(false);
        marioBulletObject->setCooldown(0);
        metroidObject->reduceLives(25);
    }

    TextStream::instance().setText(std::to_string(metroidObject->getLives())+" health",0,2) ;

    if (metroidObject->getLives() <= 0) {
        if (!engine->isTransitioning()) {

            //TextStream::instance() << "entered: starting next scene";

            engine->transitionIntoScene(new DeadScene(engine), new FadeOutScene(6));
        }
    }
    if (bg->getScrollX() + metroidObject->getMetroid()->getX() == 470){
        if (!engine->isTransitioning()) {

            //TextStream::instance() << "entered: starting next scene";

            engine->transitionIntoScene(new VictoryScene(engine), new FadeOutScene(6));
        }
    }
}

