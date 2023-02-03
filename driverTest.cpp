#include "Driver.h"


int main() {  // driver class test
    cout << "***test default constructor***" << endl;
    Driver duc("Duc");
    cout << duc.driverSummary() << endl;

    cout << "\n***test logout***" << endl;
    duc.logout();
//    duc.logout();
    cout << "logout success" << endl;

    cout << "\n***test login***" << endl;
    duc.login();
//    duc.login();
    cout << "login success" << endl;

    // define:
    Time time1(10, 00);
    Time time2(10, 15);
    Time time3(10, 30);
    Time time4(10, 45);
    Time time5(11, 00);
    auto order1 = new Order(time1, "order 1");
    auto order2 = new Order(time1, "order 2");
    auto order3 = new Order(time1, "order 3");

    cout << "\n***test depart***" << endl;
    duc.depart(time2, order1);
//    duc.depart(time2, order2);
    cout << (order1->getOrderTime()).toString() << endl;

    cout << "\n***test depart***" << endl;
    duc.deliver(time3, 2.5);
//    duc.deliver(time3, 2.6);
    cout << (order1->getDeliveredTime()).toString() << endl;
    cout << duc.driverSummary() << endl;

    cout << "\n***test arrive***" << endl;
    duc.arrive(time4);
//    duc.arrive(time4);
    cout << duc.driverSummary() << endl;

    cout << "\n***general test***" << endl;
    duc.depart(time2, order2);
    duc.deliver(time3, 2.5);
    cout << duc.driverStatus() << endl;
    duc.arrive(time4);

    duc.depart(time2, order3);
    duc.deliver(time3, 2.5);
    duc.arrive(time4);
    cout << duc.driverStatus() << endl;
    cout << duc.driverSummary() << endl;

    return 0;
}