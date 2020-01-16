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

    std::unique_ptr<Sprite> someEnemySprite;
    std::unique_ptr<Sprite> someAirBallSprite;
    std::unique_ptr<Sprite> someHealthbarEnemySprite;

    std::unique_ptr<Background> backgroundGround;
    std::unique_ptr<Background> backgroundSea;
    std::unique_ptr<Background> backgroundSun;

    std::unique_ptr<Aang> aang;
    std::vector<std::vector<std::unique_ptr<Enemy>>> enemies;
    std::vector<std::unique_ptr<Enemy>> enemysSection1;
    std::vector<std::unique_ptr<Enemy>> activeEnemies;
    std::vector<std::unique_ptr<AirBall>> airBalls;

    int xScrollingGround = 0;
    int xScrollingSea = 0;
    int xScrollingSun = 0;

    int amountEnemysKilled=0;
    double attackCounter2 =0;
    //COMMENTAAR DAT WEG MAG: Is niet meer nodig als we de enemies op voorhand plaatsen
    double newEnemyTimer = 0;
    double newEnemyTimerVelocity =1;
    bool enemiesUpdated;

    enum Direction {LEFT, RIGHT};
    Direction previousPosition = LEFT;   //Dit houdt bij aan welke kant van eht scherm de vorige enemy gekomen is


    int previousAmountOfAirballs=0;
    int previousAmountOfEnemies =0;

    SpriteBuilder<Sprite> builder;
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void moveOthers();
    std::unique_ptr<Enemy> createNewEnemy(int beginXPosition, int endXPosition, bool staticPosition);
    std::unique_ptr<AirBall> createAirBall();

    Scene_Level1(std::shared_ptr<GBAEngine> engine) : Scene(engine) {    }

    void load() override;
    void tick(u16 keys) override;
};

#endif
