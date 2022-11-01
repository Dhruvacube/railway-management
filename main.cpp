#define FMT_HEADER_ONLY
#include <iostream>
#include <fstream>
#include <string>
#include "utility/constants.h"
#include "utility/fmt/core.h"
#include "utility/fmt/color.h"
#include "utility/fmt/format.h"
#include "auth/handler.h"
#include "user/creation.h"
#include "user/admin/admin.h"
#include "user/customer/customer.h"
#include <conio.h>
using namespace std;

bool admin_checker(){
    std::ifstream data;
    int ph_no;
    string username, password, first_name, last_name, address, email;
    bool admin;
    data.open("database/user/data.txt", std::ios::app);
    while(data>>username>>password>>email>>ph_no>>first_name>>last_name>>address>>admin){
        if (admin==true){
            data.close();
            return true;
        };
    };
    data.close();
    return false;
};

void menu(string menu_display){
    int choice;
    system("CLS");
    cout<<menu_display;
    cin>>choice;
    if (!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow),"\nYou have wrong option in the previous menu selection!\n");
        system("PAUSE");
        menu(menu_display);
    }
    Handler handler;
    login_type login_type_t;
    if (choice==1){
        login_type_t = admin;
        handler.handle(login_type_t);
        AdminMenu menu;
        menu.admin_menu();
    }else if (choice==2){
        login_type_t = user;
        handler.handle(login_type_t);
        CustomerMenu menu;
        menu.customer_menu();
    }else if (choice==3){
        Account account;
        user_type user_type_t;
        user_type_t = normal_user;
        account.create_account(user_type_t);
    }else if (choice==4){
        system("PAUSE");
        system("CLS");
        exit(1);  
    }else{
        fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow),"\nYou have wrong option in the previous menu selection!\n");
        system("PAUSE");
        menu(menu_display);
    }
    menu(menu_display);
};

int main()
{
    cout<<flush;
    if (!admin_checker()){
        Account account;
        user_type user_type_t;
        user_type_t = admin_user;
        fmt::print(fmt::emphasis::bold | fg(fmt::color::sky_blue),"\nSince system has no admin account, so first an admin account will be created!\n");
        system("PAUSE");
        account.create_account(user_type_t);
    }
    string file;
    ifstream menu_stream;
    menu_stream.open("database/menus/login_screen.txt");
    if (!menu)
    {
        fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow),"Error! Some files are corrupted please reinstall the program again!\n");
        fmt::print(fg(fmt::color::red),"Quitting the program!\n");
        exit(1);
    }
    string menu_display;
    bool display_error = false;
    while (menu_stream.eof()==0)
    {   
        register string temp_menu_display;
        getline(menu_stream,temp_menu_display);
        menu_display+=(temp_menu_display+"\n");
    }
    menu_stream.close();
    menu_display=fmt::format(menu_display,name);
    menu(menu_display);
    getch();
    return 0;
}