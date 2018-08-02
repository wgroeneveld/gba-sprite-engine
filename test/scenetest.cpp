//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <engine/Scene.h>
#include <engine/sprites/sprite_builder.h>
#include <engine/gba_engine.h>
#include "gtest/gtest.h"

class SceneSuite : public ::testing::Test {
protected:
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }
};

class SomeScene : public Scene {
private:
    std::unique_ptr<Sprite> someSprite1;
    std::unique_ptr<Sprite> someSprite2;
public:
    void moveToNextSceneTest(Scene& next) {
        this->onNextSceneFn(next);
    }
    std::vector<Sprite *> sprites() override {
        return {
            someSprite1.get(), someSprite2.get()
        };
    }

    std::vector<Background *> backgrounds() override {
        return std::vector<Background *>();
    }

    void tick(u16 i) override {
    }

    void load() override {
        someSprite1 = SpriteBuilder<Sprite>()
                .withLocation(1, 1)
                .buildPtr();
        someSprite2 = SpriteBuilder<Sprite>()
                .withLocation(2, 2)
                .buildPtr();
    }
};

TEST_F(SceneSuite, OnGoToNextScene_Callback_Test) {
    SomeScene scene;
    bool called = false;

    auto goToNextScene = [&called](Scene& sceneFromArgs)  {
        called = true;
    };
    scene.onNextScene(goToNextScene);
    scene.moveToNextSceneTest(scene);

    ASSERT_TRUE(called);
}

TEST_F(SceneSuite, GetSpritesReturnsPointersOfBuiltSprites) {
    SomeScene scene;
    scene.load();

    auto sprites = scene.sprites();
    ASSERT_EQ(2, sprites.size());
    ASSERT_EQ(1, sprites.at(0)->getX());
    ASSERT_EQ(2, sprites.at(1)->getX());
}
