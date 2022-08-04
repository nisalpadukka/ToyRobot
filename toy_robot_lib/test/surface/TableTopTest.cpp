//
// Created by Nisal Padukka on 2022-08-02.
//

#include "gtest/gtest.h"
#include "surface/TableTop.h"
#include "../TestUtils.h"

namespace toyrobottest {

    struct TestParam{
        TestParam(Attribute<int> coordinate, bool isInside): m_coordinate(coordinate), m_isInside(isInside){};
        Attribute<int> m_coordinate;
        bool m_isInside;
    };
    class TableTopTest : public testing::TestWithParam<TestParam>{
    protected:
        unique_ptr<toyrobot::surface::Surface> m_tableTop = make_unique<toyrobot::surface::TableTop>();
    };

    INSTANTIATE_TEST_SUITE_P(
            coordinate,
            TableTopTest,
            ::testing::Values(
                    TestParam(getAttribute(-1, 2), false),
                    TestParam(getAttribute(1, 2), true),
                    TestParam(getAttribute(1, 5), true),
                    TestParam(getAttribute(6, 5), false),
                    TestParam(getAttribute(0, 0), true),
                    TestParam(getAttribute(0, -1), false)
            ));

    TEST_P(TableTopTest, isInsideTable) {
        EXPECT_EQ(m_tableTop->isInsideSurface(GetParam().m_coordinate), GetParam().m_isInside);
    }
}