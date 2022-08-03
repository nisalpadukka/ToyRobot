//
// Created by Nisal Padukka on 2022-07-30.
//

#pragma once
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

namespace toyrobot {
    namespace orientation {

        enum Axis{
            X,
            Y,
            Z
        };

        // Template class holding axis based data
        template <class T>
        class Attribute {
        private:
            map<Axis, T> m_values;
        public:
            void setValue(Axis axis, T angle){
                auto it = m_values.find(axis);
                if (it != m_values.end()) {
                    it->second = angle;
                    return;
                }
                m_values.insert({axis, angle});
            }

            T getValue(Axis axis) const{
                auto it = m_values.find(axis);
                if (it == m_values.end()){
                    throw invalid_argument("Axis " + to_string(axis) + " was not set, start with PLACE command");
                }
                return it->second;
            }
        };
    }
}
