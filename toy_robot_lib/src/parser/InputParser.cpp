//
// Created by Nisal Padukka on 2022-07-30.
//

#include <regex>
#include <stdexcept>

#include "InputParser.h"
#include "command/MoveCommand.h"
#include "command/RotateCommand.h"
#include "command/ReportCommand.h"
#include "command/PlaceCommand.h"
#include "utils/AngleMapperUtils.h"

using namespace toyrobot;
using namespace toyrobot::parser;
using namespace toyrobot::command;
using namespace toyrobot::utils;
using namespace toyrobot::orientation;

//anonymous namespace
namespace{
    //command names
    constexpr const char* MOVE_COMMAND = "MOVE";
    constexpr const char* LEFT_COMMAND = "LEFT";
    constexpr const char* RIGHT_COMMAND = "RIGHT";
    constexpr const char* PLACE_COMMAND = "PLACE";
    constexpr const char* REPORT_COMMAND = "REPORT";
    constexpr const char* EXIT_COMMAND = "EXIT";

    string preprocessInputStr(const string& input); //remove leading, trailing & extra spaces
    vector<string> split(string& str); //tokenize string into vector
    string getCommandType(const string& command);
    unique_ptr<Command> getRotationCommand(unique_ptr<Robot> &robot, Turn angle);
    unique_ptr<Command> getPlaceCommand(unique_ptr<Robot> &robot, unique_ptr<Surface> &surface, const string &input);
}

unique_ptr<Command> InputParser::parse(const string& input, unique_ptr<Robot>& robot, unique_ptr<Surface>& surface){
    string preprocessedInput = preprocessInputStr(input);
    auto commandType = getCommandType(preprocessedInput);
    if (commandType == MOVE_COMMAND){
        return unique_ptr<Command>{new MoveCommand(robot, surface, 1)};
    }
    if (commandType == PLACE_COMMAND){
        return getPlaceCommand(robot, surface, preprocessedInput);
    }
    if (commandType == LEFT_COMMAND){
        return getRotationCommand(robot, Turn::LEFT);
    }
    if (commandType == RIGHT_COMMAND){
        return getRotationCommand(robot, Turn::RIGHT);
    }
    if (commandType == REPORT_COMMAND){
        return unique_ptr<Command>{new ReportCommand(robot)};
    }
    if (commandType == EXIT_COMMAND) {
        return nullptr;
    }
    throw invalid_argument("Invalid command [" + input + "] received.");
}

//anonymous namespace
namespace{
    string preprocessInputStr(const string& input){
        auto const re = regex("^ +| +$|( ) +");
        return regex_replace(input, re, "$1");;
    }

    vector<string> split(string& str){
        auto const re = regex{R"(,)"};
        return vector<string>(
                sregex_token_iterator{begin(str), end(str), re, -1},
                sregex_token_iterator{}
        );
    }

    inline string getCommandType(const string& command){
        auto pos = command.find(' ');
        if (pos == string::npos) {
            return command;
        }
        return command.substr(0, pos);
    }

    unique_ptr<Command> getRotationCommand(unique_ptr<Robot> &robot, Turn angle){
        Attribute<int> rotation;
        rotation.setValue(Axis::Z, AngleMapperUtils::getAngleValue(angle));
        return unique_ptr<Command>{new RotateCommand(robot, rotation)};
    }

    unique_ptr<Command> getPlaceCommand(unique_ptr<Robot> &robot, unique_ptr<Surface> &surface, const string &input) {
        auto throwInvalidCommandException = [&input](){
            throw invalid_argument("PLACE command [" + input + "] is invalid, expected format [PLACE x,y,FACING]");};
        auto startOfx = input.find(' ');
        if (startOfx == string::npos) {
            throwInvalidCommandException();
        }
        string moveCmdSpecs = input.substr(startOfx, input.size());
        auto attributes = split(moveCmdSpecs);
        if (attributes.size() != 3){
            throwInvalidCommandException();
        }
        try{
            Attribute<int> coordinates;
            coordinates.setValue(Axis::X, atoi(attributes[0].c_str()));
            coordinates.setValue(Axis::Y, atoi(attributes[1].c_str()));
            Attribute<int> rotation;
            rotation.setValue(Axis::Z, AngleMapperUtils::getAngleValue(attributes[2]));
            return unique_ptr<Command>{new PlaceCommand(robot, surface, coordinates, rotation)};
        }catch (exception& e){
            throwInvalidCommandException();
        }
        return nullptr;
    }
}
