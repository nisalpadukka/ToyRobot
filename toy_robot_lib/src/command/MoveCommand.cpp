//
// Created by Nisal Padukka on 2022-07-26.
//

#include "MoveCommand.h"
#include "utils/AngleMapperUtils.h"
#include <stdexcept>

using namespace std;
using namespace toyrobot::command;

MoveCommand::MoveCommand(unique_ptr<Robot>& robot, unique_ptr<Surface>& surface, const int &distance):
m_robot(robot), m_surface(surface), m_distance(distance) {

}

void MoveCommand::execute() {
    auto move = [this](const Axis axis, const int distance){
        Attribute<int> newCoordinates;
        newCoordinates.setValue(Axis::X, m_robot->getCoordinate(Axis::X));
        newCoordinates.setValue(Axis::Y, m_robot->getCoordinate(Axis::Y));
        newCoordinates.setValue(axis, newCoordinates.getValue(axis) + distance);
        if (!m_surface->isInsideSurface(newCoordinates)){
            throw invalid_argument("Cannot move outside surface");
        }
        m_robot->setCoordinate(Axis::X, newCoordinates.getValue(Axis::X));
        m_robot->setCoordinate(Axis::Y, newCoordinates.getValue(Axis::Y));
    };
    switch(m_robot->getRotation(Axis::Z)){
        case 0:{
            move(Axis::Y, m_distance);
            break;
        }
        case 90: {
            move(Axis::X, m_distance);
            break;
        }
        case 180: {
            move(Axis::Y, -m_distance);
            break;
        }
        case 270: {
            move(Axis::X, -m_distance);
            break;
        }
    }
}


