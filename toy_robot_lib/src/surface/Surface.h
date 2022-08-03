//
// Created by Nisal Padukka on 2022-07-30.
//

#pragma once

#include "orientation/Attribute.h"

using namespace toyrobot::orientation;

namespace toyrobot {
    namespace surface {
        class Surface {
        public:
            virtual bool isInsideSurface(const Attribute<int>& coordinates) const = 0;
            virtual ~Surface()= default;;
        };
    }
}
