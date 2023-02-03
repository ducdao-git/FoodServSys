#ifndef RESTAURANTTEST_CPP_HELPERFUNCTIONS_H
#define RESTAURANTTEST_CPP_HELPERFUNCTIONS_H

#include "Restaurant.h"

void print_help();

list<string> getCommand();

string wordFormat(string &word);

Time constructTimeHelper(const string &time) throw(logic_error);

string infoExtraction(const list<string> &inputStr);

float moneyFormat(const string &tip) throw(logic_error);

#endif //RESTAURANTTEST_CPP_HELPERFUNCTIONS_H
