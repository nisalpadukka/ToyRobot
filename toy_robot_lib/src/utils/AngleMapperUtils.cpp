//
// Created by Nisal Padukka on 2022-07-30.
//

#include "AngleMapperUtils.h"

using namespace toyrobot::utils;

namespace {
    //facings
    constexpr const char* FACING_NORTH = "NORTH";
    constexpr const char* FACING_SOUTH = "SOUTH";
    constexpr const char* FACING_EAST = "EAST";
    constexpr const char* FACING_WEST = "WEST";
}

//Get the value of turn in degrees
int AngleMapperUtils::getAngleValue(const Turn turn){
    switch(turn){
        case Turn::LEFT:
            return -90;
        case Turn::RIGHT:
            return 90;
        default:
            throw invalid_argument("Unknown turn type received " + to_string(turn));
    }
}

//                N (0`)
//                |
//                |
// (270`) W - - - + - - -E (90`)
//                |
//                |
//              S (180`)
//Gets the value of facing in degrees
int AngleMapperUtils::getAngleValue(const string& facing){
    if (facing == FACING_NORTH) {
        return 0;
    }
    if (facing == FACING_EAST) {
        return 90;
    }
    if (facing == FACING_SOUTH) {
        return 180;
    }
    if (facing == FACING_WEST) {
        return 270;
    }
    throw invalid_argument("Unknown facing received " + facing);
}

//Gets the angle value of facing in degrees in 360` degrees
int AngleMapperUtils::getAngleIn360(int angle) {
    angle = angle % 360;
    if (angle < 0){
        return angle + 360;
    }
    return angle;
}

//Get facing from angle
string AngleMapperUtils::getFacing(const int angle) {
    auto angleIn360 = getAngleIn360(angle);
    switch(angleIn360){
        case 0:{
            return FACING_NORTH;
        }
        case 90: {
            return FACING_EAST;
        }
        case 180: {
            return FACING_SOUTH;
        }
        case 270: {
            return FACING_WEST;
        }
        default:
            return FACING_NORTH;
    }
}

