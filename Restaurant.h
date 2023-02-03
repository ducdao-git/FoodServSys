#ifndef PIZZATRACKING_RESTAURANT_H
#define PIZZATRACKING_RESTAURANT_H

#include <iostream>
#include <list>

#include "Driver.h"
#include "Order.h"
#include "Time.h"

using namespace std;

class Restaurant {
private:
    list<Order *> orderToCook{};
    list<Order *> orderToDepart{};
    list<Driver *> loggedInDriver{};
    list<Driver *> loggedOutDriver{};
    int completedOrderNum{}, totalServeTime{};

public:
    // pre: none
    // post: creates a restaurant in an initial state, with no drivers or orders.
    Restaurant() = default;

    // pre: none
    // post: delete restaurant obj.
    ~Restaurant();

    // pre: none
    // post: prints status of orders and logged-in drivers, as specified by the “status” command description.
    void status() const;

    // pre: none
    // post: prints summary statistics on orders and drivers, as specified by the “summary” command description.
    void summary() const;

    // pre: none
    // post: adds the given driver to the system.
    void addDriver(const string &name) throw(logic_error);

    // pre: none
    // post: if a driver with the given name exists within the system (logged in or not),
    //       returns a pointer to that driver. otherwise, returns a null pointer.
    Driver *getDriver(const string &name) const;

    // pre: driver exist and not logged in
    // post: login a driver
    void driverLogin(const string &name) throw(logic_error);

    // pre: driver exist and must at the restaurant to logout
    // post: logout a driver
    void driverLogout(const string &name) throw(logic_error);

    // pre: none
    // post: create and adds the given order to the system, enqueuing it for cooking.
    void addOrder(Time time, const string &info);

    // pre: the cooking queue is not empty.
    // post: removes the oldest order from the cooking queue and enqueues it for departure.
    void serveNextOrder() throw(logic_error);

    // pre: driver is logged-in and at restaurant, have order wait for depart
    // post: removes the oldest order from the departure queue and give it to driver.
    void departNextOrder(const string &name, Time time) throw(logic_error);

    // pre: driver is delivering, tip >= 0.
    // post: the order carried by the driver is delivered at the given time. the driver receives the given tip.
    void driverDeliver(const string &name, Time time, float tip) throw(logic_error);

    // pre: driver is driving but not delivering.
    // post: update time driver get back to the restaurant to keep track driver stat
    void driverArriveBack(const string &name, Time time) throw(logic_error);

    // pre: none
    // post: return string contain orders waiting to cook
    string getOrderToCookList() const;

    // pre: none
    // post: return string contain orders waiting to depart
    string getOrderToDepartList() const;

    // pre: none
    // post: return logged-in driver list along with their status
    string getLoggedInDriverList() const;
};

#endif //PIZZATRACKING_RESTAURANT_H