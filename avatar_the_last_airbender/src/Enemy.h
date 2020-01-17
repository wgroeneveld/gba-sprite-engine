#ifndef GBA_SPRITE_ENGINE_PROJECT_ENEMY_H
#define GBA_SPRITE_ENGINE_PROJECT_ENEMY_H

#include <libgba-sprite-engine/scene.h>

class Enemy {
private:
    std::unique_ptr<Sprite> enemySprite;
    std::unique_ptr<Sprite> enemyHealthbarSprite;

    int health;
    bool walkingLeft;

    int timer = 0;
public:
    ///CONSTRUCTOR
    Enemy(std::unique_ptr<Sprite> enemySprite,
            std::unique_ptr<Sprite> healthbarSprite) :
            enemySprite(std::move(enemySprite)),
            enemyHealthbarSprite(std::move(healthbarSprite)),
            walkingLeft(true),
            health(3) {}

            ///GETTERS
    Sprite* getEnemySprite() {return enemySprite.get();}
    Sprite* getHealthBarSprite() {return enemyHealthbarSprite.get();}
    int getHealth(){return health;}
    bool isDeath(){return health <= 0;}

    ///SETTERS
    void setDirectionLeft(bool newDirectionLeft) { walkingLeft = newDirectionLeft;}

    ///OTHERS
    void tick();
    void updateHealth(int newHealth);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENEMY_H
