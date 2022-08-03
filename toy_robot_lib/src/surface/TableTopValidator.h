//
// Created by Nisal Padukka on 2022-07-30.
//

#pragma once

#include "Surface.h"

namespace toyrobot {
    namespace surface {
        class TableTopValidator{
        public:
            static bool validate(const Attribute<int> &coordinates);
        };
    }
}

