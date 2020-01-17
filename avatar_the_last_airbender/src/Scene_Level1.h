#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_LEVEL1_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_LEVEL1_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>

#include "data/sprites/sprite_aangdown.h"
#include "data/sprites/sprite_aangup.h"
#include "data/sprites/sprite_healthbaraang.h"

#include "Aang.h"
#include "Enemy.h"
#include "AirBall.h"

class Scene_Level1: public Scene {
private:
    std::unique_ptr<Aang> aang;
    std::vector<std::unique_ptr<Enemy>> activeEnemies;
    std::vector<std::unique_ptr<AirBall>> airBalls;

    std::unique_ptr<Sprite> someEnemySprite;
    std::unique_ptr<Sprite> someAirBallSprite;
    std::unique_ptr<Sprite> someHealthbarEnemySprite;

    std::unique_ptr<Background> backgroundGround;
    std::unique_ptr<Background> backgroundSea;
    std::unique_ptr<Background> backgroundSun;

    int xScrollingGround = 0;
    int xScrollingSea = 0;
    int xScrollingSun = 0;

    int amountEnemysKilled=0;
    double attackCounter2 =0;
    double newEnemyTimer = 0;
    double newEnemyTimerVelocity =1;
    bool previousEnemyPositionLeft=false;

    int previousAmountOfAirballs=0;
    int previousAmountOfEnemies =0;

    SpriteBuilder<Sprite> builder;
public:
    ///CONSTRUCTOR
    Scene_Level1(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    ///GETTERS
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    ///OTHERS
    void load() override;
    void tick(u16 keys) override;
    std::unique_ptr<Enemy> createNewEnemy(int xPosition);
    std::unique_ptr<AirBall> createAirBall();
    void moveOthers();
    bool collidesWith(Sprite &s1, Sprite &s2);
};

#endif
