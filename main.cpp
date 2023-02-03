#include "HelperFunctions.h"


int main() {
    Restaurant res0{};

    list<string> inputStr;
    string cmd{};

    print_help();

    do {
        inputStr = getCommand();

        cmd = inputStr.front();
        wordFormat(cmd);

        try {
            if (cmd == "Help" || cmd == "H") {
                print_help();

            } else if (cmd == "Driver") {
                wordFormat(inputStr.back());
                res0.addDriver(inputStr.back());

            } else if (cmd == "Login") {
                wordFormat(inputStr.back());
                res0.driverLogin(inputStr.back());

            } else if (cmd == "Logout") {
                wordFormat(inputStr.back());
                res0.driverLogout(inputStr.back());

            } else if (cmd == "Order") {
                auto it = next(inputStr.begin(), 1);
                res0.addOrder(constructTimeHelper(*it), infoExtraction(inputStr));

            } else if (cmd == "Serve") {
                res0.serveNextOrder();

            } else if (cmd == "Depart") {
                auto it = next(inputStr.begin(), 1);
                wordFormat(inputStr.back());

                res0.departNextOrder(inputStr.back(), constructTimeHelper(*it));

            } else if (cmd == "Deliver") {
                auto it = next(inputStr.begin(), 1);
                string time = *it;

                advance(it, 1);
                string name = wordFormat(*it);

                float tip = moneyFormat(inputStr.back());
                res0.driverDeliver(name, constructTimeHelper(time), tip);

            } else if (cmd == "Arrive") {
                auto it = next(inputStr.begin(), 1);
                string time = wordFormat(*it);

                advance(it, 1);
                string name = wordFormat(*it);

                res0.driverArriveBack(name, constructTimeHelper(time));

            } else if (cmd == "Status") {
                cout << "[After “status” command:]" << endl;
                res0.status();
//                cout << endl;

            } else if (cmd == "Summary") {
                cout << "[After “summary” command:]" << endl;
                res0.summary();
//                cout << endl;

            } else if (cmd == "Quit" || cmd == "Q") {
                break;

            } else
                cout << " ? Invalid Command" << endl;

        }
        catch (const logic_error &e) {
            cout << " ? Error: " << e.what() << endl;
        }

    } while (cmd != "Quit" || cmd == "Q");

    return 0;
}