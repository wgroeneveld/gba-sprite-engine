#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>

#include "Scene_Level1.h"

#include "sprites/sprite_aang.h"
#include "sprites/sprite_enemy.h"
#include "sprites/sprite_pal.h"
#include "sprites/sprite_airball.h"

#include "background_game/background1_set.h"
#include "background_game/background1_map.h"
#include "background_game/background2_set.h"
#include "background_game/background2_map.h"
#include "background_game/background_pal.h"

#include "math.h"
#include <algorithm>

#define AIRBALL_ROTATION_DIFF (128*6)

Scene_Level1::Scene_Level1(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Background *> Scene_Level1::backgrounds() {
    return {  backgroundGround.get(), backgroundSea.get()};
}

std::vector<Sprite *> Scene_Level1::sprites() {
    std::vector<Sprite*> sprites;
    for(auto& ab : airBalls ){
        sprites.push_back(ab->getSprite());
    }
    if(healthEnemey>0) sprites.push_back(enemy.get());
    sprites.push_back(aang.get());
    sprites.push_back(someAirBallSprite.get());

    return sprites;
}


void Scene_Level1::removeAirBallsOffScreen() {
    airBalls.erase(
            std::remove_if(airBalls.begin(), airBalls.end(), [](std::unique_ptr<AirBall> &s) { return s->isOffScreen(); }),
            airBalls.end());*/
}

void Scene_Level1::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(spritesPal, sizeof(spritesPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(backgroundPal, sizeof(backgroundPal)));

    backgroundGround = std::unique_ptr<Background>(new Background(1, background1Tiles, sizeof(background1Tiles),background1Map , sizeof(background1Map), 9, 1, MAPLAYOUT_32X64));
    backgroundSea = std::unique_ptr<Background>(new Background(2, background2Tiles, sizeof(background2Tiles),background2Map , sizeof(background2Map), 25, 2, MAPLAYOUT_32X32));

    spriteBuilder = std::unique_ptr<SpriteBuilder<Sprite>>(new SpriteBuilder<Sprite>);
    SpriteBuilder<Sprite> builder;
    SpriteBuilder<AffineSprite> affBuilder;


    someAirBallSprite = builder
            .withData(airballTiles, sizeof(airballTiles))
            .withSize(SIZE_16_16)
            .withAnimated(2,5)
            .withLocation( GBA_SCREEN_WIDTH+10,GBA_SCREEN_HEIGHT +10)
            .buildPtr();



    enemy = affBuilder
            .withData(enemyTiles, sizeof(enemyTiles))
            .withSize(SIZE_32_32)
            .withLocation(150,75)
            .buildPtr();

    aang = builder
            .withData(aangTiles, sizeof(aangTiles))
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


void Scene_Level1::tick(u16 keys) {

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

std::unique_ptr<AirBall> Scene_Level1::createAirBall() {
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