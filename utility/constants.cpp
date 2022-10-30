#include <string>
#include "constants.h"
#include <map>

//hashing
const std::string salt = "5213761a294a36227cd81dcc06d446b6"; //It could be anything, it will be helpful in decoding the password stored in the database

int get_seat_count(string seat_class) {
    if (seating.find(seat_class) != seating.end()) {
        return seating[seat_class];
    }else{
        return 0;
    }
}