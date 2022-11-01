#ifndef AUTH_H
#define AUTH_H
#include <string>
#include "../../utility/constants.h"
#include "auth.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdint>
using namespace std;

std::string string_to_hex(const std::string& in) {
    std::stringstream ss;

    ss << std::hex << std::setfill('0');
    for (size_t i = 0; in.length() > i; ++i) {
        ss << std::setw(2) << static_cast<unsigned int>(static_cast<unsigned char>(in[i]));
    }

    return ss.str(); 
}

class SHA256Hashing {
    public:
        string hash(string password){
        string salted_password = password + salt + password + salt;
        return string_to_hex(salted_password);
    };
};

#endif