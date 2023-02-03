#ifndef PIZZATRACKING_ORDER_H
#define PIZZATRACKING_ORDER_H

#include <string>
#include <stdexcept>
#include <utility>

#include "Time.h"

using namespace std;

class Order {
private:
    Time orderTime{}, deliveredTime{};
    string info{};
    string state = "restaurant"; // restaurant, delivering, delivered

public:
    // default constructor
    // pre: none
    // post: creates an order with default values
    Order() = default;

    // param constructor
    // pre: none
    // post: creates an order with the given order time and information
    Order(Time time, string info);

    // pre: order is at the restaurant
    // post: order is out for delivery
    void depart() throw(logic_error);

    // pre: order is out for delivery
    // post: order is delivered. deliveredTime is recorded
    void deliver(const Time &time) throw(logic_error);

    // pre: none
    // post: return orderTime
    Time getOrderTime() const;

    // pre: order is delivered
    // post: return deliveredTime
    Time getDeliveredTime() const throw(logic_error);

    // pre: order is delivered
    // post: returns the minutes until the order is delivered (i.e., between “order” and “deliver” commands).
    int getMinToDelivery() const throw(logic_error);

    // pre: none
    // post: returns a string containing the order time and info
    string toString();
};

#endif //PIZZATRACKING_ORDER_H
