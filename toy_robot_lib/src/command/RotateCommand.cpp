//
// Created by Nisal Padukka on 2022-07-26.
//

#include "RotateCommand.h"

using namespace toyrobot::command;

RotateCommand::RotateCommand(unique_ptr<Robot> &robot, const Attribute<int> &rotation): m_robot(robot), m_rotation(rotation){

}
void RotateCommand::execute() {
    m_robot->setRotation(Axis::Z,  m_robot->getRotation(Axis::Z) + m_rotation.getValue(Axis::Z));
}


