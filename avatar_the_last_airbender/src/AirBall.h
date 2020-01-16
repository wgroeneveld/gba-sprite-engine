//
// Created by woute on 27/12/2019.
// With a lot of inspiration from demo 3
//

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
    bool left;
    bool collided;

public:
   // AirBall(std::unique_ptr<Sprite> airballSprite) : airballSprite(std::move(airballSprite)), left(true) {}
    AirBall(std::unique_ptr<Sprite> airballSprite, bool directionTogo) : airballSprite(std::move(airballSprite)), left(directionTogo), collided(false){}

    void tick();
    void setLeft(bool left);
    bool isOffScreen() { return airballSprite->isOffScreen(); }
    bool collidesWith(Sprite *ohterSprite){ return airballSprite->collidesWith(*ohterSprite);}
    Sprite* getSprite() { return airballSprite.get(); }
    void setCollided(){collided =true;}
    bool getCollided(){return collided;}
};




#endif //GBA_SPRITE_ENGINE_PROJECT_AIRBALL_H
