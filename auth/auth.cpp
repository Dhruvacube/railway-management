#include <string>
#include <../constants.cpp>
using namespace std;

class MD5Hashing {
    public:
        string salt = "5213761a294a36227cd81dcc06d446b6";
        string hash(string password) {
            string salted_password = password + salt;
            return md5(salted_password);
        }
};