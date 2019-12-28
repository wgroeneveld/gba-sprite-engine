//
// Created by SDM Technics on 28/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_METROID_H
#define GBA_SPRITE_ENGINE_PROJECT_METROID_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gba/tonc_math.h>

class Metroid {
private:
    std::unique_ptr<Sprite> metroid;

public:
    Metroid(std::unique_ptr<Sprite> sprite1) : metroid(std::move(sprite1)){}
    Sprite *getMetroid() {return metroid.get();}
    void tick(u16 keys);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_METROID_H
