#ifndef PIZZATRACKING_TIME_H
#define PIZZATRACKING_TIME_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Time {
private:
    int hour{};
    int min{};

public:
    // default constructor
    // pre: none
    // post: creates a time with default values for data members.
    Time() = default;

    // param constructor
    // pre: hour in the range from 0-23, minute in the range from 0-59
    // post: creates a "correct" time with the given hour and minute
    Time(int hour, int min) throw(logic_error);

    // pre: none
    // post: returns the difference in minutes between t1 and t2
    static int elapsedMin(Time t1, Time t2);

    // pre: none
    // post: returns a string containing the hour and minute
    string toString() const;
};

#endif //PIZZATRACKING_TIME_H