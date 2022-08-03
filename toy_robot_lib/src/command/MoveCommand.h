//
// Created by Nisal Padukka on 2022-07-26.
//

#pragma once

#include <string>
#include <iostream>
#include "command/Command.h"
#include "robot/Robot.h"
#include <memory>

using namespace std;
using namespace toyrobot::robot;

namespace toyrobot {
    namespace command {
        class MoveCommand : public Command {
        private:
            unique_ptr<Robot>& m_robot;
            unique_ptr<Surface>& m_surface;
            int m_distance;
        public:
            MoveCommand(unique_ptr<Robot>& robot, unique_ptr<Surface>& surface, const int& distance);
            void execute() override;
        };
    }
}
