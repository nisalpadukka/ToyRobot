//
// Created by Nisal Padukka on 2022-07-30.
//

#include "PlaceCommand.h"
#include "utils/AngleMapperUtils.h"
#include <stdexcept>

using namespace std;
using namespace toyrobot::command;

PlaceCommand::PlaceCommand(unique_ptr<Robot>& robot, unique_ptr<Surface>& surface,
                           const Attribute<int>& coordinates, const Attribute<int>& rotation):
m_robot(robot), m_surface(surface), m_coordinates(coordinates), m_rotation(rotation) {

}

void PlaceCommand::execute() {
    auto copyCoordinate = [this](Axis axis){
        m_robot->setCoordinate(axis, m_coordinates.getValue(axis));
    };
    if (!m_surface->isInsideSurface(m_coordinates)){
        throw invalid_argument("Place command should be within surface");
    }
    copyCoordinate(Axis::X);
    copyCoordinate(Axis::Y);
    m_robot->setRotation(Axis::Z, m_rotation.getValue(Axis::Z));
}


