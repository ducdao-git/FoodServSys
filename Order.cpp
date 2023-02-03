#include "Order.h"


Order::Order(Time time, string info) {
    orderTime = time;
    this->info = move(info);
}


void Order::depart() throw(logic_error) {
    if (state != "restaurant")
        throw (logic_error("Order is not at the restaurant"));

    state = "delivering";
}


void Order::deliver(const Time &time) throw(logic_error) {
    if (state != "delivering")
        throw (logic_error("Order is not out for delivery yet"));

    state = "delivered";
    deliveredTime = time;
}


Time Order::getOrderTime() const {
    return orderTime;
}


Time Order::getDeliveredTime() const throw(logic_error) {
    if (state != "delivered")
        throw (logic_error("Order hasn't delivered yet"));

    return deliveredTime;
}


int Order::getMinToDelivery() const throw(logic_error) {
    if (state != "delivered")
        throw (logic_error("Order hasn't delivered yet"));

    return Time::elapsedMin(orderTime, deliveredTime);
}


string Order::toString() {
    char space = ' ';
    return orderTime.toString() + space + info;
}