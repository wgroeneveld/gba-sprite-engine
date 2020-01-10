#ifndef GBA_SPRITE_ENGINE_PROJECT_ENEMY_H
#define GBA_SPRITE_ENGINE_PROJECT_ENEMY_H

#include <libgba-sprite-engine/scene.h>

class Enemy {
private:
    std::unique_ptr<Sprite> enemy;
    std::unique_ptr<Sprite> healthbar;

    int health;
public:
    Enemy(std::unique_ptr<Sprite> enemy, std::unique_ptr<Sprite> healthbar) : enemy(std::move(enemy)), healthbar(std::move(healthbar)) {}

    Sprite* getEnemySprite() {return enemy.get();};
    Sprite* getHealthBarSprite() {return healthbar.get();};
    void updateHealth(int health);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENEMY_H
