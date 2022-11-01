#ifndef AUTH_H
#define AUTH_H
#include <string>
using namespace std;

class SHA256Hashing {
    public:
        string hash(string password);
};

#endif