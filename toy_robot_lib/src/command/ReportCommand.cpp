//
// Created by Nisal Padukka on 2022-07-30.
//

#include "ReportCommand.h"
#include "utils/AngleMapperUtils.h"

using namespace toyrobot::utils;
using namespace toyrobot::command;

ReportCommand::ReportCommand(const unique_ptr<Robot> &robot): m_robot(robot){
}
void ReportCommand::execute() {
    cout << m_robot->getCoordinate(Axis::X) << "," << m_robot->getCoordinate(Axis::Y) << ","
         << AngleMapperUtils::getFacing(m_robot->getRotation(Axis::Z)) << endl;
}


