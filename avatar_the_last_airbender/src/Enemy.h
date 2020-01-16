#ifndef GBA_SPRITE_ENGINE_PROJECT_ENEMY_H
#define GBA_SPRITE_ENGINE_PROJECT_ENEMY_H

#include <libgba-sprite-engine/scene.h>

class Enemy {
private:
    std::unique_ptr<Sprite> enemySprite;
    std::unique_ptr<Sprite> healthbarSprite;

    int health;
    bool directionLeft;
public:
    Enemy(std::unique_ptr<Sprite> enemySprite, std::unique_ptr<Sprite> healthbarSprite) : enemySprite(std::move(enemySprite)), healthbarSprite(std::move(healthbarSprite)), directionLeft(true), health(3) {}

    Sprite* getEnemySprite() {return enemySprite.get();}
    Sprite* getHealthBarSprite() {return healthbarSprite.get();}
    int getHealth(){return health;}
    bool isDeath(){ return health <= 0; }

    void setDirectionLeft(bool newDirectionLeft) { directionLeft = newDirectionLeft;}

    void tick();
    void updateHealth(int health);



};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENEMY_H
