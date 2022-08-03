//
// Created by Nisal Padukka on 2022-08-02.
//

#include "InputParserValidTestBase.h"
#include "command/PlaceCommand.h"

using namespace std;

namespace toyrobottest{

    class InputParserPlaceCommand : public InputParserValidTestBase{};

    INSTANTIATE_TEST_SUITE_P(
            validPlaceCommands,
            InputParserPlaceCommand,
            ::testing::Values(
                    ValidInput("PLACE 1,2,NORTH", 1, 2, 0),
                    ValidInput("PLACE 1,2,EAST", 1, 2, 90),
                    ValidInput("PLACE 1,2,SOUTH", 1, 2, 180),
                    ValidInput("PLACE 1,2,WEST", 1, 2, 270)
            ));

    //Test suite with valid test cases base class, this test class will be extended for new commands
    TEST_P(InputParserPlaceCommand, validPlaceCommand) {
        auto command = m_inputParser->parse(GetParam().m_input, m_robot, m_surface);
        command->execute();
        InputParserValidTestBase::validatePlacement(GetParam().m_coordinateX, GetParam().m_coordinateY, GetParam().m_rotationZ);
    }

    class InputParserMoveCommand : public InputParserValidTestBase{};

    INSTANTIATE_TEST_SUITE_P(
            validMoveCommand,
            InputParserMoveCommand,
            ::testing::Values(
                    ValidInput("MOVE", 2, 2, 90),
                    ValidInput(" MOVE ", 2, 2, 90),
                    ValidInput(" MOVE", 2, 2, 90),
                    ValidInput("MOVE ", 2, 2, 90)
            ));

    TEST_P(InputParserMoveCommand, validMoveCommand) {
        InputParserValidTestBase::placeRobot(1, 2, 90);
        auto moveCommand = m_inputParser->parse(GetParam().m_input, m_robot, m_surface);
        moveCommand->execute();
        InputParserValidTestBase::validatePlacement(GetParam().m_coordinateX, GetParam().m_coordinateY, GetParam().m_rotationZ);
    }

    class InputParserRotateCommand : public InputParserValidTestBase{};

    INSTANTIATE_TEST_SUITE_P(
            validRotateCommand,
            InputParserRotateCommand,
            ::testing::Values(
                    ValidInput("LEFT", 1, 2, 0),
                    ValidInput("RIGHT", 1, 2, 180)
            ));

    TEST_P(InputParserRotateCommand, validRotateCommand) {
        InputParserValidTestBase::placeRobot(1, 2, 90);
        auto rotateCommand = m_inputParser->parse(GetParam().m_input, m_robot, m_surface);
        rotateCommand->execute();
        InputParserValidTestBase::validatePlacement(GetParam().m_coordinateX, GetParam().m_coordinateY, GetParam().m_rotationZ);
    }

    TEST_F(InputParserValidTestBase, validReportCommand) {
        placeRobot(1, 2, 90);
        auto reportCommand = m_inputParser->parse("REPORT", m_robot, m_surface);
        testing::internal::CaptureStdout();
        reportCommand->execute();
        std::string output = testing::internal::GetCapturedStdout();
        validatePlacement(1, 2, 90);
        EXPECT_EQ("1,2,EAST\n", output);
    }
}
