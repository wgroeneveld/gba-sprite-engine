#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_END_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_END_H

#include <libgba-sprite-engine/scene.h>

class Scene_End : public Scene {
private:
    std::unique_ptr<Background> backgroundGround;
    std::unique_ptr<Background> backgroundSea;
    std::unique_ptr<Background> backgroundSun;

    int amountEnemiesKilled;
public:
    ///CONSTRUCTOR
    Scene_End(std::shared_ptr<GBAEngine> engine,
            int amountEnemiesKilled) :
            Scene(engine),
            amountEnemiesKilled(amountEnemiesKilled) {}

    ///GETTERS
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    ///OTHERS
    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SCENE_END_H
