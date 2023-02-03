#include "Restaurant.h"


Restaurant::~Restaurant() {
    orderToCook.clear();
    orderToDepart.clear();
    loggedInDriver.clear();
    loggedOutDriver.clear();
}


void Restaurant::status() const {
    cout << getOrderToCookList() << endl;
    cout << getOrderToDepartList() << endl;
    cout << getLoggedInDriverList() << endl;
}


void Restaurant::summary() const {
    cout << " * Number of orders completed: " << completedOrderNum << endl;
    cout << " * Average time per order: ";

    if (completedOrderNum != 0)
        cout << totalServeTime / completedOrderNum << " min" << endl;
    else
        cout << "n/a" << endl;

    for (auto const &driver : loggedInDriver)
        cout << driver->driverSummary() << endl;

    for (auto const &driver : loggedOutDriver)
        cout << driver->driverSummary() << endl;
}


void Restaurant::addDriver(const string &name) throw(logic_error) {
    if (getDriver(name) != nullptr)
        throw (logic_error("The driver already exist"));

    auto *driver = new Driver(name);
    driver->logout();
    loggedOutDriver.push_back(driver);
}


Driver *Restaurant::getDriver(const string &name) const {
    for (auto const &driver : loggedInDriver)
        if (driver->getName() == name)
            return driver;

    for (auto const &driver : loggedOutDriver)
        if (driver->getName() == name)
            return driver;

    return nullptr;
}


void Restaurant::driverLogin(const string &name) throw(logic_error) {
    auto *driver = getDriver(name);

    if (driver == nullptr)
        throw (logic_error("Driver not exist"));

    driver->login();
    loggedInDriver.push_back(driver);
    loggedOutDriver.remove(driver);
}


void Restaurant::driverLogout(const string &name) throw(logic_error) {
    auto *driver = getDriver(name);

    if (driver == nullptr)
        throw (logic_error("Driver not exist"));

    driver->logout();
    loggedOutDriver.push_back(driver);
    loggedInDriver.remove(driver);
}


void Restaurant::addOrder(Time time, const string &info) {
    auto *order = new Order(time, info);
    orderToCook.push_back(order);
}


void Restaurant::serveNextOrder() throw(logic_error) {
    if (orderToCook.empty())
        throw (logic_error("The is no order wait to cook"));

    orderToDepart.push_back(orderToCook.front());
    orderToCook.pop_front();
}


void Restaurant::departNextOrder(const string &name, Time time) throw(logic_error) {
    auto *driver = getDriver(name);

    if (driver == nullptr)
        throw (logic_error("Driver not exist"));

    if (orderToDepart.empty())
        throw (logic_error("The is no order wait to depart"));

    driver->depart(time, orderToDepart.front());
    orderToDepart.pop_front();

    loggedInDriver.remove(driver);
    loggedInDriver.push_back(driver);
}


void Restaurant::driverDeliver(const string &name, Time time, float tip) throw(logic_error) {
    auto *driver = getDriver(name);

    if (driver == nullptr)
        throw (logic_error("Driver not exist"));

    driver->deliver(time, tip);

    totalServeTime += Time::elapsedMin(driver->getOrder().getOrderTime(), time);
    completedOrderNum++;
}


void Restaurant::driverArriveBack(const string &name, Time time) throw(logic_error) {
    auto *driver = getDriver(name);

    if (driver == nullptr)
        throw (logic_error("Driver not exist"));

    driver->arrive(time);
}


string Restaurant::getOrderToCookList() const {
    if (orderToCook.empty())
        return " ! There is no order waiting to be cooked";
    else {
        stringstream report;
        report << " * Orders waiting to cook:\n";

        for (auto const &order : orderToCook) {
            report << "   + " << order->toString();

            if (order != orderToCook.back())
                report << "\n";
        }

        return report.str();
    }
}


string Restaurant::getOrderToDepartList() const {
    if (orderToDepart.empty())
        return " ! There is no order waiting to be delivered";
    else {
        stringstream report;
        report << " * Orders waiting to depart:\n";

        for (auto const &order : orderToDepart) {
            report << "   + " << order->toString();

            if (order != orderToDepart.back())
                report << "\n";
        }

        return report.str();
    }
}


string Restaurant::getLoggedInDriverList() const {
    if (loggedInDriver.empty())
        return " ! There is no logged-in driver";
    else {
        stringstream report;
        report << " * Logged-in driver:\n";

        for (auto const &driver : loggedInDriver) {
            report << "   + " << driver->driverStatus();

            if (driver != loggedInDriver.back())
                report << "\n";
        }

        return report.str();
    }
}