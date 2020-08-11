//
// Created by michi on 22/03/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ABOUTSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_ABOUTSCREEN_H


#include <libgba-sprite-engine/scene.h>

class AboutScreen : public Scene {
private:

    std::unique_ptr<Background> background;

    std::unique_ptr<Sprite> spook1Sprite;
    std::unique_ptr<Sprite> spook2Sprite;
    std::unique_ptr<Sprite> steenRoodSprite;
    std::unique_ptr<Sprite> steenGroenSprite;
    std::unique_ptr<Sprite> steenBlauwSprite;
    std::unique_ptr<Sprite> boxSprite;
    std::unique_ptr<Sprite> pijlSprite;
    std::unique_ptr<Sprite> dobbelsteenSprite;
    std::unique_ptr<Sprite> spookGroenSprite;
    std::unique_ptr<Sprite> spookRoodSprite;
    std::unique_ptr<Sprite> spookBlauwSprite;
    std::unique_ptr<Sprite> alleKleurenSprite;






    u16 lastKeys = 0;
    bool firstTick = true;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    AboutScreen(std::shared_ptr<GBAEngine> engine) : Scene(engine) {};



    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ABOUTSCREEN_H

// moet hier ergens explicit ofzo komen? Zie vorige taak (minions vs zombies)