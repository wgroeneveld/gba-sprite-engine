//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_FLYING_STUFF_SCENE_H
#define GBA_SPRITE_ENGINE_FLYING_STUFF_SCENE_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/background/background.h>

class FlyingStuffScene : public Scene {
private:
    std::unique_ptr<Sprite> smiley;
    std::unique_ptr<AffineSprite> player;
    std::unique_ptr<Sprite> kul;
    std::unique_ptr<AffineSprite> kulFlying;
    std::unique_ptr<Background> bg;

    int scrollX, scrollY;
    int rotation;
    int rotationDiff = 128;
public:
    FlyingStuffScene(std::shared_ptr<GBAEngine> engine) : Scene(engine), rotation(0), rotationDiff(128), scrollX(0), scrollY(0) {}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 i) override;
};


#endif //GBA_SPRITE_ENGINE_FLYING_STUFF_SCENE_H
