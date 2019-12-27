//
// Created by woute on 9/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_LEVEL1_SCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_LEVEL1_SCENE_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include "AirBall.h"

class Level1_scene: public Scene {
private:
    std::unique_ptr<Sprite> aang;
    std::unique_ptr<AffineSprite> enemy;
    std::unique_ptr<Sprite> someAirBallSprite;
    std::vector<std::unique_ptr<AirBall>> airBalls;

    std::unique_ptr<Background> background;
    int angle;

    std::unique_ptr<SpriteBuilder<Sprite>> spriteBuilder;
    std::unique_ptr<AirBall> createAirBall();
    void removeAirBallsOffScreen();

    VECTOR rotateAround(VECTOR center, VECTOR point);
    VECTOR defaultBulletTarget;

public:
    explicit Level1_scene(const std::shared_ptr<GBAEngine> &engine);
    Level1_scene(Level1_scene& other) = delete;

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    //Level1_scene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_LEVEL1_SCENE_H
