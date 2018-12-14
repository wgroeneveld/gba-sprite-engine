//
// Created by Wouter Groeneveld on 14/12/18.
//



#include <gtest/gtest.h>
#include <libgba-sprite-engine/math.h>

class MathSuite : public ::testing::Test {
protected:

    virtual void TearDown() {
    }

    virtual void SetUp() {
    }
};

TEST_F(MathSuite, LineBetween_Diagonal_ToTopRightCorner) {
    auto points = Math::bresenhamLineBetween({120, 80}, {240, 0});
    ASSERT_EQ(121, points.size());
    VECTOR pt;

    // some sampling
    pt = points.at(1);
    ASSERT_EQ(121, pt.x);
    ASSERT_EQ(79, pt.y);
    pt = points.at(2);
    ASSERT_EQ(122, pt.x);
    ASSERT_EQ(79, pt.y);
    pt = points.at(10);
    ASSERT_EQ(130, pt.x);
    ASSERT_EQ(73, pt.y);
    pt = points.at(100);
    ASSERT_EQ(220, pt.x);
    ASSERT_EQ(13, pt.y);
}

TEST_F(MathSuite, LineBetween_Diagonal_ToTopLeftCorner) {
    auto points = Math::bresenhamLineBetween({120, 80}, {0, 0});
    ASSERT_EQ(121, points.size());
    VECTOR pt;

    // some sampling
    pt = points.at(1);
    ASSERT_EQ(119, pt.x);
    ASSERT_EQ(79, pt.y);
    pt = points.at(2);
    ASSERT_EQ(118, pt.x);
    ASSERT_EQ(79, pt.y);
    pt = points.at(10);
    ASSERT_EQ(110, pt.x);
    ASSERT_EQ(73, pt.y);
    pt = points.at(100);
    ASSERT_EQ(20, pt.x);
    ASSERT_EQ(13, pt.y);
}

TEST_F(MathSuite, LineBetween_Diagonal_ToBottomLeftCorner) {
    auto points = Math::bresenhamLineBetween({120, 80}, {0, 160});
    ASSERT_EQ(121, points.size());
    VECTOR pt;

    // some sampling
    pt = points.at(1);
    ASSERT_EQ(119, pt.x);
    ASSERT_EQ(81, pt.y);
    pt = points.at(2);
    ASSERT_EQ(118, pt.x);
    ASSERT_EQ(81, pt.y);
    pt = points.at(10);
    ASSERT_EQ(110, pt.x);
    ASSERT_EQ(87, pt.y);
    pt = points.at(100);
    ASSERT_EQ(20, pt.x);
    ASSERT_EQ(147, pt.y);
}

TEST_F(MathSuite, LineBetween_Diagonal_ToBottomRightCorner) {
    auto points = Math::bresenhamLineBetween({120, 80}, {240, 160});
    ASSERT_EQ(121, points.size());
    VECTOR pt;

    // some sampling
    pt = points.at(1);
    ASSERT_EQ(121, pt.x);
    ASSERT_EQ(81, pt.y);
    pt = points.at(2);
    ASSERT_EQ(122, pt.x);
    ASSERT_EQ(81, pt.y);
    pt = points.at(10);
    ASSERT_EQ(130, pt.x);
    ASSERT_EQ(87, pt.y);
    pt = points.at(100);
    ASSERT_EQ(220, pt.x);
    ASSERT_EQ(147, pt.y);
}

TEST_F(MathSuite, LineBetween_Horizontal_FromCenterToHalfYZeroX) {
    auto points = Math::bresenhamLineBetween({120, 80}, {0, 80});
    ASSERT_EQ(121, points.size());
    for(int i = 0; i <= 120; i++) {
        auto &vec = points.front();
        ASSERT_EQ(80, vec.y);
        ASSERT_EQ(120 - i, vec.x);
        points.pop_front();
    }
}

TEST_F(MathSuite, LineBetween_Vertical_FromCenterToHalfXFullY) {
    auto points = Math::bresenhamLineBetween({120, 80}, {120, 160});
    ASSERT_EQ(81, points.size());
    for(int i = 0; i <= (160 - 80); i++) {
        auto &vec = points.front();
        ASSERT_EQ(120, vec.x);
        ASSERT_EQ(80 + i, vec.y);
        points.pop_front();
    }
}
