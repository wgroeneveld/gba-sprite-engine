//
// Created by kyles on 3/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_LEVEL1_H
#define GBA_SPRITE_ENGINE_PROJECT_LEVEL1_H

#include <libgba-sprite-engine/scene.h>
#include "Metroid.h"
#include "Mario.h"
#include "Bullet.h"
#include "MarioBullet.h"

class Level1 : public Scene {
private:
    std::unique_ptr<Sprite> metroidBewegen;
    std::unique_ptr<Sprite> ball_projectiel;
    std::unique_ptr<Sprite> enemy;
    std::unique_ptr<Sprite> projectiel;
    std::unique_ptr<Sprite> firebolt;
    std::unique_ptr<Metroid> metroidObject;
    std::unique_ptr<Mario> enemyObject;
    std::unique_ptr<Bullet> bulletObject;
    std::unique_ptr<MarioBullet> marioBulletObject;
    std::unique_ptr<Background> bg;
    std::unique_ptr<Background> bg2;
    int scrollX, scrollY;



public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;


    Level1(std::shared_ptr<GBAEngine> engine) : Scene(engine), scrollX(0), scrollY(0) {}

    void load() override;
    void tick(u16 keys) override;

};



#endif //GBA_SPRITE_ENGINE_PROJECT_LEVEL1_H
