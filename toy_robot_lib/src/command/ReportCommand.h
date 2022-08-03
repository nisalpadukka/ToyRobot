//
// Created by Nisal Padukka on 2022-07-26.
//

#pragma once

#include "command/Command.h"
#include "robot/Robot.h"
#include <memory>

using namespace std;
using namespace toyrobot::robot;

namespace toyrobot {
    namespace command {
        class ReportCommand : public Command {
        private:
            const unique_ptr<Robot>& m_robot;
        public:
            explicit ReportCommand(unique_ptr<Robot>& robot);
            void execute() override;
        };
    }
}
