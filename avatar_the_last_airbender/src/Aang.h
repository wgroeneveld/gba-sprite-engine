#ifndef GBA_SPRITE_ENGINE_PROJECT_AANG_H
#define GBA_SPRITE_ENGINE_PROJECT_AANG_H

#include <libgba-sprite-engine/scene.h>



class Aang {
private:
    std::unique_ptr<Sprite> aangDownSprite;
    std::unique_ptr<Sprite> aangUpSprite;
    std::unique_ptr<Sprite> aangHealthbarSprite;

    int health=3;
    int xVelocity = 1;
    double yPosition;
    double yVelocity;
    int time;
    int yPositionDefault = 87;

    bool walkingLeft;
    bool walkingRight;
    bool jumping;
    bool attacking;
    bool moveOthers;
    bool launchAirball;

public:
    Aang(std::unique_ptr<Sprite> aangDownSprite, std::unique_ptr<Sprite> aangUpSprite,  std::unique_ptr<Sprite> aangHealthbarSprite) : aangDownSprite(std::move(aangDownSprite)), aangUpSprite(std::move(aangUpSprite)), aangHealthbarSprite(std::move(aangHealthbarSprite)), health(3) {}

    Sprite* getAangDownSprite() {return aangDownSprite.get();}
    Sprite* getAangUpSprite() {return aangUpSprite.get();}
    Sprite* getHealthBarSprite() {return aangHealthbarSprite.get();}

    void tick(u16 keys);


    int getHealth() {return health;}
    int getXVelocity() {return xVelocity;}
    double getYPosition() {return yPosition;}
    int getYPositionDefault() {return yPositionDefault;}
    bool isWalkingLeft() {return walkingLeft;}
    bool isWalkingRight() {return walkingRight;}
    bool isJumping() {return jumping;}
    bool isAttacking() {return attacking;}
    bool isLaunchAirball() {return launchAirball;}
    bool isMoveOthers() {return moveOthers;}

    void setHealth(int health);

    void move();
};

#endif //GBA_SPRITE_ENGINE_PROJECT_AANG_H
