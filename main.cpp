#define FMT_HEADER_ONLY
#include <iostream>
#include <fstream>
#include <string>
#include "utility/constants.h"
#include "utility/fmt/core.h"
#include "utility/fmt/color.h"
#include "utility/utility.h"
#include "utility/fmt/format.h"

int main()
{
    string file;
    ifstream menu;
    menu.open("database/menus/login_screen.txt");
    if (!menu)
    {
        fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow),"Error! Some files are corrupted please reinstall the program again!\n");
        fmt::print(fg(fmt::color::red),"Quitting the program!\n");
        exit(1);
    }
    string menu_display;
    while (menu.eof()==0)
    {   
        register string temp_menu_display;
        getline(menu,temp_menu_display);
        menu_display+=(temp_menu_display+"\n");
    }
    menu.close();
    menu_display=fmt::format(menu_display,name);
    while(true){
        int choice = -1;
        system("CLS");
        cout<<flush<<menu_display;
        cin>>choice;
        cout<<choice<<"hey";
        if (choice==1){
            cout<<"hey";
        }else if (choice==2){
            cout<<"hey";
        }else if (choice==3){
            /* code */
        }else if (choice==4){
            system("PAUSE");
            system("CLS");
            exit(1);  
        }else if (choice != -1){
            fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow),"\nPlease select a valid option from the above menu!\n");
            sleepcp(2000);
            system("CLS");
        }
    };

    return 0;
}