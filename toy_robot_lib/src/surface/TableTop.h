//
// Created by Nisal Padukka on 2022-07-30.
//

#pragma once

#include <string>
#include "Surface.h"

namespace toyrobot {
    namespace surface {
        class TableTop : public Surface {
        public:
            bool isInsideSurface(const Attribute<int>& coordinates) const override;
        };
    }
}

