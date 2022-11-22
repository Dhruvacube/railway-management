#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <fstream>
#include "../../utility/constants.h"
#include "../../utility/fmt/core.h"
#include "../creation.h"

using namespace std;

class CustomerMenu{
    public:
    void customer_menu(){
        cout << flush;
        string file;
        ifstream menu_stream;
        menu_stream.open("database/menus/customer.txt");
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
            customer_menu();
        }
        if (choice==1){
            this->display_trains();
        }else if (choice==2){
            this->book();
        }else if (choice==3){
            this->cancel();
        }else if (choice==4){
            cout<<"Logout successfully!"<<endl;
            system("PAUSE");
            system("CLS");
            return;  
        }else{
            fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow),"\nYou have wrong option in the previous menu selection!\n");
            system("PAUSE");
        }
        customer_menu();
    };
    void display_trains(){
        system("CLS");
        ofstream train;
        train.open("../../database/trains/data.txt");
        int train_no;
        string destination, departure, name;
        int AC1_coaches,AC2_coaches,AC3_coaches,CC_coaches,AC_coaches,SL_coaches,GN_coaches,kms;
        while (train << name << train_no << departure << destination << kms << AC1_coaches << AC2_coaches << AC3_coaches << CC_coaches << AC_coaches << SL_coaches << GN_coaches){
            cout<<endl;
            cout<<endl;
            cout<<"Train Name: "<<name<<endl;
            cout<<"Train No: "<<train_no<<endl;
            cout<<"Departure: "<<departure<<endl;
            cout<<"Destination: "<<destination<<endl;
            cout << "Kms: " << kms << "kms"<<endl;
            cout<<"AC1 Coaches: "<<AC1_coaches<<endl;
            cout<<"AC2 Coaches: "<<AC2_coaches<<endl;
            cout<<"AC3 Coaches: "<<AC3_coaches<<endl;
            cout<<"CC Coaches: "<<CC_coaches<<endl;
            cout<<"AC Coaches: "<<AC_coaches<<endl;
            cout<<"SL Coaches: "<<SL_coaches<<endl;
            cout<<"GN Coaches: "<<GN_coaches<<endl;

        };
        train.close();
    };
    void book(){
        int no;
        system("CLS");
        ofstream booking, trains;
        booking.open("database/trains/book.txt");
        trains.open("database/trains/data.txt");
        int booking_no, seat_no;
        bool AC1, AC2,AC3,CC,AC,SL,GN;
        int n=0;

        cout<<"Enter the train no: ";
        cin>>no;

        int train_no;
        string destination, departure, name;
        int AC1_coaches,AC2_coaches,AC3_coaches,CC_coaches,AC_coaches,SL_coaches,GN_coaches,kms;
        while (trains << name << train_no << departure << destination << kms << AC1_coaches << AC2_coaches << AC3_coaches << CC_coaches << AC_coaches << SL_coaches << GN_coaches){
            if(train_no == no){
                n++;
            }
        }

        if(n==0){
            cout<<"Train not found!"<<endl;
            system("PAUSE");
            return;
        }
        
        string date;
        cout<<"Enter the date of journey: ";
        cin>>date;

        int seats_no;
        cout<<"Enter the number of seats: ";
        cin>>seats_no;

        string seat_type;
        cout<<"Enter the seat type: ";
        cin>>seat_type;

        booking << to_string(no) + " ";
        booking.flush();
        booking << to_string(booking_no) +  " ";
        booking.flush();
        booking <<  to_string(seat_no) + " " ;
        booking.flush();
        booking << date + " ";
        booking.flush();
        booking << seat_type + "\n";
        booking.close();
    };
    void cancel(){
        system("CLS");
        int booking_no;
        cout<<"Enter the booking no: ";
        cin>>booking_no;

        string date, seat_type;
        int seat_no, train_no;

        ofstream booking;
        booking.open("database/trains/book.txt");
        int n = 0;
        // string dummy_data
        while(booking << train_no << booking_no << seat_no << date << seat_type){
            if(booking_no == booking_no){
                fmt::print(fmt::emphasis::bold ,"Booking found!");
                cout<<"Train no: "<<train_no<<endl;
                cout<<"Date: "<<date<<endl;
                cout<<"Seat type: "<<seat_type<<endl;
                cout<<"Number of Seats: "<<seat_no<<endl<<endl;
                fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow),"\nBooking canceled!\n");
                system("PAUSE");
                n+=1;
            };
        };
        if(n){
            fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow),"\nNo booking with that booking id found!\n");
        }
        return;
    };
};

#endif