//
// Created by Wouter Groeneveld on 04/08/18.
//

#include <libgba-sprite-engine/palette/palette_manager.h>
#include "gtest/gtest.h"

class SomePaletteManager : public PaletteManager {
public:
    PALBANK* palette;
    SomePaletteManager() : SomePaletteManager({}) {};
    SomePaletteManager(const u16 *paletteData) : PaletteManager(paletteData) {
        palette = (PALBANK*) malloc(sizeof(PALBANK) * 16);
    }

    virtual ~SomePaletteManager() {
        delete palette;
    }

protected:
    PALBANK *paletteBank() override {
        return palette;
    }

    void *paletteAddress() override {
        return nullptr;
    }
};

class PaletteSuite : public ::testing::Test {
protected:
    SomePaletteManager* palette;

    virtual void TearDown() {
        delete palette;
    }

    virtual void SetUp() {
        palette = new SomePaletteManager();
    }
};

TEST_F(PaletteSuite, Increase_Intensity_Updates_For_RGB_Values) {
    palette->palette[0][0] = PaletteManager::color(10, 10, 10);
    palette->palette[1][1] = PaletteManager::color(11, 11, 11);
    palette->palette[2][2] = PaletteManager::color(12, 12, 12);

    palette->increaseBrightness(1);

    ASSERT_EQ(11, PaletteManager::red(palette->palette[0][0]));
    ASSERT_EQ(11, PaletteManager::green(palette->palette[0][0]));
    ASSERT_EQ(11, PaletteManager::blue(palette->palette[0][0]));

    ASSERT_EQ(12, PaletteManager::red(palette->palette[1][1]));
    ASSERT_EQ(12, PaletteManager::green(palette->palette[1][1]));
    ASSERT_EQ(12, PaletteManager::blue(palette->palette[1][1]));

    ASSERT_EQ(13, PaletteManager::red(palette->palette[2][2]));
    ASSERT_EQ(13, PaletteManager::green(palette->palette[2][2]));
    ASSERT_EQ(13, PaletteManager::blue(palette->palette[2][2]));
}

TEST_F(PaletteSuite, Extract_Individual_Colors) {
    auto color = PaletteManager::color(10, 20, 30);

    ASSERT_EQ(10, PaletteManager::red(color));
    ASSERT_EQ(20, PaletteManager::green(color));
    ASSERT_EQ(30, PaletteManager::blue(color));
}
