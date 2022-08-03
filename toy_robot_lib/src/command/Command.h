//
// Created by Nisal Padukka on 2022-07-25.
//

#pragma once

#include "../robot/Robot.h"

using namespace toyrobot::robot;

namespace toyrobot {
    namespace command {
        class Command {
        public:
            virtual void execute() = 0;
            virtual ~Command()= default;;
        };
    }
}