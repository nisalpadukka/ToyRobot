//
// Created by Nisal Padukka on 2022-07-25.
//

#pragma once


namespace toyrobot {
    namespace command {
        class Command {
        public:
            virtual void execute() = 0;
            virtual ~Command()= default;;
        };
    }
}