#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <map>
#include <string>

const std::string salt = "5213761a294a36227cd81dcc06d446b6"; //It could be anything, it will be helpful in decoding the password stored in the database

//Name of the railway management app
std::string name = "Indian Rail Transport Corporation (IRCTC) Ltd";

// seating layout in the trains
const int ac1_seats = 24;
const int ac2_seats = 54;
const int ac3_seats = 64;
const int chair_car = 78;
const int ac_chair_car = 72;
const int sleeper_seats = 72;
const int general_seats = 72;

const int train_no_length = 5;

//seat mapping with the seating class in a dict type of python
std::map<std::string, int> seating = {
    { "1AC", ac1_seats },
    { "2AC", ac2_seats },
    { "3AC", ac3_seats },
    { "CC", chair_car },
    { "AC", ac_chair_car },
    { "SL", sleeper_seats },
    { "GN", general_seats }
};

enum login_type
{
    admin,
    user
};

enum user_type
{
    admin_user,
    normal_user
};

#endif