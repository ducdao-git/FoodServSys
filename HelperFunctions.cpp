#include "HelperFunctions.h"


float moneyFormat(const string &tip) throw(logic_error) {
    int dotLocL = tip.find('.');
    int dotLocR = tip.rfind('.');
    if (dotLocL == string::npos || dotLocL != dotLocR)
        throw (logic_error("Invalid tip"));

    float dollar = (float) stoi(tip.substr(0, dotLocL));
    float cent = (float) stoi(tip.substr(++dotLocL));

    if ((dollar < 0) || (cent < 0) || (cent > 99))
        throw (logic_error("Invalid tip"));

    return (dollar + cent / 100);
}


string infoExtraction(const list <string> &inputStr) {
    string info{};
    int wordCount = 0;

    for (auto &i : inputStr) {
        if (wordCount < 2) {
            wordCount++;
        } else {
            info.append(i);
            info.append(" ");
        }
    }

    return info;
}


Time constructTimeHelper(const string &time) throw(logic_error) {
    int colonLocL = time.find(':');
    int colonLocR = time.rfind(':');
    if (colonLocL == string::npos || colonLocL != colonLocR)
        throw (logic_error("Invalid time"));

    int hour = stoi(time.substr(0, colonLocL));
    int minute = stoi(time.substr(++colonLocL));

    if ((hour < 0) || (hour > 23) || (minute < 0) || (minute > 59))
        throw (logic_error("Invalid time"));

    return {hour, minute};
}


string wordFormat(string &word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    word[0] = toupper(word[0]);

    return word;
}


list <string> getCommand() {
    string inputStr, word;
    list <string> inputCmd{};

    cout << endl << "Command: ";
    getline(cin, inputStr);
    istringstream splitStr(inputStr);

    while (splitStr >> word)
        inputCmd.push_back(word);

    return inputCmd;
}


void print_help() {
    cout << endl << "Commands:" << endl;
    cout << "  Help or H                    : Help (displays this message)" << endl;
    cout << "  Driver <name>                : Add a new drive to the restaurant" << endl;
    cout << "  Login <name>                 : Login with driver's username" << endl;
    cout << "  Logout <name>                : Logout with driver's username" << endl;
    cout << "  Order <time> <info>          : Add an order" << endl;
    cout << "  Serve                        : Serve the next order" << endl;
    cout << "  Depart <time> <name>         : Time driver go out to deliver" << endl;
    cout << "  Deliver <time> <name> <tip>  : Time driver delivered the order" << endl;
    cout << "  Arrive <time> <name>         : Time driver got back to the restaurant" << endl;
    cout << "  Status                       : Display status of order and driver" << endl;
    cout << "  Summary                      : Display statistic summary of the restaurant" << endl;
    cout << "  Quit or Q                    : Quit the test program" << endl;
}