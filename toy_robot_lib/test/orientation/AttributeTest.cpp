//
// Created by Nisal Padukka on 2022-08-02.
//

//
// Created by Nisal Padukka on 2022-08-03.
//

#include <gtest/gtest.h>
#include "../TestUtils.h"
#include "orientation/Attribute.h"

using namespace toyrobot::orientation;

namespace toyrobottest{

    TEST(AttributeTest, testParams){
        Attribute<int> coordinates;
        EXPECT_THROW_WITH_MESSAGE(coordinates.getValue(Axis::X), invalid_argument, "Axis 0 was not set, start with PLACE command");
        EXPECT_THROW_WITH_MESSAGE(coordinates.getValue(Axis::Y), invalid_argument, "Axis 1 was not set, start with PLACE command");
        EXPECT_THROW_WITH_MESSAGE(coordinates.getValue(Axis::Z), invalid_argument, "Axis 2 was not set, start with PLACE command");
        coordinates.setValue(Axis::X, 4);
        coordinates.setValue(Axis::Y, 5);
        coordinates.setValue(Axis::Z, 6);
        EXPECT_EQ(coordinates.getValue(Axis::X), 4);
        EXPECT_EQ(coordinates.getValue(Axis::Y), 5);
        EXPECT_EQ(coordinates.getValue(Axis::Z), 6);
    }
}

