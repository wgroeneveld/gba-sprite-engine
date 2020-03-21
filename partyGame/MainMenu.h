//
// Created by michi on 21/03/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MAINMENU_H
#define GBA_SPRITE_ENGINE_PROJECT_MAINMENU_H


#include <libgba-sprite-engine/scene.h>

class MainMenu : public Scene {

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    MainMenu(std::shared_ptr<GBAEngine> engine) : Scene(engine) {};
    ~MainMenu(){};


    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MAINMENU_H
