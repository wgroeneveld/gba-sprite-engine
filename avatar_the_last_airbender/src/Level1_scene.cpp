//
// Created by woute on 9/12/2019.
//

#include "Level1_scene.h"
/*
#include "background_game/background_water.h"
#include "background_game/background_earth_tilemap.h"
#include "background_game/background_earth_data.h"
 */
#include "background_game/background_set.h"
#include "background_game/background_map.h"

#include "grit/aang.h"
#include "grit/enemy.h"
#include "grit/shared.h"

#include "math.h"
#include "grit/air_ball_data.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <algorithm>

#define AIRBALL_ROTATION_DIFF (128*6)

Level1_scene::Level1_scene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Background *> Level1_scene::backgrounds() {
    return {  background0.get()};
}

std::vector<Sprite *> Level1_scene::sprites() {
    std::vector<Sprite*> sprites;
    for(auto& ab : airBalls ){
        sprites.push_back(ab->getSprite());
    }
    if(healthEnemey>0) sprites.push_back(enemy.get());
    sprites.push_back(aang.get());
    sprites.push_back(someAirBallSprite.get());

    return sprites;
}

void Level1_scene::removeAirBallsOffScreen() {
    airBalls.erase(
            std::remove_if(airBalls.begin(), airBalls.end(), [](std::unique_ptr<AirBall> &s) { return s->isOffScreen(); }),
            airBalls.end());
}

void Level1_scene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal3, sizeof(sharedPal3)));

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(backgroundPal, sizeof(backgroundPal)));

    background0 = std:: unique_ptr<Background>(new Background(1, backgroundTiles, sizeof(backgroundTiles),backgroundMap , sizeof(backgroundMap)));
    background0.get()->useMapScreenBlock(16);

    spriteBuilder = std::unique_ptr<SpriteBuilder<Sprite>>(new SpriteBuilder<Sprite>);
    SpriteBuilder<Sprite> builder;
    SpriteBuilder<AffineSprite> affBuilder;


    someAirBallSprite = builder
            .withData(air_set_16Tiles, sizeof(air_set_16Tiles))
            .withSize(SIZE_16_16)
            .withAnimated(2,5)
            .withLocation( GBA_SCREEN_WIDTH+10,GBA_SCREEN_HEIGHT +10)
            .buildPtr();

    angle = 90;

    enemy = affBuilder
            .withData(enemy_32Tiles, sizeof(enemy_32Tiles))
            .withSize(SIZE_32_32)
            .withLocation(150,75)
            .buildPtr();

    aang = builder
            .withData(aang_32Tiles, sizeof(aang_32Tiles))
            .withSize(SIZE_32_32)
            .withLocation(100,81)
            .buildPtr();
    aang->setStayWithinBounds(true);


    healthAang = 100;
    healthEnemey = 50;

}

int xVelocity = 1;
double yVelocity;
int time = 1;
int countEnemy = 1;

bool isWalkingLeft;
bool isWalkingRight;
bool aangIsGoingLeft;
bool isJumping;
bool isAttacking;

double attackCounter =0;


void Level1_scene::tick(u16 keys) {

    TextStream::instance().setText( std::string(" Health aang: ") + std::to_string(healthAang), 3, 1);
    TextStream::instance().setText( std::string(" Health enemy: ") + std::to_string(healthEnemey), 4, 1);
    TextStream::instance().setText(std::string(" Attack counter: ") +std::to_string(attackCounter), 5,1);

    if(keys & KEY_LEFT) {
        if(!isWalkingLeft) isWalkingLeft = true;
        aangIsGoingLeft = true;
    }
    else {
        isWalkingLeft = false;
    }
    if(keys & KEY_RIGHT) {
        if(!isWalkingRight) isWalkingRight = true;
        aangIsGoingLeft = false;
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
        yVelocity = -(pow(((0.25 * time) - 3),2))+((2*time)-3)+12;
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

////COLLISION DETECION AANG AND ENEMY ////
    if(isAttacking) {
        if(attackCounter>= 40 && aang.get()->collidesWith(*enemy.get())){
            healthEnemey--;
            if(healthEnemey<0) engine.get()->updateSpritesInScene();
            attackCounter=0;
        }
        if(!aang->isAnimating()) aang->makeAnimated(5, 4, 12);
    } else {
        if(attackCounter>= 40 && aang.get()->collidesWith(*enemy.get())){
            healthAang--;
            attackCounter =0;
        }
    }




    ///AIRBALL-SHOOTING + END OF ATTACK ACTION///

    int oldAirBallsSize = airBalls.size();
    removeAirBallsOffScreen();
    TextStream::instance().setText(std::string("Amount of airBalls: ") + std::to_string(airBalls.size()), 1, 1);
    if(aang->getCurrentFrame() > 7) {
        isAttacking = false;
        aang->stopAnimating();
        aang->animateToFrame(0);

        // een airball afschieten:
        if(airBalls.size() < 10) {
            airBalls.push_back(createAirBall());

            auto &ab = airBalls.at(airBalls.size()-1);
            ab->setLeft(aangIsGoingLeft);

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
            if(attackCounter >= 40 && ab.get()->getSprite()->collidesWith(*enemy.get())) {
                healthEnemey -= 20;
                attackCounter = 0;
                positionToBeDeleted = position;
            }
            position++;
        }
    }

    if(positionToBeDeleted>=0) {
        airBalls.erase(airBalls.begin()+positionToBeDeleted);
        engine.get()->updateSpritesInScene();
    }


    ///////////
    ///ENEMY///
    ///////////
    if(countEnemy>=100){
        countEnemy =0;
        enemy->moveTo(enemy->getX() -5, enemy->getY());
        enemy->flipHorizontally(true);

    } else{
        countEnemy++;
    }
    attackCounter++;
}

std::unique_ptr<AirBall> Level1_scene::createAirBall() {
    if(aangIsGoingLeft){
        return std::unique_ptr<AirBall>(new AirBall(spriteBuilder
                                                            ->withLocation(aang->getX() - aang->getWidth() / 2, aang->getY() + aang->getHeight() / 4)
                                                            .buildWithDataOf(*someAirBallSprite.get())));

    }else{
     return std::unique_ptr<AirBall>(new AirBall(spriteBuilder
                                                    ->withLocation(aang->getX() + aang->getWidth() / 2, aang->getY() + aang->getHeight() / 4)
                                                      .buildWithDataOf(*someAirBallSprite.get())));
    }
}