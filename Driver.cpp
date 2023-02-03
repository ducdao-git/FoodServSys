#include "Driver.h"


Driver::Driver(string name) : name(move(name)), logged_in(true), state("restaurant"), totalTip(0.0) {
    totalDeliveries = totalMinDelivering = totalMinDriving = 0;

    Time time{};
    departTime = time;

    currOdder = prevOrder = nullptr;
}


void Driver::login() throw(logic_error) {
    if (isLoggedIn())
        throw (logic_error("Driver already logged-in"));

    logged_in = true;
}


void Driver::logout() throw(logic_error) {
    if (!isLoggedIn())
        throw (logic_error("Driver hasn't logged-in yet"));
    else if (state != "restaurant")
        throw (logic_error("Driver is not at the restaurant to logout"));

    logged_in = false;
}


void Driver::depart(Time time, Order *order) throw(logic_error) {
    if (!isLoggedIn())
        throw (logic_error("Driver hasn't logged-in yet"));
    else if (state != "restaurant")
        throw (logic_error("Driver is not at the restaurant to deliver"));

    state = "delivering";
    departTime = time;

    currOdder = order;
    currOdder->depart();
}


void Driver::deliver(Time deliveredTime, float tip) throw(logic_error) {
    if (state != "delivering")
        throw (logic_error("Driver is not delivering"));
    else if (tip < 0)
        throw (logic_error("Invalid tip amount"));

    currOdder->deliver(deliveredTime);

    state = "driving";
    totalTip += tip;
    totalDeliveries++;

    totalMinDelivering += Time::elapsedMin(departTime, deliveredTime);
}


void Driver::arrive(Time time) throw(logic_error) {
    if (state != "driving")
        throw (logic_error("Driver is currently not driving"));

    state = "restaurant";
    totalMinDriving += Time::elapsedMin(currOdder->getDeliveredTime(), time);

    prevOrder = currOdder;
    currOdder = nullptr;
}


string Driver::getName() const {
    return name;
}


bool Driver::isLoggedIn() const {
    return logged_in;
}


int Driver::getTotalDeliveries() const {
    return totalDeliveries;
}


int Driver::getTotalMinDelivering() const {
    return totalMinDelivering;
}


int Driver::getTotalMinDriving() const {
    return totalMinDriving;
}


float Driver::getTotalTips() const {
    return totalTip;
}


Order Driver::getOrder() const throw(logic_error) {
    return *currOdder;
}


string Driver::driverSummary() const {
    stringstream report;
    report << " * Driver " << name << ":" << "\n" <<
           "   + Number of deliveries completed: " << totalDeliveries << "\n";

    if (totalDeliveries != 0)
        report << "   + Average time per completed delivery: " << (totalMinDelivering / totalDeliveries) << " min\n";
    else
        report << "   + Average time per completed delivery: n/a \n";

    report << "   + Total driving time: " << (totalMinDriving + totalMinDelivering) << " min\n" <<
           "   + Total tips: $" << totalTip;

    return report.str();
}


string Driver::driverStatus() const {
    string space = ": ";
    string ready = "Ready to take order";

    if (!isLoggedIn())
        return "Driver is not logged-in";

    if (state != "restaurant")
        return name + space + getOrder().toString();
    else
        return name + space + ready;
}
