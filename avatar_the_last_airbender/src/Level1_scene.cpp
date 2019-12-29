//
// Created by woute on 9/12/2019.
//

#include "Level1_scene.h"
/*
#include "background_game/background_water.h"
#include "background_game/background_earth_tilemap.h"
#include "background_game/background_earth_data.h"
 */
#include "background_game/background_tileset.h"
#include "background_game/background_tilemap.h"

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
    return { background.get()};
}

std::vector<Sprite *> Level1_scene::sprites() {
    std::vector<Sprite*> sprites;

    for(auto& ab : airBalls ){
        sprites.push_back(ab->getSprite());
    }
    sprites.push_back(enemy.get());
    sprites.push_back(aang.get());

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

    background = std:: unique_ptr<Background>(new Background(0, backgroundTiles, sizeof(backgroundTiles),backgroundMap , sizeof(backgroundMap)));
    background.get()->useMapScreenBlock(16);


    spriteBuilder = std::unique_ptr<SpriteBuilder<Sprite>>(new SpriteBuilder<Sprite>);
    SpriteBuilder<Sprite> builder;
    SpriteBuilder<AffineSprite> affBuilder;


    someAirBallSprite = spriteBuilder
            ->withData(air_set_16Tiles, sizeof(air_set_16Tiles))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_WIDTH - 20, GBA_SCREEN_HEIGHT - 20)
            .buildPtr();
    angle = 90;

    defaultBulletTarget = { GBA_SCREEN_WIDTH / 2, GBA_SCREEN_HEIGHT + (GBA_SCREEN_WIDTH / 2) - aang->getCenter().y + 40};

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


}


VECTOR Level1_scene::rotateAround(VECTOR center, VECTOR point) {
    return GBAVector(center).rotateAsCenter(point, angle);
}

int xVelocity = 1;
double yVelocity;
int time = 1;
int countEnemy = 1;

bool isWalkingLeft;
bool isWalkingRight;
bool isJumping;
bool isAttacking;

double healthAang = 100;
double healthEnemey = 50;
double attackCounter =0;


void Level1_scene::tick(u16 keys) {

    TextStream::instance().setText( std::string(" Health aang: ") + std::to_string(healthAang), 3, 1);
    TextStream::instance().setText( std::string(" Health enemy: ") + std::to_string(healthEnemey), 4, 1);
    TextStream::instance().setText(std::string(" Attack counter: ") +std::to_string(attackCounter), 5,1);
    TextStream::instance().setText(std::string(" Airball angle: ") +std::to_string(angle), 6,1);

    if(keys & KEY_LEFT) {
        if(!isWalkingLeft) isWalkingLeft = true;
    }
    else {
        isWalkingLeft = false;
    }
    if(keys & KEY_RIGHT) {
        if(!isWalkingRight) isWalkingRight = true;
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

    if(isAttacking) {
        if(attackCounter>= 40 && aang.get()->collidesWith(*enemy.get())){
            healthEnemey--;
            attackCounter=0;
        }
        if(!aang->isAnimating()) aang->makeAnimated(5, 4, 12);
    }
    if(!isAttacking) {
        if(attackCounter>= 40 && aang.get()->collidesWith(*enemy.get())){
            healthAang--;
            attackCounter =0;
        }
    }

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
            auto destination = rotateAround(aang->getCenter(),defaultBulletTarget);
            destination.y = 60;
            destination.x= 999;
            TextStream::instance().setText(std::string("shooting dest: ") + std::to_string(destination.x) + std::string(",") + std::to_string(destination.y), 16, 1);
            ab->setDestination(destination);
        }
    }


    if(oldAirBallsSize != airBalls.size()) {
        engine.get()->updateSpritesInScene();

        TextStream::instance().setText(std::string(" in de tweede if old:") +std::to_string(oldAirBallsSize) +std::string(" new:") +std::to_string(airBalls.size()), 7,1);
    }

    for(auto &ab : airBalls) {

        TextStream::instance().setText(std::string(" in the for, voor tick, oldAirBallsSize=  ") +std::to_string(oldAirBallsSize), 7,1);
        ab->tick();
        TextStream::instance().setText(std::string(" in the for, na tick, oldAirBallsSize=  ") +std::to_string(oldAirBallsSize), 7,1);
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
     return std::unique_ptr<AirBall>(new AirBall(spriteBuilder
                                                    ->withLocation(aang->getX() + aang->getWidth() / 2, aang->getY() + aang->getHeight() / 2)
                                                      .buildWithDataOf(*someAirBallSprite.get())));

}