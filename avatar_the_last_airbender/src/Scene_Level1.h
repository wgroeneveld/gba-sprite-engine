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
    /*
    std::unique_ptr<Sprite> aangDown;
    std::unique_ptr<Sprite> aangUp;
    std::unique_ptr<Sprite> healtbarAang;
     */

    std::unique_ptr<Sprite> someAangDownSprite;
    std::unique_ptr<Sprite> someAangUpSprite;
    std::unique_ptr<Sprite> someEnemySprite;
    std::unique_ptr<Sprite> someAirBallSprite;
    std::unique_ptr<Sprite> someHealthbarAangSprite;
    std::unique_ptr<Sprite> someHealthbarEnemySprite;

    std::unique_ptr<Background> backgroundGround;
    std::unique_ptr<Background> backgroundSea;
    std::unique_ptr<Background> backgroundSun;

    std::unique_ptr<Aang> aang;
    std::vector<std::unique_ptr<Enemy>> enemys;
    std::vector<std::unique_ptr<AirBall>> airBalls;

/*
    int xVelocity = 1;
    double yVelocity;
    int yPositionDefault = 83;
    int time = 1;

    bool isWalkingLeft;
    bool isWalkingRight;
    bool isJumping;
    bool isAttacking;
*/
    int xScrollingGround = 0;
    int xScrollingSea = 0;
    int xScrollingSun = 0;

    double healthAang;
    double enemySpawn;

    SpriteBuilder<Sprite> builder;
    void removeAirBallsOffScreen();
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void moveAang();
    void moveOthers();
    std::unique_ptr<Enemy> createNewEnemy();
    std::unique_ptr<AirBall> createAirBall(bool directionToGo);

    Scene_Level1(std::shared_ptr<GBAEngine> engine) : Scene(engine) {
        aang = std::unique_ptr<Aang>(new Aang(   builder
                                                         .withData(aangDownTiles, sizeof(aangDownTiles))
                                                         .withSize(SIZE_64_32)
                                                         .withLocation( 20,83)
                                                         .buildPtr(),
                                                builder
                                                        .withData(aangUpTiles, sizeof(aangUpTiles))
                                                        .withSize(SIZE_64_32)
                                                        .withLocation( GBA_SCREEN_WIDTH+10,GBA_SCREEN_HEIGHT +10)
                                                        .buildPtr(),
                                                 builder
                                                         .withData(healthbarAangTiles, sizeof(healthbarAangTiles))
                                                         .withSize(SIZE_32_16)
                                                         .withLocation( 10,10)
                                                         .buildPtr()

        /*
                                                builder.withSize(SIZE_64_32)
                                                         .withLocation(20,83)
                                                         .buildWithDataOf(*someAangDownSprite.get()),
                                                 builder.withSize(SIZE_64_32)
                                                         .withLocation(GBA_SCREEN_WIDTH+10,GBA_SCREEN_HEIGHT+10)
                                                         .buildWithDataOf(*someAangUpSprite.get()),
                                                 builder.withSize(SIZE_32_16)
                                                         .withLocation(10,10)
                                                         .buildWithDataOf(*someHealthbarEnemySprite.get())*/));
    }

    void load() override;
    void tick(u16 keys) override;
};

#endif
