//
// Created by Nisal Padukka on 2022-07-26.
//

#pragma once

#include <string>
#include <iostream>
#include "../surface/Surface.h"
#include "../orientation/Attribute.h"

using namespace std;
using namespace toyrobot::orientation;
using namespace toyrobot::surface;

namespace toyrobot{
    namespace robot {
        class Robot {
        private:
            Attribute<int> m_coordinates;
            Attribute<int> m_rotations;
        public:
            int getCoordinate(Axis axis) const;
            int getRotation(Axis axis) const;
            void setCoordinate(Axis axis, int value);
            void setRotation(Axis axis, int value);
        };
    }
}
