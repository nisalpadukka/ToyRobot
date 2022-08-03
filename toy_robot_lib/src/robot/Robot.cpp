//
// Created by Nisal Padukka on 2022-07-31.
//
#include "Robot.h"

using namespace toyrobot::robot;

int Robot::getCoordinate(Axis axis) const{
    return m_coordinates.getValue(axis);
}

int Robot::getRotation(Axis axis) const{
    return  m_rotations.getValue(axis);
}

void Robot::setCoordinate(Axis axis, int value) {
    m_coordinates.setValue(axis, value);
}

void Robot::setRotation(Axis axis, int value){
    m_rotations.setValue(axis, value);
}



