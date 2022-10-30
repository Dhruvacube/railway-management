#include <iostream>
#include <string>
#include <stdio.h>
#include "utility/constants.h"
// #include <format>
using namespace std;

int main()
{
    FILE* fptr;
    fptr = fopen("database/login_screen.txt", "r");
    if (fptr == NULL)
    {
        cout<<"Error! Some files are corrupted please reinstall the program again!"<<endl;
        cout<<"Quitting the program!"<<endl;
        exit(1);
    }
    // std:format("hey {}", "there");

    return 0;
}