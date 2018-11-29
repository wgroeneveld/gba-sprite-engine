//
// Created by Wouter Groeneveld on 29/11/18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SPLASHSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_SPLASHSCREEN_H


#include <libgba-sprite-engine/scene.h>

class SplashScreen : public Scene {
private:
    std::unique_ptr<Background> bg;

public:
    SplashScreen(const std::shared_ptr<GBAEngine> &engine);

    std::vector<Sprite *> sprites() override;

    std::vector<Background *> backgrounds() override;

    void load() override;

    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SPLASHSCREEN_H
