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
        class PlaceCommand : public Command {
        private:
            unique_ptr<Robot>& m_robot;
            unique_ptr<Surface>& m_surface;
            Attribute<int> m_coordinates;
            Attribute<int> m_rotation;
        public:
            PlaceCommand(unique_ptr<Robot>& robot, unique_ptr<Surface>& surface, const Attribute<int>& coordinates,
                         const Attribute<int>& rotation);
            void execute() override;
        };
    }
}
