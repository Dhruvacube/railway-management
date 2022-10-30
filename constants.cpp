#include <string>
#include <map>

//hashing
const std::string salt = "5213761a294a36227cd81dcc06d446b6"; //It could be anything, it will be helpful in decoding the password stored in the database

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

int get_seat_count(char seat_class) {
    if (seating.find(toupper(seat_class)) != seating.end()) {
        return seating[toupper(seat_class)];
    }else{
        return 0;
    }
}