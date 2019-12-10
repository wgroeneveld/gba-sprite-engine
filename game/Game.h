//
// Created by Erwin on 21/11/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAME_H
#define GBA_SPRITE_ENGINE_PROJECT_GAME_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "Start_Screen.h"
#include "ChooseCharacter_Screen.h"
#include "Start_Screen.h"

class Game {
private:
    Start_Screen *startScene;
    ChooseCharacter_Screen *chooseCharacterScene;
public:
    Start_Screen *getStartScene(){return startScene();}

    void setStartscreen(Start_Screen start) {startScene = start;}
};

#endif //GBA_SPRITE_ENGINE_PROJECT_GAME_H
