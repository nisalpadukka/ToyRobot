//
// Created by Nisal Padukka on 2022-08-02.
//

#include "InputParserValidTestBase.h"

using namespace toyrobottest;

void InputParserValidTestBase::placeRobot(const int& x, const int& y, const int& angle){
    auto placeCommand = make_unique<PlaceCommand>(m_robot, m_surface,
                                                  getAttribute(x, y), getAttribute(Axis::Z, angle));
    placeCommand->execute();
}

void InputParserValidTestBase::validatePlacement(const int& x, const int& y, const int& angle) const{
    EXPECT_EQ(x, m_robot->getCoordinate(toyrobot::orientation::Axis::X));
    EXPECT_EQ(y, m_robot->getCoordinate(toyrobot::orientation::Axis::Y));
    EXPECT_EQ(angle, m_robot->getRotation(toyrobot::orientation::Axis::Z));
}

