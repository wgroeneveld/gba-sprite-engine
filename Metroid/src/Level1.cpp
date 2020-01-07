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

std::vector<Background *> Level1::backgrounds() {
    return {bg.get(), bg2.get()};
}

std::vector<Sprite *> Level1::sprites() {
    return {  metroidObject->getMetroid(), ball_projectiel.get(), enemyObject->getMario(), bulletObject->getBullet(), marioBulletObject->getBullet()};
}

void Level1::load() {
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
            .withLocation(16, 48)
          //  .withinBounds()
            .buildPtr();

    enemy = builder
            .withData(enemy_bigTiles, sizeof(enemy_bigTiles))
            .withSize(SIZE_16_32)
                    // .withAnimated(7, 30)
            .withLocation(224, 112)
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
            .withinBounds()
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


    engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);

}

void Level1::tick(u16 keys) {


    int bla = 0;
    int up = 0;
    if(metroidObject->getIsJumping()){
        engine->getTimer()->start();
        bla ++;
    }
    if(!isObstacleAbove(metroidObject->getMetroid(),bg.get())){
        up ++;
    }
    if(engine->getTimer()->getSecs() == 3 || metroidObject->getIsFalling()){
        engine->getTimer()->reset();
        engine->getTimer()->stop();
        metroidObject->setIsFalling(true);
        metroidObject->setIsJumping(false);
    }

    metroidObject->setCanGoRight(!isObstacleInFront((metroidObject->getMetroid()), bg.get()));
    metroidObject->setCanGoLeft(!isObstacleBehind(metroidObject->getMetroid(), bg.get()));
    metroidObject->setCanGoDown(!isObstacleBelow(metroidObject->getMetroid(),bg.get()));
    metroidObject->setCanGoUp(!isObstacleAbove(metroidObject->getMetroid(), bg.get()));

    enemyObject->setCanGoLeft(!isObstacleBehind(enemyObject->getMario(), bg.get()));
    enemyObject->setCanGoRight(!isObstacleInFront(enemyObject->getMario(), bg.get()));

 //   bulletObject->setCanGoLeft(!isObstacleBehind(bulletObject->getBullet(), bg.get()));
   // bulletObject->setCanGoRight(!isObstacleInFront(bulletObject->getBullet(), bg.get()));

    TextStream::instance().setText(engine->getTimer()->to_string(), 12, 0);


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
                if (bg->getScrollX() == 272)
                    scrollX = scrollX + 0;
                else {
                    scrollX = scrollX + 2;
                    bg->setScrollX(scrollX);
                    enemyObject->getMario()->moveTo(enemyObject->getMario()->getX() - 2,
                                                    enemyObject->getMario()->getY());
                    ball_projectiel.get()->moveTo(ball_projectiel->getX() - 2, ball_projectiel->getY());
                    metroidObject->getMetroid()->moveTo(metroidObject->getMetroid()->getX() - 1,
                                                        metroidObject->getMetroid()->getY());
                
            }
        }
    }
    else if (metroidObject->getMetroid()->getDx() == 0) {
        scrollX = scrollX + 0;
    }
    else{
        if(metroidObject->getMetroid()->getX() < 120 && metroidObject->getMetroid()->getX() > 94) {
            if (bg->getScrollX() == 0)
                scrollX = scrollX + 0;
            else {
                scrollX = scrollX - 2;
                enemyObject->getMario()->moveTo(enemyObject->getMario()->getX() + 2,
                                                enemyObject->getMario()->getY());
                ball_projectiel.get()->moveTo(ball_projectiel->getX() + 2, ball_projectiel->getY());
                metroidObject->getMetroid()->moveTo(metroidObject->getMetroid()->getX() + 1,
                                                    metroidObject->getMetroid()->getY());
                bg->setScrollX(scrollX);
            }
        }
    }

    bg.get()->scroll(scrollX, scrollY);

    if( (metroidObject->getMetroid()->getX() + 80 <= bulletObject->getBullet()->getX()) || (metroidObject->getMetroid()->getX() -64 >= bulletObject->getBullet()->getX()) ) {
        bulletObject->setIsShooting(false);
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
        ball_projectiel->moveTo(-20,0);
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

    TextStream::instance().setText(std::to_string(metroidObject->getLives())+"/100",0,10) ;
}

