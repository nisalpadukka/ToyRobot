//
// Created by Nisal Padukka on 2022-07-31.
//

#include "TableTopValidator.h"

using namespace toyrobot;
using namespace toyrobot::surface;

namespace {
    constexpr const int tableTopWidth = 5;
    constexpr const int tableTopHeight = 5;
}

bool TableTopValidator::validate(const Attribute<int> &coordinates) {
    auto x = coordinates.getValue(Axis::X);
    auto y = coordinates.getValue(Axis::Y);
    return ((0 <= x) && (x < tableTopWidth) && (0 <= y) && (y < tableTopHeight));
}
