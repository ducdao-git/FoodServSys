#include "Order.h"


int main() {  // time class test
    cout << "***test constructor***" << endl;
    Time time1(5, 0);
    Time time2(15, 0);

    Order o0{};
    Order o1(time1, "1 pizza to wooster");

    cout << o0.toString() << endl;
    cout << o1.toString() << endl;

    cout << "\n***test depart***" << endl;
    o1.depart();
//    o1.depart();

    cout << "\n***test deliver***" << endl;
    o1.deliver(time2);
//    o1.deliver(time2);
    cout << o1.toString() << endl;

    cout << "\n***test getMinToDelivery***" << endl;
    cout << o1.getMinToDelivery() << endl;

    return 0;
}