#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include <fstream>
#include "../../utility/constants.h"
#include "../../utility/fmt/core.h"
#include "../creation.h"

using namespace std;

int gen_random_no(const int len) {
    static const char alphanum[] =
        "0123456789";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return stoi(tmp_s);
}

class AdminMenu{
    public:
    void admin_menu(){
        cout<<flush;
        string file;
        ifstream menu_stream;
        menu_stream.open("../../database/menus/admin.txt");
        if (!menu_stream)
        {
            fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow),"Error! Some files are corrupted please reinstall the program again!\n");
            fmt::print(fg(fmt::color::red),"Quitting the program!\n");
            exit(1);
        }
        int choice;
        system("CLS");
        string menu_display;
        while (menu_stream.eof()==0)
        {   
            register string temp_menu_display;
            getline(menu_stream,temp_menu_display);
            menu_display+=(temp_menu_display+"\n");
        }
        cout<<menu_display;
        cin>>choice;
        if (!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow),"\nYou have wrong option in the previous menu selection!\n");
            system("PAUSE");
            this->admin_menu();
        }
        if (choice==1){
            Account account;
            user_type user_type_t;
            user_type_t = admin_user;
            account.create_account(user_type_t);
        }else if (choice==2){
            this->new_train();
        }else if (choice==3){
            this->update_train();
        }else if (choice==4){
            this->delete_train();
        }else if (choice==5){
            cout<<"Logout successfully!"<<endl;
            system("PAUSE");
            system("CLS");
            return;  
        }else{
            fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow),"\nYou have wrong option in the previous menu selection!\n");
            system("PAUSE");
        }
        admin_menu();
    };
    void new_train(){
        system("CLS");
        ofstream train;
        train.open("../../database/trains/data.txt", ios::app);
        fmt::print(fmt::emphasis::bold, "\nNew train data entry\n");
        int train_no = gen_random_no(train_no_length);
        int train_no_down = train_no - 1;
        string destination, departure, name;
        int AC1_coaches,AC2_coaches,AC3_coaches,CC_coaches,AC_coaches,SL_coaches,GN_coaches,kms;

        cout<< "Enter the train name: "<< endl;
        cin>>name;
        
        cout<< "Enter the destination name: "<< endl;
        cin>>destination;

        cout<< "Enter the departure name: "<< endl;
        cin>>departure;

        cout<< "Enter the no of AC1 coaches: "<< endl;
        cin>>AC1_coaches;

        cout<< "Enter the no of AC2 coaches: "<< endl;
        cin>>AC2_coaches;

        cout<< "Enter the no of AC3 coaches: "<< endl;
        cin>>AC3_coaches;

        cout<< "Enter the no of Chair Car coaches: "<< endl;
        cin>>CC_coaches;

        cout<< "Enter the no of AC Chair Car coaches: "<< endl;
        cin>>AC_coaches;

        cout<< "Enter the no of Slepeer class coaches: "<< endl;
        cin>>SL_coaches;

        cout<< "Enter the no of General class coaches: "<< endl;
        cin>>GN_coaches;

        cout<< "Enter the no of kms it would cover: " << endl;
        cin>>kms;

        train << name << " " << train_no << " " << departure << " " << destination << " " << kms << " " << AC1_coaches << " " << AC2_coaches << " " << AC3_coaches << " " << CC_coaches << " " << AC_coaches << " " << SL_coaches << " " << GN_coaches <<endl;
        train << name << " " << train_no_down << " " << destination << " " << departure << " " << kms << " " << AC1_coaches << " " << AC2_coaches << " " << AC3_coaches << " " << CC_coaches << " " << AC_coaches << " " << SL_coaches << " " << GN_coaches << endl;

        train.close();
        system("CLS");
        cout<< "Added train " << name << "with train no " << train_no << "& " << train_no_down <<endl;
        system("PAUSE");
        return;

    };
    void update_train(){
        system("CLS");
        int no;
        cout<< "Please enter the train number of which you want to update: "<<endl;
        cin>>no;
        ofstream train;
        train.open("../../database/trains/data.txt", ios::out | ios::trunc);
        string train_data ="";
        string destination, departure, name;
        bool concelled = false;
        int AC1_coaches,AC2_coaches,AC3_coaches,CC_coaches,AC_coaches,SL_coaches,GN_coaches,kms, train_no;
        while (train<<name << train_no << departure << destination << kms << AC1_coaches << AC2_coaches << AC3_coaches << CC_coaches << AC_coaches << SL_coaches << GN_coaches){
            if (train_no == no){
                cout<< "Enter the train name: "<< endl;
                cin>>name;
                
                cout<< "Enter the destination name: "<< endl;
                cin>>destination;

                cout<< "Enter the departure name: "<< endl;
                cin>>departure;

                cout<< "Enter the no of AC1 coaches: "<< endl;
                cin>>AC1_coaches;

                cout<< "Enter the no of AC2 coaches: "<< endl;
                cin>>AC2_coaches;

                cout<< "Enter the no of AC3 coaches: "<< endl;
                cin>>AC3_coaches;

                cout<< "Enter the no of Chair Car coaches: "<< endl;
                cin>>CC_coaches;

                cout<< "Enter the no of AC Chair Car coaches: "<< endl;
                cin>>AC_coaches;

                cout<< "Enter the no of Slepeer class coaches: "<< endl;
                cin>>SL_coaches;

                cout<< "Enter the no of General class coaches: "<< endl;
                cin>>GN_coaches;

                cout<< "Enter the no of kms it would cover: " << endl;
                cin>>kms;
                train << train_data;
                train << name << " " << train_no << " " << departure << " " << destination << " " << kms << " " << AC1_coaches << " " << AC2_coaches << " " << AC3_coaches << " " << CC_coaches << " " << AC_coaches << " " << SL_coaches << " " << GN_coaches << endl;
                train.close();
                system("CLS");
                cout << "Train data updated"<< endl;
                system("PAUSE");
            }else{
                train_data += (name + " " + to_string(train_no) + " " + departure + " " + destination + " " + to_string(kms) + " " + to_string(AC1_coaches) + " " + to_string(AC2_coaches) + " " + to_string(AC3_coaches) + " " + to_string(CC_coaches) + " " + to_string(AC_coaches) + " " + to_string(SL_coaches) + " " + to_string(GN_coaches) + "\n");
            };
        };
        train.close();
        system("CLS");
        fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow),"\nCouldn't find a train with that no!\n");
        system("PAUSE");
        return;
    };
    void delete_train(){
        system("CLS");
        int no;
        cout<< "Please enter the train number of which you want to delete: "<<endl;
        cin>>no;
        ofstream train;
        train.open("../../database/trains/data.txt", ios::out | ios::trunc);
        string train_data ="";
        string destination, departure, name;
        bool concelled = false;
        int AC1_coaches,AC2_coaches,AC3_coaches,CC_coaches,AC_coaches,SL_coaches,GN_coaches,kms, train_no;
        while (train<<name << train_no << departure << destination << kms << AC1_coaches << AC2_coaches << AC3_coaches << CC_coaches << AC_coaches << SL_coaches << GN_coaches){
            if (train_no != no){
                train_data += (name + " " + to_string(train_no) + " " + departure + " " + destination + " " + to_string(kms) + " " + to_string(AC1_coaches) + " " + to_string(AC2_coaches) + " " + to_string(AC3_coaches) + " " + to_string(CC_coaches) + " " + to_string(AC_coaches) + " " + to_string(SL_coaches) + " " + to_string(GN_coaches) + "\n");
            };
        };
        train << train_data;
        train.close();
        system("CLS");
        fmt::print(fmt::emphasis::bold,"\nIf any train with that train exists then it would be deleted!\n");
        system("PAUSE");
        return;
    };
};

#endif