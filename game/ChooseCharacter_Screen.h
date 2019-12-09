//
// Created by Erwin on 28/11/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_CHOOSECHARACHTER_SCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_CHOOSECHARACHTER_SCREEN_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>

#define charBen 1
#define charErwin 2
#define charStefan 3
#define charWeapon 4

/** Waardes nog aan te passen */
#define CHARPTR_X 10
#define CHARPTR_Y 10
#define CHARBEN_X 10
#define CHARBEN_Y 10
#define CHARERWIN_X 10
#define CHARERWIN_Y 10
#define CHARSTEFAN_X 10
#define CHARSTEFAN_Y 10

class ChooseCharacter_Screen : public Scene {
private:
    std::unique_ptr<Sprite> character_ptr;
    std::unique_ptr<Sprite> character_Ben;
    std::unique_ptr<Sprite> character_Erwin;
    std::unique_ptr<Sprite> character_Stefan;
    std::unique_ptr<Sprite> character_Weapon;

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
    //1:Ben (default character), 2:Erwin, 3:Stefan
    int chosen_ = 1;
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    ChooseCharacterScene(std::shared_ptr<GBAEngine> engine) : Scene(engine){}

    void load() override;
    void createSpriteObjects();
}
#endif //GBA_SPRITE_ENGINE_PROJECT_CHOOSECHARACHTER_SCREEN_H
