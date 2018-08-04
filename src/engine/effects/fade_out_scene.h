//
// Created by Wouter Groeneveld on 04/08/18.
//

#ifndef GBA_SPRITE_ENGINE_FADE_OUT_SCENE_H
#define GBA_SPRITE_ENGINE_FADE_OUT_SCENE_H


#include <engine/Scene.h>
#include "scene_effect.h"

class FadeOutScene : public SceneEffect {
private:
    int timesUpdated;
    int speed;

public:
    FadeOutScene(int speed) : timesUpdated(0), speed(speed) {}
    void update() override;
    bool isDone() override { return timesUpdated >= (32 / speed); }

};


#endif //GBA_SPRITE_ENGINE_FADE_OUT_SCENE_H
