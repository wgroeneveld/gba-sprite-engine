//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
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
    SomeScene() : Scene(nullptr) { };
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

TEST_F(SceneSuite, GetSpritesReturnsPointersOfBuiltSprites) {
    SomeScene scene;
    scene.load();

    auto sprites = scene.sprites();
    ASSERT_EQ(2, sprites.size());
    ASSERT_EQ(1, sprites.at(0)->getX());
    ASSERT_EQ(2, sprites.at(1)->getX());
}
