#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_LEVEL2_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_LEVEL2_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>

class Scene_Level2: public Scene {
private:
    std::unique_ptr<Sprite> aang;
    std::unique_ptr<Sprite> enemy;

    std::unique_ptr<Background> backgroundGround;
    std::unique_ptr<Background> backgroundSea;
    std::unique_ptr<Background> backgroundSun;

    int xVelocity = 1;
    double yVelocity;
    int time = 1;
    int xScrollingGround = 0;
    int xScrollingSea = 0;
    int xScrollingSun = 0;

    bool isWalkingLeft;
    bool isWalkingRight;
    bool isJumping;
    bool isAttacking;
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void moveAang();
    void moveOthers();

    Scene_Level2(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;
};

#endif
