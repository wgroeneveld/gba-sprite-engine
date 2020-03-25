//
// Created by michi on 21/03/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MAINMENUSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_MAINMENUSCREEN_H


#include <libgba-sprite-engine/scene.h>

class MainMenuScreen : public Scene {

private:
    std::unique_ptr<Sprite> minion;
    std::unique_ptr<Background> background;
    void updateSelect();

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    MainMenuScreen(std::shared_ptr<GBAEngine> engine) : Scene(engine) {};
    //~MainMenuScreen(){};


    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MAINMENUSCREEN_H
