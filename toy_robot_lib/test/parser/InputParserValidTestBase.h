//
// Created by Nisal Padukka on 2022-08-02.
//

#include <gtest/gtest.h>

#include <utility>
#include "../TestUtils.h"
#include "parser/InputParser.h"
#include "robot/Robot.h"
#include "surface/TableTop.h"
#include "command/PlaceCommand.h"

#pragma once

using namespace std;

namespace toyrobottest{

    //data structure for valid test case
    struct ValidInput{
        string m_input;
        int m_coordinateX;
        int m_coordinateY;
        int m_rotationZ;
        ValidInput(string input, int coordinateX, int coordinateY, int rotationZ) :
                m_input(std::move(input)), m_coordinateX(coordinateX), m_coordinateY(coordinateY), m_rotationZ(rotationZ) {}
    };

    //Test suite for valid test cases base class, this test class can be extended for other commands
    class InputParserValidTestBase : public testing::TestWithParam<ValidInput> {
    protected:
        unique_ptr<toyrobot::robot::Robot> m_robot = make_unique<toyrobot::robot::Robot>();
        unique_ptr<toyrobot::surface::Surface> m_surface = make_unique<toyrobot::surface::TableTop>();
        unique_ptr<toyrobot::parser::InputParser> m_inputParser = make_unique<toyrobot::parser::InputParser>();

        void placeRobot(const int& x, const int& y, const int& angle);
        void validatePlacement(const int& x, const int& y, const int& angle);
    };
}
