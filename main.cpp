#define FMT_HEADER_ONLY
#include <iostream>
#include <fstream>
#include <string>
#include "utility/constants.h"
#include "utility/fmt/core.h"
#include "utility/fmt/color.h"
#include "utility/fmt/format.h"
#include <conio.h>


int main()
{
    cout<<flush;
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
    bool display_error = false;
    while (menu.eof()==0)
    {   
        register string temp_menu_display;
        getline(menu,temp_menu_display);
        menu_display+=(temp_menu_display+"\n");
    }
    menu.close();
    menu_display=fmt::format(menu_display,name);
    int choice;
   do{
        system("CLS");
        cout<<menu_display;
        cin>>choice;
        switch(choice)

        {
            case 1:

        }
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
        }else{
            display_error = true;
            system("CLS");
        }
        if (display_error){
           fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow),"\nYou have wrong option in the previous menu selection!\n");
           display_error=false;
           system("PAUSE");
        }
    }while(choice<=4);
    getch();

    return 0;
}