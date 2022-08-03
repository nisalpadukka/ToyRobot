//
// Created by Nisal Padukka on 2022-08-02.
//

#include <gtest/gtest.h>
#include "TestUtils.h"
#include "parser/InputParser.h"
#include "robot/Robot.h"
#include "surface/TableTop.h"

using namespace std;

namespace toyrobottest{

    //InputParser test for invalid commands
    class InputParserTestInvalid : public testing::TestWithParam<pair<string, string>> {
    protected:
        unique_ptr<toyrobot::parser::InputParser> m_inputParser = make_unique<toyrobot::parser::InputParser>();
        unique_ptr<toyrobot::robot::Robot> m_robot = make_unique<toyrobot::robot::Robot>();
        unique_ptr<toyrobot::surface::Surface> m_surface = make_unique<toyrobot::surface::TableTop>();
    };

    INSTANTIATE_TEST_SUITE_P(
            invalidCommands,
            InputParserTestInvalid,
            ::testing::Values(
                    make_pair("", "Invalid command [] received."),
                    make_pair("Invalid", "Invalid command [Invalid] received."),
                    make_pair("PLACE", "PLACE command [PLACE] is invalid, expected format [PLACE x,y,FACING]"),
                    make_pair(" PLACE 1.2 NORTH", "PLACE command [PLACE 1.2 NORTH] is invalid, expected format [PLACE x,y,FACING]")
            ));

    TEST_P(InputParserTestInvalid, validPlace) {
        EXPECT_THROW_WITH_MESSAGE(m_inputParser->parse(GetParam().first, m_robot, m_surface),
                                  invalid_argument, GetParam().second);
    }
}
