#include <string>
#include "../hash/sha256.h"
#include "../../utility/constants.h"
#include "auth.h"

using namespace std;
extern string salt;

string SHA256Hashing::hash(string password){
    string salted_password = password + salt + password + salt;
    return sha256(salted_password);
}
