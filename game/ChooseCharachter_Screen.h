//
// Created by Erwin on 28/11/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_CHOOSECHARACHTER_SCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_CHOOSECHARACHTER_SCREEN_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>

#define char1 1
#define char2 2
#define char3 3
#define char4 4

class ChooseCharachterScreen : public Scene {
private:
    std::unique_ptr<Sprite> sp_arrow;
    std::unique_ptr<Sprite> character1;
    std::unique_ptr<Sprite> character2;
    std::unique_ptr<Sprite> character3;
    std::unique_ptr<Sprite> character4;

    bool right_pressed = false;
    bool right_mem = false;
    bool left_pressed = false;
    bool left_mem = false;
    bool up_pressed = false;
    bool up_mem = false;
    bool down_pressed = false;
    bool down_mem = false;
    bool start_pressed = false;
    bool start_mem = false;
    //1:red (default), 2:blue, 3:green, 4:purple, 5:turquoise, 6:mustard
    int chosen_ = 1;
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    ChooseCarScene(std::shared_ptr<GBAEngine> engine) : Scene(engine){}

    void load() override;
    void createSpriteObjects();
}
#endif //GBA_SPRITE_ENGINE_PROJECT_CHOOSECHARACHTER_SCREEN_H
