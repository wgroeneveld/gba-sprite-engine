//
// Created by Wouter Groeneveld on 12/12/19.
//

#include <gtest/gtest.h>
#include <libgba-sprite-engine/background/background.h>

class BGTestSuite : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }
};

TEST_F(BGTestSuite, Create_Background_Can_Set_Custom_ScreenAndMapAndLayout) {
    Background bg(1, NULL, 100, NULL, 200, 15, 16, MAPLAYOUT_64X64);

    ASSERT_EQ(16, bg.getCharBlock());
    ASSERT_EQ(15, bg.getScreenBlock());
}

TEST_F(BGTestSuite, Create_Background_CharBlockIsBgIndex_ByDefault) {
    Background bg(1, NULL, 100, NULL, 200);

    ASSERT_EQ(1, bg.getCharBlock());
    ASSERT_EQ(0, bg.getScreenBlock());
}