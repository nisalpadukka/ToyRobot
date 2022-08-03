//
// Created by Nisal Padukka on 2022-07-30.
//

#include "TableTop.h"
#include "TableTopValidator.h"

using namespace toyrobot::surface;

bool TableTop::isInsideSurface(const Attribute<int>& coordinates) const{
    return  TableTopValidator::validate(coordinates);
}
