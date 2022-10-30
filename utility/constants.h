#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <map>
#include <string>

using namespace std;

// seating layout in the trains
const int ac1_seats = 24;
const int ac2_seats = 54;
const int ac3_seats = 64;
const int chair_car = 78;
const int ac_chair_car = 72;
const int sleeper_seats = 72;
const int general_seats = 72;

//seat mapping with the seating class in a dict type of python
std::map<char, int> seating = {
    { '1AC', ac1_seats },
    { '2AC', ac2_seats },
    { '3AC', ac3_seats },
    { 'CC', chair_car },
    { 'AC', ac_chair_car },
    { 'SL', sleeper_seats },
    { 'GN', general_seats }
};

const string login_screen_path = "../database/login_screen.txt";

#endif