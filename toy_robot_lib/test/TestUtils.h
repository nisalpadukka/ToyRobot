//
// Created by Nisal Padukka on 2022-08-02.
//

#pragma once

#include "orientation/Attribute.h"

using namespace std;

#define EXPECT_THROW_WITH_MESSAGE(statement, exception, errorMsg) \
    EXPECT_THROW( \
        try { \
            statement; \
        } catch (const exception& ex) { \
            EXPECT_EQ(std::string(ex.what()), errorMsg); \
            throw; \
        } \
    , exception)

namespace toyrobottest {
    template<typename T>
    toyrobot::orientation::Attribute <T> getAttribute(T x, T y) {
        toyrobot::orientation::Attribute<T> attribute;
        attribute.setValue(toyrobot::orientation::Axis::X, x);
        attribute.setValue(toyrobot::orientation::Axis::Y, y);
        return attribute;
    }
}

