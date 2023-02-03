#include "Time.h"


int main() {  // time class test
    cout << "***test constructor***" << endl;
    Time time0{};
    Time time1(5, 0);
    Time time2(15, 2);

    cout << time0.toString() << endl;
    cout << time1.toString() << endl;
    cout << time2.toString() << endl;

    cout << Time::elapsedMin(time0, time1) << endl;
    cout << Time::elapsedMin(time1, time2) << endl;
    cout << Time::elapsedMin(time2, time0) << endl;

    return 0;
}