#include <string>
#include <algorithm>

using namespace std;

extern const string salt;

static class MD5Hashing {
    string salt;
    public:
        MD5Hashing(string salt)
        {
            this->salt = salt;
        }

        string hash(string password) {
            string salted_password = password + salt;
            return ;
        }
};