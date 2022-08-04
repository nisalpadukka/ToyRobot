//
// Created by Nisal Padukka on 2022-08-03.
//

#include <gtest/gtest.h>
#include "../TestUtils.h"
#include "surface/TableTop.h"
#include "robot/Robot.h"
#include "command/PlaceCommand.h"
#include "command/MoveCommand.h"
#include "command/RotateCommand.h"
#include "command/ReportCommand.h"
#include "utils/AngleMapperUtils.h"
#include <memory>

using namespace toyrobot::command;

namespace toyrobottest{

    class CommandTest : public testing::Test{
    protected:
        unique_ptr <toyrobot::robot::Robot> m_robot = make_unique<toyrobot::robot::Robot>();
        unique_ptr <toyrobot::surface::Surface> m_surface = make_unique<toyrobot::surface::TableTop>();
    };

    TEST_F(CommandTest, commands){
        auto executePlaceCommand = [this](int x, int y, int angle){
            auto command = PlaceCommand(m_robot, m_surface, getAttribute<int>(x, y),
                    getAttribute<int>(toyrobot::orientation::Axis::Z, angle));
            command.execute();
        };
        auto executeMoveCommand = [this](int distance){
            auto command = MoveCommand(m_robot, m_surface, distance);
            command.execute();
        };

        auto executeRotateCommand = [this](toyrobot::Turn angle){
            auto command = RotateCommand(m_robot, getAttribute(Axis::Z,
                                                               toyrobot::utils::AngleMapperUtils::getAngleValue(angle)));
            command.execute();
        };

        auto executeReportCommand = [this](){
            auto command = ReportCommand(m_robot);
            testing::internal::CaptureStdout();
            command.execute();
            return testing::internal::GetCapturedStdout();
        };

        auto executeReportCommandEx = [this](){
            auto command = ReportCommand(m_robot);
            command.execute();
        };

        EXPECT_THROW_WITH_MESSAGE(executeMoveCommand(1), invalid_argument,
                                  "Axis 2 was not set, start with PLACE command");
        EXPECT_THROW_WITH_MESSAGE(executeReportCommandEx(), invalid_argument,
                                  "Axis 0 was not set, start with PLACE command");
        EXPECT_THROW_WITH_MESSAGE(executeRotateCommand(toyrobot::Turn::RIGHT), invalid_argument,
                                  "Axis 2 was not set, start with PLACE command");
        EXPECT_THROW_WITH_MESSAGE(executePlaceCommand(6, 4, 90), invalid_argument,
                                  "Place command should be within surface");
        executePlaceCommand(2, 4, 90);
        executeMoveCommand(1);
        EXPECT_EQ("3,4,EAST\n", executeReportCommand());
        executeMoveCommand(1);
        executeMoveCommand(1);
        EXPECT_THROW_WITH_MESSAGE(executeMoveCommand(1), invalid_argument, "Cannot move outside surface");
        EXPECT_EQ("5,4,EAST\n", executeReportCommand());
        executeRotateCommand(toyrobot::Turn::RIGHT);
        EXPECT_EQ("5,4,SOUTH\n", executeReportCommand());
        executeRotateCommand(toyrobot::Turn::RIGHT);
        EXPECT_EQ("5,4,WEST\n", executeReportCommand());
        executeMoveCommand(1);
        EXPECT_EQ("4,4,WEST\n", executeReportCommand());
        executeRotateCommand(toyrobot::Turn::RIGHT);
        EXPECT_EQ("4,4,NORTH\n", executeReportCommand());
        executeRotateCommand(toyrobot::Turn::RIGHT);
        EXPECT_EQ("4,4,EAST\n", executeReportCommand());
        executeRotateCommand(toyrobot::Turn::LEFT);
        EXPECT_EQ("4,4,NORTH\n", executeReportCommand());
        executeRotateCommand(toyrobot::Turn::LEFT);
        executeMoveCommand(1);
        EXPECT_EQ("3,4,WEST\n", executeReportCommand());
        executeRotateCommand(toyrobot::Turn::LEFT);
        EXPECT_EQ("3,4,SOUTH\n", executeReportCommand());
        executeMoveCommand(1);
        executeRotateCommand(toyrobot::Turn::LEFT);
        EXPECT_EQ("3,3,EAST\n", executeReportCommand());

    }
}

