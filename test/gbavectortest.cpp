//
// Created by Wouter Groeneveld on 14/12/18.
//



#include <gtest/gtest.h>
#include <libgba-sprite-engine/gbavector.h>

class GBAVectorSuite : public ::testing::Test {
protected:
    GBAVector vector;
    VECTOR bottomHalf;

    virtual void TearDown() {
    }

    virtual void SetUp() {
        vector = GBAVector({120, 80});
        bottomHalf = { 120, 200 };
    }
};

// Angle in DEGREES for readability - converted in tonc_math_stub!
TEST_F(GBAVectorSuite, Rotate_FromBottomHalf_0_Degrees) {
    auto result = vector.rotateAsCenter(bottomHalf, 0);
    ASSERT_EQ(120, result.x);
    ASSERT_EQ(200, result.y);
}

TEST_F(GBAVectorSuite, Rotate_FromBottomHalf_90_Degrees) {
    auto result = vector.rotateAsCenter(bottomHalf, 90);
    ASSERT_EQ(240, result.x);
    ASSERT_EQ(80, result.y);
}

TEST_F(GBAVectorSuite, Rotate_FromBottomHalf_180_Degrees) {
    auto result = vector.rotateAsCenter(bottomHalf, 180);
    ASSERT_EQ(120, result.x);
    ASSERT_EQ(-40, result.y);
}

TEST_F(GBAVectorSuite, Rotate_FromBottomHalf_270_Degrees) {
    auto result = vector.rotateAsCenter(bottomHalf, 270);
    ASSERT_EQ(0, result.x);
    ASSERT_EQ(80, result.y);
}
// ---- //

TEST_F(GBAVectorSuite, ToString) {
    ASSERT_EQ(std::string("(120,80)"), vector.to_string());
}

TEST_F(GBAVectorSuite, LineBetween_Diagonal_ToTopRightCorner) {
    auto points = vector.bresenhamLineTo({240, 0});
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

TEST_F(GBAVectorSuite, LineBetween_Diagonal_ToTopLeftCorner) {
    auto points = vector.bresenhamLineTo({0, 0});
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

TEST_F(GBAVectorSuite, LineBetween_Diagonal_ToBottomLeftCorner) {
    auto points = vector.bresenhamLineTo({0, 160});
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

TEST_F(GBAVectorSuite, LineBetween_Diagonal_ToBottomRightCorner) {
    auto points = vector.bresenhamLineTo({240, 160});
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

TEST_F(GBAVectorSuite, LineBetween_Horizontal_FromCenterToHalfYZeroX) {
    auto points = vector.bresenhamLineTo({0, 80});
    ASSERT_EQ(121, points.size());
    for(int i = 0; i <= 120; i++) {
        auto &vec = points.front();
        ASSERT_EQ(80, vec.y);
        ASSERT_EQ(120 - i, vec.x);
        points.pop_front();
    }
}

TEST_F(GBAVectorSuite, LineBetween_Vertical_FromCenterToHalfXFullY) {
    auto points = vector.bresenhamLineTo({120, 160});
    ASSERT_EQ(81, points.size());
    for(int i = 0; i <= (160 - 80); i++) {
        auto &vec = points.front();
        ASSERT_EQ(120, vec.x);
        ASSERT_EQ(80 + i, vec.y);
        points.pop_front();
    }
}
