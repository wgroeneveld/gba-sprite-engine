#ifndef GBA_SPRITE_ENGINE_PROJECT_ENEMY_H
#define GBA_SPRITE_ENGINE_PROJECT_ENEMY_H

#include <libgba-sprite-engine/scene.h>

class Enemy {
private:
    std::unique_ptr<Sprite> enemy;
    std::unique_ptr<Sprite> healthbar;
    bool directionIsLeft;
    int health;
public:
    Enemy(std::unique_ptr<Sprite> enemySprite, std::unique_ptr<Sprite> healthbarSprite ) : enemy(std::move(enemySprite)), healthbar(std::move(healthbarSprite)),  directionIsLeft(true), health(3) {}

    Sprite* getEnemySprite() {return enemy.get();}
    Sprite* getHealthBarSprite() {return healthbar.get();}
    int getHealth(){return health;}
    void tick();
    void updateHealth(int health);
    void setDirectionIsLeft(bool left){ directionIsLeft = left;}
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENEMY_H
