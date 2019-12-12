//
// Created by woute on 9/12/2019.
//

#include "Level1_scene.h"
#include "background_game/background_water.h"
#include "background_game/background_earth_tilemap.h"
#include "background_game/background_earth_data.h"

#include "aang/aang.h"
#include "math.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

std::vector<Background *> Level1_scene::backgrounds() {
    return { background.get()};
}

std::vector<Sprite *> Level1_scene::sprites() {
    return {  aang.get()};
}

void Level1_scene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(aangPal, sizeof(aangPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(background_earth_data2Pal, sizeof(background_earth_data2Pal)));

    background = std:: unique_ptr<Background>(new Background(0, background_earth_data2Tiles, sizeof(background_earth_data2Tiles),background_earth_tilemap , sizeof(background_earth_tilemap)));
    //background.get()->useMapScreenBlock(64);

    SpriteBuilder<Sprite> builder;

    aang = builder
            .withData(aangTiles, sizeof(aangTiles))
            .withSize(SIZE_64_64)
            .withLocation(50, 100)
            .buildPtr();
    }

int xVelocity = 1;
double yVelocity;
int time = 1;
bool isWalking;
bool isJumping;

void Level1_scene::tick(u16 keys) {
    if((keys & KEY_LEFT)) {
        if(aang->getX()-2>0) {
            aang->flipHorizontally(true);
            aang->moveTo(aang->getX() - xVelocity, aang->getY());
            if(!aang->isAnimating()) {
                isWalking = true;
                aang->makeAnimated(1,2,15);
            }
        }
    } else if(keys & KEY_RIGHT) {
        if (aang->getX() + 2 < 240) {
            aang->flipHorizontally(false);
            aang->moveTo(aang->getX() + xVelocity, aang->getY());
            if (!aang->isAnimating()) {
                isWalking = true;
                aang->makeAnimated(1, 2, 15);
            }
        }
    }
    else {
        aang->stopAnimating();
        aang->animateToFrame(0);
    }


    if(keys & KEY_UP) {
        if(!isJumping) isJumping = true;
    }

    if(isJumping) {
        if (isWalking) {
            isWalking = false;
            aang->stopAnimating();
            aang->animateToFrame(0);
        }
        if(!aang->isAnimating()) {
            aang->makeAnimated(3, 2, 15);
        }
        yVelocity = -(pow(((0.2 * time) - 3),2))+((2*time)-3)+12;
        int yPosition = 100 - yVelocity;
        aang->moveTo(aang->getX(), yPosition);
        if(aang->getY() != 100) {
            time++;
        }
        else {
            isJumping = false;
            time = 1;
            aang->stopAnimating();
            aang->animateToFrame(0);
        }
    }
}