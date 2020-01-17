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
    int yPositionDefault = 87;
    double yVelocity;

    bool walkingLeft;
    bool walkingRight;
    bool jumping;
    bool attacking;
    bool moveOthers;
    bool launchAirball;
    bool launchLeft;


    int timer;
public:
    ///CONSTRUCTOR
    Aang(std::unique_ptr<Sprite> aangDownSprite,
            std::unique_ptr<Sprite> aangUpSprite,
            std::unique_ptr<Sprite> aangHealthbarSprite) :
            aangDownSprite(std::move(aangDownSprite)),
            aangUpSprite(std::move(aangUpSprite)),
            aangHealthbarSprite(std::move(aangHealthbarSprite)),
            health(3) {}

    ///GETTERS
    Sprite* getAangDownSprite() {return aangDownSprite.get();}
    Sprite* getAangUpSprite() {return aangUpSprite.get();}
    Sprite* getHealthBarSprite() {return aangHealthbarSprite.get();}


    int getHealth() {return health;}
    int getXVelocity() {return xVelocity;}
    bool isWalkingLeft() {return walkingLeft;}
    bool isWalkingRight() {return walkingRight;}
    bool isAttacking() {return attacking;}
    bool isMoveOthers() {return moveOthers;}
    bool isLaunchAirball() {return launchAirball;}
    bool isLaunchLeft() {return launchLeft;}

    void setHealth(int health);

    void tick(u16 keys);
    void move();
};

#endif //GBA_SPRITE_ENGINE_PROJECT_AANG_H
