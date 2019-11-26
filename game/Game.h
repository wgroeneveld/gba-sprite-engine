//
// Created by Erwin on 21/11/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAME_H
#define GBA_SPRITE_ENGINE_PROJECT_GAME_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "Startscreen.h"

class Game {
private:

public:
    Startscreen *getStartScene(){return startscreen1();}

    void setStartscreen(Startscreen start) {startscreen1 = scene;}
};

#endif //GBA_SPRITE_ENGINE_PROJECT_GAME_H
