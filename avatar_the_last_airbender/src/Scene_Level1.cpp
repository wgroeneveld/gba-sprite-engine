#include <libgba-sprite-engine/background/text_stream.h>
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
#include "data/music/avatar_music.h"

#include "Scene_End.h"

std::vector<Background *> Scene_Level1::backgrounds() {
    return {  backgroundGround.get(),
              backgroundSea.get(),
              backgroundSun.get()};
}

std::vector<Sprite *> Scene_Level1::sprites() {
    std::vector<Sprite*> sprites;


    for(auto& ab : airBalls ){  // lijst van Airballs afgaan en elke airballSprite renderen
        sprites.push_back(ab->getSprite());
    }

    for(auto& e : activeEnemies ){  // lijst van Enenmys afgaan en elke airballSprite renderen
        sprites.push_back(e->getEnemySprite());
        sprites.push_back(e->getHealthBarSprite());
    }
    
    // Aang + dd healthbar van aang renderen
    sprites.push_back(aang->getAangDownSprite());
    sprites.push_back(aang->getAangUpSprite());
    sprites.push_back(aang->getHealthBarSprite());

    //Een voorbeeld airballSprite laden voor airbal en enemy zodat hier instances van genomen kunnen worden
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
                                                     .withLocation( (GBA_SCREEN_WIDTH/2)-16,83)
                                                     .buildPtr(),
                                             builder
                                                     .withData(aangUpTiles, sizeof(aangUpTiles))
                                                     .withSize(SIZE_64_32)
                                                     .withLocation( GBA_SCREEN_WIDTH+10,GBA_SCREEN_HEIGHT +10)
                                                     .buildPtr(),
                                             builder
                                                     .withData(healthbarAangTiles, sizeof(healthbarAangTiles))
                                                     .withSize(SIZE_32_16)
                                                     .withLocation( 3,3)
                                                     .buildPtr()));


    //COMMENTAAR DAT WEG MAG: Hier maak ik een vector aan van enemies die zich in de eerste section moeten bevinden
    //enemysSection1.push_back(createNewEnemy(20,20,true));
    //COMMENTAAR DAT WEG MAG: Hier wil ik die vector toevoegen aan de vector van de vector, maar hier geeft het de fout als je wilt compileren
    //enemies.push_back(enemysSection1);

    engine.get()->enqueueSound(avatar_music, sizeof(avatar_music), 62500);


}


void Scene_Level1::tick(u16 keys) {
    TextStream::instance().setText(std::string("Score: ") + std::to_string(amountEnemysKilled), 1, 21);

    //COMMENTAAR DAT WEG MAG: Ik heb hier alles gestructureerd
    ////////////////////////////// TICKS ///////////////////////////////////
    aang->tick(keys);

    for(auto& e : activeEnemies) {
        e->tick();
    }

    for(auto& ab : airBalls) {
        ab->tick();
    }

    if (aang->isMoveOthers()) {
        moveOthers();
    }

    ////////////////////////////// ENEMY //////////////////////////////
    ///ADD
    //COMMENTAAR DAT WEG MAG: Hier kijk ik dus als aang van de ene section naar de andere loop moet dus de nieuwe enemies geladen worden
    //Dus ik kijk als de module van de grond dat gescrold is 0 is
    // Maar de de xScrollingGround mag niet 0 zijn anders zal het steeds updaten (door de updateSpriteInScene) en rare dingen doen totdat je de achtergrond laat scrollen)
    //De enemiesUpdated dient om de update maar 1 keer te laten gebeuren/session (Weet niet als we die wg mogen laten)
    //Dus wanneer die if true is zal ik het nummer (activeSection) van de section bepalen met de deling en zal ik eerst alles enemies clearen
    //Daarnaa voeg ik de enemies van die section in de activeEnemies. Dat zijn de enemies die worden wweergegeven
    //
    /*
    TextStream::instance().setText(std::string("X") + std::to_string(xScrollingGround), 1, 1);
    if(xScrollingGround%256 == 0 && xScrollingGround != 0 && !enemiesUpdated) {
        enemiesUpdated = true;
        activeSection = xScrollingGround/GBA_SCREEN_WIDTH;
        activeEnemies.erase(activeEnemies.begin(), activeEnemies.end());
        for(auto& e : enemies[activeSection]) {
            activeEnemies.push_back(createNewEnemy(e->getBeginXPosition(), e->getEndXPosition(), e->isStaticPosition()));
        }
        engine->updateSpritesInScene();
    }
    else {
        enemiesUpdated = false;
    }
    */
    ////////// UPDATE THE DIFFICULTY OF THE GAME //////
    if(amountEnemysKilled>5){
        newEnemyTimerVelocity =2;
    }else if (amountEnemysKilled>10){
        newEnemyTimerVelocity =5;
    }

    previousAmountOfEnemies = activeEnemies.size();
    if(newEnemyTimer <= 0) {
        if (activeEnemies.size() < 4) {
            if(previousPosition == RIGHT) {
                activeEnemies.push_back(createNewEnemy(GBA_SCREEN_WIDTH-32));
                previousPosition = LEFT;
            }else{
                activeEnemies.push_back(createNewEnemy(0));
                previousPosition = RIGHT;
            }
            engine->updateSpritesInScene();
            newEnemyTimer = 500;
        }
    }else{
        newEnemyTimer= newEnemyTimer - newEnemyTimerVelocity;
    }

    ///UPDATE DIRECTION
    for(auto &e: activeEnemies) {
        int i = rand() % 10 + 1;
        switch(i) {
            case 1: e->setDirectionLeft(true);
            default: e->setDirectionLeft(false);
        }
    }

     


    attackCounter2++;


    //////////////////////////////// AIRBALL ////////////////////////////////////
    previousAmountOfAirballs = airBalls.size();
    ///ADD
    if (aang->isLaunchAirball()) {
        if (airBalls.size() < 5) {
            airBalls.push_back(createAirBall());
        }
    }
    ///REMOVE
    if(airBalls.size() != 0) {
        airBalls.erase(
                std::remove_if(airBalls.begin(), airBalls.end(),
                               [](std::unique_ptr<AirBall> &s) { return s->isOffScreen() || s->getCollided(); }),
                airBalls.end());
    }


    //////////////////////////////////// COLLISION DETECTIONS /////////////////////////////////////////
    bool deathEnemies = false;
    ///COLLISION DETECION AANG AND ENEMY
    if (aang->isAttacking()) {
        for (auto &e: activeEnemies) {
            if (attackCounter2 >= 40 && aang->getAangDownSprite()->collidesWith(*e->getEnemySprite())) {
                e->updateHealth(e->getHealth() - 1);
                if (e->getHealth() <= 0) {
                    deathEnemies = true;
                    amountEnemysKilled++;
                }
                attackCounter2 = 0;
            }
        }
        if (!aang->getAangDownSprite()->isAnimating()) {
            aang->getAangDownSprite()->makeAnimated(5, 4, 20);
        }
    } else {
        for (auto &e : activeEnemies) {
            //if (attackCounter2 >= 40 && aang->getAangDownSprite()->collidesWith(*e->getEnemySprite())) {
            if (attackCounter2 >= 40 && collidesWith(*aang->getAangDownSprite(), *e->getEnemySprite())) {
                aang->setHealth(aang->getHealth()-1);
                if(aang->getHealth()<=0){
                    auto scene_end = new Scene_End(engine, amountEnemysKilled);
                    engine->transitionIntoScene(scene_end, new FadeOutScene(5));
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

    ///COLLISION DETECTION ENEMY AND AIRBALL
    if(airBalls.size() > 0){
        for(auto& ab : airBalls){
            for(auto& e : activeEnemies) {
                if (attackCounter2 >= 40 && ab.get()->getSprite()->collidesWith(*e->getEnemySprite())) {
                    e->updateHealth(e->getHealth()-1);
                    if(e->getHealth()<=0){
                        deathEnemies = true;
                        amountEnemysKilled++;
                    }
                    attackCounter2 = 0;
                    ab->setCollided();
                }
            }
        }

    }

    ////Delete death enemys
    if(deathEnemies) {
        activeEnemies.erase(
                std::remove_if(activeEnemies.begin(), activeEnemies.end(),
                               [](std::unique_ptr<Enemy> &e) { return e->isDeath(); }),
                activeEnemies.end());
    }

    //// Checking if something changed with the airball or enemy sprites
    if(previousAmountOfAirballs != airBalls.size() || previousAmountOfEnemies != activeEnemies.size())  engine->updateSpritesInScene();

}

void Scene_Level1::moveOthers() {
    if (aang->isWalkingLeft() && !aang->isAttacking()) {
        for(auto& e: activeEnemies) {
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
        for(auto& e: activeEnemies) {
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

std::unique_ptr<AirBall> Scene_Level1::createAirBall() {
    if(aang->isLaunchLeft()){
        return std::unique_ptr<AirBall>(new AirBall(builder
                                                            .withLocation(aang->getAangDownSprite()->getX() - aang->getAangDownSprite()->getWidth() / 2, aang->getAangDownSprite()->getY() + aang->getAangDownSprite()->getHeight() / 4)
                                                            .buildWithDataOf(*someAirBallSprite), true));

    }else{
        return std::unique_ptr<AirBall>(new AirBall(builder
        .withLocation(aang->getAangDownSprite()->getX() + aang->getAangDownSprite()->getWidth() / 2, aang->getAangDownSprite()->getY() + aang->getAangDownSprite()->getHeight() / 4)
                                                            .buildWithDataOf(*someAirBallSprite), false));
    }
}

//COMMENTAAR DAT WEG MAG: Heb die methode beetje aangepast doordat ik de constructor van de Enemy heb aangepast
std::unique_ptr<Enemy> Scene_Level1::createNewEnemy(int xPosition) {

    /*return std::unique_ptr<Enemy>(new Enemy(   builder.withSize(SIZE_32_64)
                                                       .withLocation(200,60)
                                                       .buildWithDataOf(*someEnemySprite),
                                               builder.withSize(SIZE_16_8)
                                                       .withLocation(208,65)
                                                       .buildWithDataOf(*someHealthbarEnemySprite)));*/

    return std::unique_ptr<Enemy>(new Enemy(   builder.withSize(SIZE_32_64)
                                                       .withLocation(xPosition,63)
                                                       .buildWithDataOf(*someEnemySprite),
                                               builder.withSize(SIZE_16_8)
                                                       .withLocation(xPosition+8,68)
                                                       .buildWithDataOf(*someHealthbarEnemySprite)));


}

//Aangepaste methode van de engine
bool Scene_Level1::collidesWith(Sprite &s1, Sprite &s2) {
    if(s1.getX() < s2.getX() + s2.getWidth() - 30 &&
       s1.getX() + s1.getWidth() - 30 > s2.getX() &&
       s1.getY() < s2.getY() + s2.getHeight() - 30 &&
       s1.getHeight() + s1.getY() - 30 > s2.getY()) {
        return true;
    }
    return false;
}

