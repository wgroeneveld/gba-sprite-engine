#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_LEVEL1_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_LEVEL1_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>

#include "AirBall.h"

class Scene_Level1: public Scene {
private:
    std::unique_ptr<Sprite> aang;
    std::unique_ptr<AffineSprite> enemy;
    std::unique_ptr<Sprite> someAirBallSprite;
    std::vector<std::unique_ptr<AirBall>> airBalls;

    std::unique_ptr<Background> backgroundGround;
    std::unique_ptr<Background> backgroundSea;

    double healthEnemey;
    double healthAang;

    std::unique_ptr<SpriteBuilder<Sprite>> spriteBuilder;
    std::unique_ptr<AirBall> createAirBall();
    void removeAirBallsOffScreen();

    VECTOR rotateAround(VECTOR center, VECTOR point);
    VECTOR defaultBulletTarget;

public:
    explicit Scene_Level1(const std::shared_ptr<GBAEngine> &engine);
    Scene_Level1(Scene_Level1& other) = delete;

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;

};

#endif
