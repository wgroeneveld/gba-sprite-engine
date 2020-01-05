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
    return {  metroidObject->getMetroid(), ball_projectiel.get(), enemyObject->getMario(), bulletObject->getBullet(), marioBulletObject->getBullet() };
}

void Level1::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(sharedBackground2Pal, sizeof(sharedBackground2Pal)));

    SpriteBuilder<Sprite> builder;

    metroidBewegen = builder
            .withData(animatie_metroidTiles, sizeof(animatie_metroidTiles))
            .withSize(SIZE_32_64)
            .withAnimated(11, 3)
            .withLocation(0, 80)
            .withinBounds()
            .buildPtr();

    ball_projectiel = builder
            .withData(ballTiles, sizeof(ballTiles))
            .withSize(SIZE_16_16)
            .withLocation(60, 60)
            .withinBounds()
            .buildPtr();

    enemy = builder
            .withData(enemy_bigTiles, sizeof(enemy_bigTiles))
            .withSize(SIZE_16_32)
                    // .withAnimated(7, 30)
            .withLocation(224, 112)
            .withinBounds()
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

    bg = std::unique_ptr<Background>(new Background(1, bricksForegroundTiles, sizeof(bricksForegroundTiles), bricksForegroundMap, sizeof(bricksForegroundMap)));
    bg.get()->useMapScreenBlock(29);
    bg->setMapData(lvl1Map);
    bg2 = std::unique_ptr<Background>(new Background(2, rocksTiles, sizeof(rocksTiles), rocksMap, sizeof(rocksMap)));
    bg2.get()->useMapScreenBlock(26);

    engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);

}

void Level1::tick(u16 keys) {




    metroidObject->setCanGoRight(!isObstacleInFront((metroidObject->getMetroid()), bg.get()));
    metroidObject->setCanGoLeft(!isObstacleBehind(metroidObject->getMetroid(), bg.get()));
  //  TextStream::instance().setText(engine->getTimer()->to_string(), 0, 12);
    int placeOnScreen = isObstacleInFrontInt(metroidObject->getMetroid(), bg.get());
    TextStream::instance().setText(std::to_string((metroidObject->getMetroid()->getX()+metroidObject->getMetroid()->getWidth()+bg.get()->getScrollX())/8) + std::string("Xreal"), 16, 1);
    TextStream::instance().setText(std::to_string((metroidObject->getMetroid()->getY()+metroidObject->getMetroid()->getHeight()+bg.get()->getScrollY())/8) + std::string("Yreal"), 17, 1);
    TextStream::instance().setText(std::to_string(placeOnScreen) + std::string("PosOnScreen"), 18, 1);
    TextStream::instance().setText(std::to_string(isObstacleInFrontIntVector(metroidObject->getMetroid(),bg.get())) + std::string("PosOnScreen"), 19, 1);

    if(metroidObject->getIsJumping()) engine->getTimer()->start();
    if(metroidObject->getIsFalling()){
        engine->getTimer()->stop();
        engine->getTimer()->reset();
    }
    metroidObject->setTimerValue(engine->getTimer()->getSecs());

    if(metroidObject->getMetroid()->getX() < 120 && metroidObject->getMetroid()->getX() > 103){
        if(metroidObject->getGoLeft()){
            scrollX --;
            bg->setScrollX(scrollX);
        }
        else{
            scrollX ++;
            bg->setScrollX(scrollX);
        }
    }
    /*if(keys & KEY_DOWN){
        scrollY -= 1;
    }
    else if(keys & KEY_UP){
        scrollY += 1;
    }*/
    bg.get()->scroll(scrollX, scrollY);

    metroidObject->tick(keys);
    enemyObject->tick(keys);
    bulletObject->tick(keys);

    TextStream::instance().setText(std::to_string(metroidObject->getMetroid()->getX()) + std::string("Pos X"), 1, 1);
    TextStream::instance().setText(std::to_string(metroidObject->getMetroid()->getY()) + std::string("Pos Y"), 3, 1);
    TextStream::instance().setText(std::to_string(scrollX) + std::string("Pos bgX"), 5, 1);
    TextStream::instance().setText(std::to_string(scrollY) + std::string("Pos bgY"), 7, 1);


    if(keys & KEY_A) {
        if (!(bulletObject->getIsShooting())) {
            if (metroidObject->getGoLeft()) {
                if(metroidObject->getIsCrouching()){
                    bulletObject->getBullet()->moveTo(metroidObject->getMetroid()->getX() - 6,
                                                      metroidObject->getMetroid()->getY() + 47);
                    bulletObject->shootBulletLeft();
                }
                else {
                    bulletObject->getBullet()->moveTo(metroidObject->getMetroid()->getX() - 6,
                                                      metroidObject->getMetroid()->getY() + 33);
                    bulletObject->shootBulletLeft();
                }
            } else {
                if (metroidObject->getIsCrouching()) {
                    bulletObject->getBullet()->moveTo(metroidObject->getMetroid()->getX() + 30,
                                                      metroidObject->getMetroid()->getY() + 47);
                    bulletObject->shootBulletRight();
                } else {
                    bulletObject->getBullet()->moveTo(metroidObject->getMetroid()->getX() + 30,
                                                      metroidObject->getMetroid()->getY() + 33);
                    bulletObject->shootBulletRight();
                }
            }
        }
    }

    if(bulletObject->getBullet()->collidesWith(*(enemyObject->getMario()))){
        bulletObject->setIsShooting(false);
    }
    /*   if(metroidObject->getMetroid()->collidesWith(*(enemyObject->getMario()))){
           TextStream::instance().setText("Auw", 0, 19);
       }*/
}

