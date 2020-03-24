//
// Created by michi on 23/03/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BOARDSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_BOARDSCREEN_H


#include <libgba-sprite-engine/scene.h>

class boardScreen : public Scene {
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    boardScreen(std::shared_ptr<GBAEngine> engine) : Scene(engine) {};
    //MainMenuScreenScreen(){};


    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_BOARDSCREEN_H
