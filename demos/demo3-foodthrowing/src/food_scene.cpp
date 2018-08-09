//
// Created by Wouter Groeneveld on 09/08/18.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <algorithm>
#include <libgba-sprite-engine/background/text_stream.h>
#include "food_scene.h"
#include "avatar.h"
#include "bullet.h"

#define AVATAR_ROTATION_DIFF 300
#define MAX_AMOUNT_OF_BULLETS 40
#define BULLET_COOLDOWN_START 20

FoodScene::FoodScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine), bulletCooldown(BULLET_COOLDOWN_START) {}

std::vector<Background *> FoodScene::backgrounds() {
    return {};
}

std::vector<Sprite *> FoodScene::sprites() {
    std::vector<Sprite*> sprites;
    // TODO order is important for affine transformations because of affinity - those always last!
    // some kind of affine bug depending on the order of sprites added in OAM
    for(auto& b : bullets) {
        sprites.push_back(b.get());
    }
    sprites.push_back(someBullet.get());
    sprites.push_back(avatar.get());

    return sprites;
}

void FoodScene::removeBulletsOffScreen() {
    bullets.erase(
            std::remove_if(bullets.begin(), bullets.end(), [](std::unique_ptr<Sprite> &s) { return s->isOffScreen(); }),
            bullets.end());
}

void FoodScene::tick(u16 keys) {
    avatar->animateToFrame(0);
    bool bulletAdded, allowedToShoot;

    if(bulletCooldown > 0) {
        bulletCooldown--;
    } else if(bulletCooldown == 0) {
        allowedToShoot = true;
    }

    removeBulletsOffScreen();
    TextStream::instance().setText(std::to_string(bullets.size()) + std::string(" bullets"), 1, 1);
    TextStream::instance().setText(std::to_string(bulletCooldown) + std::string(" cooldown"), 2, 1);

    if(keys & KEY_LEFT) {
        avatarRotation -= AVATAR_ROTATION_DIFF;
    } else if(keys & KEY_RIGHT) {
        avatarRotation += AVATAR_ROTATION_DIFF;
    }
    if((keys & KEY_A) && allowedToShoot) {
        avatar->animateToFrame(1);

        if(bullets.size() < MAX_AMOUNT_OF_BULLETS) {
            bulletCooldown = BULLET_COOLDOWN_START;
            bullets.push_back(createBullet());
            bulletAdded = true;

            auto &b = bullets.at(bullets.size() - 1);
        }
    }

    avatar->rotate(avatarRotation);

    if(bulletAdded) {
        engine->updateSpritesInScene();
    }
 }

 std::unique_ptr<Sprite> FoodScene::createBullet() {
    return spriteBuilder->withVelocity(1, 1)
            .withLocation(avatar->getX(), avatar->getY())
            .buildWithDataOf(*someBullet.get());
}

void FoodScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(avatar_palette, sizeof(avatar_palette)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    spriteBuilder = std::unique_ptr<SpriteBuilder<Sprite>>(new SpriteBuilder<Sprite>);
    SpriteBuilder<AffineSprite> affineBuilder;

    // Doom avatar copyright iD Software
    avatar = affineBuilder.withData(avatar_data, sizeof(avatar_data))
            .withSize(SIZE_64_64)
            .withAnimated(2, 3)
            .withLocation(GBA_SCREEN_WIDTH / 2 - 32, GBA_SCREEN_HEIGHT / 2 - 32)
            .buildPtr();
    avatar->stopAnimating();
    avatarRotation = 0;

    someBullet = spriteBuilder->withData(bullet_data, sizeof(bullet_data))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_WIDTH + 20, GBA_SCREEN_HEIGHT + 20)
            .buildPtr();
}