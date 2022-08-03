//
// Created by Nisal Padukka on 2022-08-02.
//

#include "gtest/gtest.h"
#include "robot/Robot.h"

namespace toyrobottest {

    TEST(RobotTest, testParams) {
        auto robot = make_unique<toyrobot::robot::Robot>();
        robot->setRotation(toyrobot::orientation::Axis::X, 30);
        robot->setCoordinate(toyrobot::orientation::Axis::X, 60);
        EXPECT_EQ(robot->getRotation(toyrobot::orientation::Axis::X), 30);
        EXPECT_EQ(robot->getCoordinate(toyrobot::orientation::Axis::X), 60);
    }
}