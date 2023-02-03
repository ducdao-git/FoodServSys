#include "Time.h"


Time::Time(int hour, int min) throw(logic_error) {
    if ((hour < 0) || (hour > 23) || (min < 0) || (min > 59))
        throw (logic_error("Invalid time"));
    else {
        this->hour = hour;
        this->min = min;
    }
}


int Time::elapsedMin(Time t1, Time t2) {
    int min_diff, hour_diff;

    if (t2.min - t1.min < 0)
        min_diff = 60 + t2.min - t1.min;
    else
        min_diff = t2.min - t1.min;

    if (t2.hour - t1.hour < 0)
        hour_diff = 24 + t2.hour - t1.hour;
    else
        hour_diff = t2.hour - t1.hour;

    return 60 * hour_diff + min_diff;
}


string Time::toString() const {
    string hour_str = to_string(hour);
    string min_str = to_string(min);

    if (hour < 10)
        hour_str = "0" + hour_str;

    if (min < 10)
        min_str = "0" + min_str;

    return hour_str + ":" + min_str;
}

//int Time::num_converter(char ch) throw(logic_error) {
//    int num = ch - '0';
//
//    if (num < 0 || num > 9)
//        throw (logic_error("Invalid time"));
//
//    return num;
//}

//Time::Time(string time_string) throw(logic_error) {
//    if (time_string.length() != 5) {
//        throw (logic_error("Invalid time. Please input your time in the format hour:minute "));
//    } else if (time_string[2] != ':') {
//        throw (logic_error("Invalid time. Please input your time in the format hour:minute"));
//    }
//    int input_hour = num_converter(time_string[0]) * 10 + time_string[1];
//    int input_min = num_converter(time_string[3]) * 10 + time_string[4];
//    if ((input_hour < 0) || (input_hour > 23) || (input_min < 0) || (input_min > 59)) {
//        throw ("Invalid time");
//    } else {
//        hour = input_hour;
//        min = input_min;
//    }
//}