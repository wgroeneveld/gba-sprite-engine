//
// Created by Wouter Groeneveld on 08/08/18.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>

#include "arkanoid_game_scene.h"
#include "spritedata.h"
#include "pats.h"
#include "dead.h"

std::vector<Sprite *> ArkanoidGameScene::sprites() {
    return {
        paddle.get(), ball.get()
    };
}

std::vector<Background *> ArkanoidGameScene::backgrounds() {
    return {};
}

void ArkanoidGameScene::youDied() {
    if(highscore < ticks) highscore = ticks;
    engine.get()->enqueueSound(raw_dead, raw_dead_bytes, 32000);
    ball->setVelocity(0, 0);
    TextStream::instance() << "You DIED - start to reset";
    dead = true;
}

void ArkanoidGameScene::resetGame() {
    dead = false;
    ticks = 0;

    TextStream::instance().clear();
    ball->moveTo(110, 140);
    ball->setVelocity(1, 1);
    paddle->moveTo(100, 150);
}

void ArkanoidGameScene::tick(u16 keys) {
    if(dead && (keys & KEY_START)) {
        resetGame();
        return;
    }

    if(dead) return;

    TextStream::instance().setText(std::string("Ticks: ") + std::to_string(ticks), 5, 10);
    TextStream::instance().setText(std::string("Highscore: ") + std::to_string(highscore), 7, 10);

    if(ball->getX() <= 0 || ball->getX() >= (GBA_SCREEN_WIDTH - ball->getWidth())) {
        ball->setVelocity(-ball->getDx(), ball->getDy());
    }else if(ball->getY() <= 0) {
        ball->setVelocity(ball->getDx(), -ball->getDy());
    } else if(ball->getY() >= (GBA_SCREEN_HEIGHT - ball->getHeight())) {
       youDied();
       return;
    } else if(ball->collidesWith(*paddle)) {
        if(ticks > 1 && ticks % 5 == 0) {
            ball->setVelocity(ball->getDx() + 1, ball->getDy() + 1);
        }

        // lousy implementation; ball could also hit paddle from right/left, meaning *BOOM*
        ball->setVelocity(ball->getDx(), -ball->getDy());
        engine.get()->enqueueSound(pats, sizeof(pats), 32000);

        ticks++;
    }

    if(keys & KEY_LEFT) {
        paddle->setVelocity(-2, 0);
    } else if(keys & KEY_RIGHT) {
        paddle->setVelocity(+2, 0);
    } else {
        paddle->setVelocity(0, 0);
    }
}

void ArkanoidGameScene::load() {
    engine.get()->enableText();
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(paletteSharedPal, sizeof(paletteSharedPal)));

    SpriteBuilder<Sprite> builder;

    ball = builder
            .withSize(SIZE_8_8)
            .withLocation(110, 140)
            .withData(ballTiles, sizeof(ballTiles))
            .withVelocity(1, 1)
            .buildPtr();

    paddle = builder
            .withSize(SIZE_32_8)
            .withLocation(100, 150)
            .withData(paddleTiles, sizeof(paddleTiles))
            .withinBounds()
            .buildPtr();
}