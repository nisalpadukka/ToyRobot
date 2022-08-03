//
// Created by Nisal Padukka on 2022-07-26.
//

#include <memory>
#include <fstream>
#include <sstream>

#include "robot/Robot.h"
#include "surface/TableTop.h"
#include "command/Command.h"
#include "parser/InputParser.h"

constexpr const char* INPUT_FILE_PATH = "../../../inputs/inputs.txt";

int main(){

    unique_ptr<toyrobot::robot::Robot> robot =  std::make_unique<toyrobot::robot::Robot>();
    unique_ptr<toyrobot::surface::Surface> tableTop = std::make_unique<toyrobot::surface::TableTop>();
    ifstream infile(INPUT_FILE_PATH);
    string input;

    while (std::getline(infile, input)){
        unique_ptr<Command> command;
        try{
            command = toyrobot::parser::InputParser::parse(input, robot, tableTop);
            if (command == nullptr){
                cout << "Exiting ...";
                break;
            }
            command->execute();
        }
        catch (std::exception& e){
            std::cout << "Error: " <<e.what() << endl;
        }
    }

    return 0;
}
