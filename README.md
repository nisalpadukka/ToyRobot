# Toy Robot Code Challenge (C++)

## Description

* The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units.

* There are no other obstructions on the table surface.

* The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. 

* Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.

## Requirements

Create an application that can read in commands of the following form:
```
PLACE X,Y,F
MOVE
LEFT
RIGHT
REPORT
```

* `PLACE` will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST.

* The origin (0,0) can be considered to be the SOUTH WEST most corner.

* The first valid command to the robot is a `PLACE` command, after that, any sequence of commands may be issued, in any order, including another `PLACE` command. The application should discard all commands in the sequence until a valid `PLACE` command has been executed

* `MOVE` will move the toy robot one unit forward in the direction it is currently facing.

* `LEFT` and `RIGHT` will rotate the robot 90 degrees in the specified direction without changing the position of the robot.

* `REPORT` will announce the X,Y and F of the robot. This can be in any form, but standard output is sufficient.

* A robot that is not on the table can choose to ignore the `MOVE`, `LEFT`, `RIGHT` and `REPORT` commands.

* Input can be from a file, or from standard input, as the developer chooses.

* Provide test data to exercise the application.

#### Constraints

* The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot.

* Any move that would cause the robot to fall must be ignored.

### Example Input and Output:

#### Example (a)


Input:

    PLACE 0,0,NORTH
    MOVE
    REPORT

Output:

    0, 1, NORTH

#### Example (b)

Input:

    PLACE 0,0,NORTH
    LEFT
    REPORT

Output:

    0, 0, WEST

#### Example (c)

Input:

    PLACE 1,2,EAST
    MOVE
    MOVE
    LEFT
    MOVE
    REPORT

Output:

    3,3,NORTH
   

## Prerequisites

* C++14 or higher
* CMake minimum required version 3.22

## Setup

1. Clone the repository

 ```git clone https://github.com/nisalpadukka/ToyRobot.git```

 2. Create build directory

 ```cd ToyRobot && mkdir build && cd build```

 3. Build 

  ```cmake .. && make```


## Run

1. Update the command sequence in input file at 

 ```PROJECT_ROOT_DIRECTORY/inputs/inputs.txt```

 2. Execute the program

 ```cd PROJECT_ROOT_DIRECTORY/build/toy_robot_ex/src && ./ToyRobot_ex```


 ## Test

 Execute Test build 

 ```cd PROJECT_ROOT_DIRECTORY/build/toy_robot_lib/test && ./ToyRobot_test```

