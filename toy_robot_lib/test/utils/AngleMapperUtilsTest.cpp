//
// Created by Nisal Padukka on 2022-08-02.
//

#include "gtest/gtest.h"
#include "utils/AngleMapperUtils.h"
#include "../TestUtils.h"

using namespace std;

namespace toyrobottest{

    class AngleMapperUtilsTest360 : public testing::TestWithParam<pair<int, int>> {};

    INSTANTIATE_TEST_SUITE_P(
            getAngleIn360,
            AngleMapperUtilsTest360,
            ::testing::Values(
                    make_pair(0, 0),
                    make_pair(90, 90),
                    make_pair(180, 180),
                    make_pair(270, 270),
                    make_pair(360, 0),
                    make_pair(-90, 270),
                    make_pair(-180, 180),
                    make_pair(-270, 90),
                    make_pair(-360, 0),
                    make_pair(100, 100),
                    make_pair(730, 10),
                    make_pair(-100, 260),
                    make_pair(-730, 350)
            ));

    TEST_P(AngleMapperUtilsTest360, getAngleIn360){
        EXPECT_EQ(toyrobot::utils::AngleMapperUtils::getAngleIn360(GetParam().first), GetParam().second);
    }

    class AngleMapperUtilsTestGetFacing : public testing::TestWithParam<pair<int, string>> {};
    INSTANTIATE_TEST_SUITE_P(
            getFacing,
            AngleMapperUtilsTestGetFacing,
            ::testing::Values(
                    make_pair(0, "NORTH"),
                    make_pair(90, "EAST"),
                    make_pair(180, "SOUTH"),
                    make_pair(270, "WEST"),
                    make_pair(360, "NORTH"),
                    make_pair(450, "EAST"),
                    make_pair(540, "SOUTH"),
                    make_pair(720, "NORTH"),
                    make_pair(0, "NORTH"),
                    make_pair(-90, "WEST"),
                    make_pair(-180, "SOUTH"),
                    make_pair(-270, "EAST"),
                    make_pair(-360, "NORTH"),
                    make_pair(-450, "WEST"),
                    make_pair(-540, "SOUTH"),
                    make_pair(-720, "NORTH")

            ));
    TEST_P(AngleMapperUtilsTestGetFacing, getFacing){
        EXPECT_EQ(toyrobot::utils::AngleMapperUtils::getFacing(GetParam().first), GetParam().second);
    }

    class AngleMapperUtilsTestGetAngle : public testing::TestWithParam<pair<string, int>> {};
    INSTANTIATE_TEST_SUITE_P(
            getAngle,
            AngleMapperUtilsTestGetAngle,
            ::testing::Values(
                    make_pair( "NORTH", 0),
                    make_pair("EAST", 90),
                    make_pair("SOUTH", 180),
                    make_pair("WEST", 270)
            ));

    TEST_P(AngleMapperUtilsTestGetAngle, getFacing){
        EXPECT_EQ(toyrobot::utils::AngleMapperUtils::getAngleValue(GetParam().first), GetParam().second);
    }

    TEST(AngleMapperUtilsTest, getFacingInvalid){
        EXPECT_THROW_WITH_MESSAGE(toyrobot::utils::AngleMapperUtils::getAngleValue("Invalid"), invalid_argument,
                                  "Unknown facing received Invalid");
    }

}





