#ifndef GBA_SPRITE_ENGINE_PROJECT_ENEMY_H
#define GBA_SPRITE_ENGINE_PROJECT_ENEMY_H

#include <libgba-sprite-engine/scene.h>

class Enemy {
private:

    std::unique_ptr<Sprite> enemySprite;
    std::unique_ptr<Sprite> healthbarSprite;

    bool staticPosition;
    int beginXPosition;
    int endXPosition;
    int health;
public:
    enum Direction {LEFT, RIGHT}; // ik heb deze twee public gemaakt omdat ik er zo aankom in level1scene
    Direction direction;
    Enemy(std::unique_ptr<Sprite> enemySprite, std::unique_ptr<Sprite> healthbarSprite, int beginXPosition, int endXPosition, bool staticPosition) : enemySprite(std::move(enemySprite)), healthbarSprite(std::move(healthbarSprite)), beginXPosition(beginXPosition), endXPosition(endXPosition), staticPosition(staticPosition), direction(LEFT), health(3) {}
    //Enemy(std::unique_ptr<Sprite> enemySprite, std::unique_ptr<Sprite> healthbarSprite) : enemySprite(std::move(enemySprite)), healthbarSprite(std::move(healthbarSprite)), direction(LEFT), health(3) {}

    Sprite* getEnemySprite() {return enemySprite.get();}
    Sprite* getHealthBarSprite() {return healthbarSprite.get();}
    int getHealth(){return health;}
    int getBeginXPosition() { return beginXPosition;}
    int getEndXPosition() { return endXPosition;}
    bool isStaticPosition() { return isStaticPosition();}
    void tick();
    void updateHealth(int health);
    void setDirection(Direction dir){this->direction = dir;}
    bool isDeath(){ return health <= 0; }

};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENEMY_H
