#include "Restaurant.h"


int main() {  // restaurant class test
    Time time1(0, 15);
    Time time2(0, 30);
    Time time3(1, 45);
    Time time4(2, 15);

    cout << "***test default constructor***" << endl;
    Restaurant res1{};
//    res1.status();

    cout << "\n***test addDriver***" << endl;
    res1.addDriver("Driver 1");
    res1.addDriver("Driver 2");
//    res1.addDriver("Driver 2");
//    res1.status();

    cout << "\n***test login***" << endl;
    res1.driverLogin("Driver 1");
    res1.driverLogin("Driver 2");
//    res1.driverLogin("Driver 2");
    res1.status();

    cout << "\n***test logout***" << endl;
//    res1.driverLogout("Driver 1");
//    res1.driverLogout("Driver 2");
//    res1.driverLogout("Driver 2");
//    res1.status();

    cout << "\n***test addOrder***" << endl;
    res1.addOrder(time1, "Order 1");
    res1.addOrder(time2, "Order 2");
    res1.status();

    cout << "\n***test serveNextOrder***" << endl;
    res1.serveNextOrder();
    res1.serveNextOrder();
    res1.status();

    cout << "\n***test departNextOrder***" << endl;
    res1.departNextOrder("Driver 1", time2);
//    res1.departNextOrder("Driver 1", time3);
    res1.departNextOrder("Driver 2", time3);
//    res1.departNextOrder("Driver 2", time3);
    res1.status();

    cout << "\n***test driverDeliver***" << endl;
    res1.driverDeliver("Driver 1", time3, 7.50);
//    res1.driverDeliver("Driver 1", time3, 7.50);
//    res1.driverDeliver("Driver 2", time4, 8.5);
//    res1.driverDeliver("Driver 2", time4, 8.5);
//    res1.status();
//    res1.summary();

    cout << "\n***test driverArriveBack***" << endl;
    res1.driverArriveBack("Driver 1", time4);
//    res1.driverArriveBack("Driver 1", time4);
//    res1.driverArriveBack("Driver 2", time1);
//    res1.driverArriveBack("Driver 2", time1);
    res1.status();
//    res1.summary();

    return 0;
}

//int main() {
//    Restaurant res1;
//    res1.addDriver("Dan");
//    res1.addDriver("Adam");
//
//    Time time1(10, 00);
//    Time time2(10, 15);
//    Time time3(10, 30);
//    Time time4(10, 45);
//    Time time5(11, 00);
//
//    res1.addOrder(time1, "Order 1");
//    res1.addOrder(time2, "Order 2");
//    res1.driverLogin("Dan");
//
//    res1.serveNextOrder();
//    res1.departNextOrder("Dan", time2);
//
//    res1.addOrder(time3, "Order 3");
//    res1.driverLogin("Adam");
//
//    res1.addOrder(time4, "Order 4");
//    res1.serveNextOrder();
//
//    cout << "Report 1: " << endl;
//    res1.status();
//    cout << endl;
//
//    res1.driverDeliver("Dan", time4, 4.50);
//    res1.driverArriveBack("Dan", time5);
//
//    cout << "Report 2: " << endl;
//    res1.status();
//    cout << endl;
//    cout << "\nSummary:\n";
//    res1.summary();
//}
