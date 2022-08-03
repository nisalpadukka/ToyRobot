//
// Created by Nisal Padukka on 2022-07-30.
//

#pragma once

#include <string>

using namespace std;

namespace toyrobot{

    enum Turn{
        LEFT,
        RIGHT
    };

    namespace utils{
        class AngleMapperUtils {
        public:
            static int getAngleValue(Turn turn);
            static int getAngleIn360(int angle);
            static string getFacing(int angle);
            static int getAngleValue(const string& facing);
        };
    }
}


