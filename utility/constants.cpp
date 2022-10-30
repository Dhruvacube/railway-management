#include <string>
#include "constants.h"

//hashing
const std::string salt = "5213761a294a36227cd81dcc06d446b6"; //It could be anything, it will be helpful in decoding the password stored in the database

int get_seat_count(char seat_class) {
    if (seating.find(toupper(seat_class)) != seating.end()) {
        return seating[toupper(seat_class)];
    }else{
        return 0;
    }
}