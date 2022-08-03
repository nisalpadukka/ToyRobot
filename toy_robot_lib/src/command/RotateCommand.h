//
// Created by Nisal Padukka on 2022-07-26.
//

#pragma once

#include "command/Command.h"
#include "robot/Robot.h"

using namespace std;
using namespace toyrobot::robot;
using namespace toyrobot::orientation;

namespace toyrobot {
    namespace command {
        class RotateCommand : public Command {
        private:
            unique_ptr<Robot>& m_robot;
            Attribute<int> m_rotation;
        public:
            explicit RotateCommand(unique_ptr<Robot>& robot, const Attribute<int> &rotation);
            void execute() override;
        };
    }
}
