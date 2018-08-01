
#include "gtest/gtest.h"

class GBASuite : public ::testing::Test {
protected:
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }
};

TEST_F(GBASuite, AssertionWorks) {
    ASSERT_TRUE(true);
}
