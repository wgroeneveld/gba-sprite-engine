#ifndef GBA_SPRITE_ENGINE_PROJECT_START_SCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_START_SCENE_H

#include <libgba-sprite-engine/scene.h>

class Scene_Start: public Scene {
private:
    std::unique_ptr<Background> background;
public:
    ///CONSTRUCTOR
    Scene_Start(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    ///GETTERS
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    ///OTHERS
    void load() override;
    void tick(u16 keys) override;
};

#endif
