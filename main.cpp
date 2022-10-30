#include <iostream>
#include <fstream>
#include <string>
#include "utility/constants.h"
using namespace std;

int main()
{
    string menu;
    ifstream in("database/login_screen.txt");
    in>>menu;
    cout << menu;
    return 0;
}