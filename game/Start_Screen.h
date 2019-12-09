//
// Created by Erwin on 20/11/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_START_SCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_START_SCREEN_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>

class Start_Screen : public Scene {
private:
    bool upPressed = false;
    bool downPressed = false;
    bool startPressed = false;
    int charachterChosen = 1;
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    StartScreen(std::shared_ptr<GBAEngine> gameEngine, int charachter) : Scene(gameEngine), charachterChosen(charachter);

    void load_screen();
};
#endif //GBA_SPRITE_ENGINE_PROJECT_START_SCREEN_H
