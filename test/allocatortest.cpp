//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <gtest/gtest.h>
#include <libgba-sprite-engine/allocator.h>
#include "gtest/gtest.h"
#include <iostream>
#include <libgba-sprite-engine/background/text.h>
#include "real_data.h"

using namespace std;

class AllocatorSuite : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
        Allocator::free();
    }
};

TEST_F(AllocatorSuite, Scenario_Text_And_Real_Bg_Size) {
    auto allocatedText = Allocator::allocateObjectTiles(sizeof(text_data));
    auto allocatedBg = Allocator::allocateObjectTiles(sizeof(background_data));

    ASSERT_EQ(0, allocatedText.getTileLocation());
    ASSERT_EQ(192, allocatedBg.getTileLocation());
}

TEST_F(AllocatorSuite, GetAllocatedSizeDefaultZero) {
    ASSERT_EQ(0, Allocator::getAllocatedSprites());
}

TEST_F(AllocatorSuite, Allocate_Increases_Allocated_Size_By_One) {
    Allocator::allocateObjectTiles(10);
    ASSERT_EQ(1, Allocator::getAllocatedSprites());
}

TEST_F(AllocatorSuite, Free_Resets_Current_Ptr) {
    u32 ptr1 = Allocator::getCurrentSpriteIndex();
    auto allocated1 = Allocator::allocateObjectTiles(10);
    auto allocated2 = Allocator::allocateObjectTiles(3395 * 8);
    Allocator::free();
    u32 ptr2 = Allocator::getCurrentSpriteIndex();

    ASSERT_EQ(ptr1, ptr2);
}

TEST_F(AllocatorSuite, Allocate_Both_Different_Ptr) {
    u32 ptr1 = Allocator::getCurrentSpriteIndex();
    auto allocated1 = Allocator::allocateObjectTiles(10);
    auto allocated2 = Allocator::allocateObjectTiles(3395 * 8);
    u32 ptr2 = Allocator::getCurrentSpriteIndex();

    ASSERT_NE(allocated1.pointer(), allocated2.pointer());
    ASSERT_NE(ptr1, ptr2);
}

TEST_F(AllocatorSuite, Allocate_Sprite_Pointers_Reservers_Some_Tile_Space) {
    auto prev = Allocator::getCurrentSpriteIndex();
    auto allocated = Allocator::allocateObjectTiles(10);
    auto curr = Allocator::getCurrentSpriteIndex();
    auto diff = curr - prev;
    auto allocated2 = Allocator::allocateObjectTiles(10);
    auto curr2 = Allocator::getCurrentSpriteIndex();
    auto diff2 = curr2 - curr;

    cout << "prev: " << prev << " - curr: " << curr << " (diff: " << diff << ")" << " and " << curr2 <<  endl;

    ASSERT_EQ(prev, allocated.currentAddress);
    ASSERT_EQ(curr, allocated2.currentAddress);
    ASSERT_EQ(10, allocated.size);
    ASSERT_EQ(10, diff);
    ASSERT_EQ(10, diff2);
    ASSERT_TRUE(curr > prev);
}

