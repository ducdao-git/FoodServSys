#ifndef PIZZATRACKING_DRIVER_H
#define PIZZATRACKING_DRIVER_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <utility>

#include "Time.h"
#include "Order.h"

using namespace std;

class Driver {
private:
    string name;
    bool logged_in;  // true = logged-in, false = not logged in
    string state;    // 3 state: restaurant, delivering, driving
    float totalTip;
    int totalDeliveries, totalMinDelivering, totalMinDriving;
    Time departTime;
    Order *currOdder, *prevOrder;

public:
    // constructor
    // pre: none
    // post: create a logged-in driver with given name
    explicit Driver(string name);

    // pre: driver not logged in
    // post: log the driver in
    void login() throw(logic_error);

    // pre: driver must at the restaurant to logout
    // post: logs the driver out
    void logout() throw(logic_error);

    // pre: driver is logged in and at the restaurant.
    // post: driver is delivering. departure time is recorded.
    void depart(Time time, Order *order) throw(logic_error);

    // pre: driver is delivering, tip >= 0.
    // post: driver is not delivering. update driver's totalTip, totalDeliveries, totalMinDelivering
    void deliver(Time deliveredTime, float tip) throw(logic_error);

    // pre: driver is driving but not delivering.
    // post: driver is at the restaurant. update driver's totalMinDriving, currOrder and prevOrder
    void arrive(Time time) throw(logic_error);

    // pre: none
    // post: returns the driver’s name.
    string getName() const;

    // pre: none
    // post: returns true iff the driver is logged in.
    bool isLoggedIn() const;

    // pre: none
    // post: returns the total number of completed deliveries.
    int getTotalDeliveries() const;

    // pre: none
    // post: returns the total minutes spent delivering (i.e., between “depart” and “deliver” commands).
    int getTotalMinDelivering() const;

    // pre: none
    // post: returns the total minutes spent driving (i.e., between “depart” and “arrive” commands).
    int getTotalMinDriving() const;

    // pre: none
    // post: returns the total tips received, in dollars.
    float getTotalTips() const;

    // pre: driver is delivering.
    // post: returns the order being delivered i.e. head of linked list.
    Order getOrder() const throw(logic_error);

    // pre: none
    // post: summary on driver's num of completed deliveries, total driving time, total tip
    string driverSummary() const;

    // pre: none
    // post: returns a string containing the driver’s name and status
    string driverStatus() const;
};

#endif //PIZZATRACKING_DRIVER_H
