#include "auth.h"
#include <string>
#include <algorithm>
#include "hash/sha256.h"
#include "../../utility/constants.h"

using namespace std;

extern const string salt;

class SHA256Hashing {
    public:
        static string hash(string password) {
            string salted_password = password + salt + password + salt;
            return sha256(salted_password);
        }
};

bool Auth::login(string username, string password, login_type login_type_t) {
    SHA256Hashing hashing;
    string hashed_password = hashing.hash(password);
    
}
