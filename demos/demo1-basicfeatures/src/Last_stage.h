//
// Created by woute on 9/11/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_LAST_STAGE_H
#define GBA_SPRITE_ENGINE_PROJECT_LAST_STAGE_H


#include <libgba-sprite-engine/scene.h>

class Last_stage : public Scene {
private:
    std:: unique_ptr<Sprite> autootje;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    Last_stage(std::shared_ptr<GBAEngine> engine) : Scene(engine){}

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_LAST_STAGE_H
