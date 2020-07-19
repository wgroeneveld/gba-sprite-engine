//
// Created by michi on 18/07/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_TESTSCREEN1_H
#define GBA_SPRITE_ENGINE_PROJECT_TESTSCREEN1_H
#include <libgba-sprite-engine/scene.h>
#include "../src/Test.h"

class testScreen1 : public Scene {
private:
    Test test;
    //Test *pointerTest = &test;
    Test &referenceTest = test;
    std::unique_ptr<Sprite> speler1Sprite;
    u16 lastKeys = 0;
    bool firstTick = true;
    std::unique_ptr<Background> background;


public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    testScreen1(std::shared_ptr<GBAEngine> engine) : Scene(engine) {};
    //testScreen1(std::shared_ptr<GBAEngine> engine, Test *pointerTestje) : Scene(engine) {pointerTest = pointerTestje;};
    testScreen1(std::shared_ptr<GBAEngine> engine, Test referenceTestje) : Scene(engine) {test = referenceTestje;};

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_TESTSCREEN1_H
