//
// Created by kyles on 27/12/2019.
//

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
#include "Level1.h"
#include "IntroScene.h"
#include "VictoryScene.h"
#include "Level2.h"

std::vector<Background *> Menu::backgrounds() {
    return {bg.get()/*, bg2.get(), bg3.get()*/};
}

std::vector<Sprite *> Menu::sprites() {
    return {  /*metroidObject->getMetroid(), ball_projectiel.get(), enemyObject->getMario(), bulletObject->getBullet(), firebolt.get()*/ };
}

void Menu::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(tussenschermMapPal, sizeof(tussenschermMapPal)));
    /*
    SpriteBuilder<Sprite> builder;

    metroidBewegen = builder
            .withData(animatie_metroidTiles, sizeof(animatie_metroidTiles))
            .withSize(SIZE_32_64)
            .withAnimated(11, 3)
            .withLocation(0, 88)
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
            .withLocation(224, 120)
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
            .withLocation(10, 20)
            .withSize(SIZE_8_8)
            .withinBounds()
            .buildPtr();


    metroidObject = std::unique_ptr<Metroid>(new Metroid(std::move(metroidBewegen)));
    enemyObject = std::unique_ptr<Mario>(new Mario(std::move(enemy)));
    bulletObject = std::unique_ptr<Bullet>(new Bullet(std::move(projectiel)));
    */
    bg = std::unique_ptr<Background>(new Background(1, tussenschermTiles, sizeof(tussenschermTiles), tussenschermMap, sizeof(tussenschermMap)));
    bg.get()->useMapScreenBlock(29);
    //bg2 = std::unique_ptr<Background>(new Background(2, rocksTiles, sizeof(rocksTiles), rocksMap, sizeof(rocksMap)));
    //bg2.get()->useMapScreenBlock(26);
    //bg3 = std::unique_ptr<Background>(new Background(3, blackTiles, sizeof(blackTiles), blackMap, sizeof(blackMap)));
    //bg3.get()->useMapScreenBlock(4);

    //bg2 = std::unique_ptr<Background>(new Background(1, wallsTiles, sizeof(wallsTiles), wallsMap, sizeof(wallsMap)));
    //bg2.get()->useMapScreenBlock(16);


    engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);
}


void Menu::tick(u16 keys) {

    //scrollX += metroidObject->getMetroid()->getDx();
    /*if(keys & KEY_DOWN){
        scrollY -= 1;
    }
    else if(keys & KEY_UP){
        scrollY += 1;
    }*/
    /*
    if(metroidObject->getMetroid()->getX() < 120 && metroidObject->getMetroid()->getX() > 96) {
        if (metroidObject->getMetroid()->getDx() == 1) {
            if(bg->getScrollX() == 300)
                scrollX = scrollX + 0;
            else{
                scrollX = scrollX + 2;
                bg->setScrollX(scrollX);
                metroidObject->getMetroid()->moveTo(metroidObject->getMetroid()->getX()-1,metroidObject->getMetroid()->getY());
                //enemyObject->getMario()->moveTo(enemyObject->getMario()->getX()-1,enemyObject->getMario()->getY());
            }
        }
        else if (metroidObject->getMetroid()->getDx() == 0) {
            scrollX = scrollX + 0;
        }
        else{
            if (bg->getScrollX() == 0)
                scrollX = scrollX + 0;
            else {
                scrollX = scrollX -2;
                metroidObject->getMetroid()->moveTo(metroidObject->getMetroid()->getX()+1,metroidObject->getMetroid()->getY());
                //enemyObject->getMario()->moveTo(enemyObject->getMario()->getX()+1,enemyObject->getMario()->getY());
                bg->setScrollX(scrollX);
            }
        }
    }
    bg2.get()->scroll(scrollX, scrollY);

    metroidObject->tick(keys);
    enemyObject->tick(keys);
    bulletObject->tick(keys);


    if(keys & KEY_A) {
        if (!(bulletObject->getIsShooting())) {
            if (metroidObject->getGoLeft()) {
                if (metroidObject->getIsCrouching()) {
                    bulletObject->getBullet()->moveTo(metroidObject->getMetroid()->getX() - 6,
                                                      metroidObject->getMetroid()->getY() + 47);
                    bulletObject->shootBulletLeft();
                } else {
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

    if (bulletObject->getBullet()->collidesWith(*(enemyObject->getMario()))) {
        bulletObject->setIsShooting(false);
    }
    /*   if(metroidObject->getMetroid()->collidesWith(*(enemyObject->getMario()))){
           TextStream::instance().setText("Auw", 0, 19);
       }*/

    if (keys & KEY_START) {
        if (!engine->isTransitioning()) {
            engine->enqueueSound(zelda_secret_16K_mono, zelda_secret_16K_mono_bytes);

            TextStream::instance() << "entered: starting next scene";

            engine->transitionIntoScene(new Level2(engine), new FadeOutScene(8));
        }
    }
}