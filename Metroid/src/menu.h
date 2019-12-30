//
// Created by kyles on 27/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MENU_H
#define GBA_SPRITE_ENGINE_PROJECT_MENU_H

#include <libgba-sprite-engine/scene.h>
#include "Metroid.h"

class Menu : public Scene {
private:
    std::unique_ptr<Sprite> metroidBewegen;
    std::unique_ptr<Sprite> ball_projectiel;
    std::unique_ptr<Sprite> enemy;
    std::unique_ptr<Sprite> projectiel;
    std::unique_ptr<Metroid> metroidObject;
    std::unique_ptr<Background> bg;
    std::unique_ptr<Background> bg2;


public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;


    Menu(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;

};

#endif //GBA_SPRITE_ENGINE_PROJECT_MENU_H
