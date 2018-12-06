//
// Created by Wouter Groeneveld on 06/12/18.
//

#include <gtest/gtest.h>
#include <libgba-sprite-engine/timer.h>

class TimerSuite : public ::testing::Test {
protected:
    Timer *t;

    virtual void TearDown() {
        delete t;
    }

    virtual void SetUp() {
        t = new Timer();
    }
};


TEST_F(TimerSuite, OnVBlankIncreasesMsecsAmountOfTimeIfStarted) {
    t->start();
    t->onvblank();
    t->stop();
    t->onvblank();

    ASSERT_EQ(t->getMsecs(), 16);
}

TEST_F(TimerSuite, OnVBlankAfterEnoughTimesToGetToSec) {
    t->start();

    for(int i = 0; i < 100; i++) {
        t->onvblank();
    }

    ASSERT_EQ(t->getSecs(), 1);
    ASSERT_EQ(t->getMsecs(), 673);
}

TEST_F(TimerSuite, OnVBlankDoesNothingIfNotEnabled) {
    t->onvblank();

    ASSERT_EQ(t->getMsecs(), 0);
}