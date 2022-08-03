//
// Created by Nisal Padukka on 2022-07-30.
//

#pragma once
#include <string>
#include "command/Command.h"

using namespace toyrobot::command;

namespace toyrobot {
    namespace parser {
        class InputParser {
        public:
            static unique_ptr<Command>
            parse(const string &input, unique_ptr<Robot> &robot, unique_ptr<Surface> &surface);
        };
    }
}
