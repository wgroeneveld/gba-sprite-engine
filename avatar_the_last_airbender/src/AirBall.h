#ifndef GBA_SPRITE_ENGINE_PROJECT_AIRBALL_H
#define GBA_SPRITE_ENGINE_PROJECT_AIRBALL_H

#include <libgba-sprite-engine/sprites/sprite.h>
#ifdef CODE_COMPILED_AS_PART_OF_TEST
#include <libgba-airballSprite-engine/gba/tonc_math_stub.h>
#else
#include <libgba-sprite-engine/gba/tonc_math.h>
#endif
#include <deque>

class AirBall {
private:
    std::unique_ptr<Sprite> airballSprite;

    bool flyingLeft;
    bool collided;
public:
    ///CONSTRUCTOR
    AirBall(std::unique_ptr<Sprite> airballSprite,
            bool flyingLeft) :
            airballSprite(std::move(airballSprite)),
            flyingLeft(flyingLeft),
            collided(false){}

    ///GETTERS
    Sprite* getSprite() {return airballSprite.get();}
    bool getCollided(){ return collided; }
    bool isOffScreen() {return airballSprite->isOffScreen();}
    bool collidesWith(Sprite *otherSprite){return airballSprite->collidesWith(*otherSprite);}

    ///SETTERS
    void setCollided(){collided =true;}

    ///OTHERS
    void tick();
};




#endif //GBA_SPRITE_ENGINE_PROJECT_AIRBALL_H
