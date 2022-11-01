#ifndef CREATION_H
#define CREATION_H
#include <iostream>
#include <string>
#include <fstream>
#include "../utility/constants.h"
#include "../utility/fmt/core.h"
#include "../utility/fmt/color.h"
#include "../utility/fmt/format.h"
#include "../auth/auth/auth.h"
#include <cmath>

std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}


class Account{
    private:
        std::string pass_word;
        std::string address;
        bool admin;
        bool email_checker(string check){
            int at_count = 0;
            int dot_count = 0;
            for (int i = 0; i < check.length(); i++){
                if (check[i] == '@'){
                    at_count++;
                }
                if (check[i] == '.'){
                    dot_count++;
                }
            }
            if (at_count == 1 && dot_count == 1){
                return true;
            }
            else{
                return false;
            }
        }

        bool phone_no_length_checker(int phno){
            int check = trunc(log10(phno)) + 1;
            if (check == 10){
                return true;
            }
            else{
                return false;
            }
        }
    public:
        std::string user_name;
        std::string email;
        int phone_number;
        std::string first_name;
        std::string last_name;
        Account(std::string user_name, std::string pass_word, std::string email, int phone_number, std::string first_name, std::string last_name, std::string address, bool admin){
            this->user_name = user_name;
            this->pass_word = pass_word;
            try{
                if (email_checker(email)){
                    this->email = email;
                }
                else{
                    throw "Invalid email";
                }
            }
            catch(const char* msg){
                std::cout<<std::endl;
                fmt::print(fmt::emphasis::bold | fg(fmt::color::red),msg);
                std::cout<<std::endl;
            }
            try{
                if (phone_no_length_checker(phone_number)){
                    this->phone_number = phone_number;
                }
                else{
                    throw "Invalid phone number, It must be 10 digits";
                }
            }
            catch(const char* msg){
                std::cout<<std::endl;
                fmt::print(fmt::emphasis::bold | fg(fmt::color::red),msg);
                std::cout<<std::endl;
            }
            this->first_name = first_name;
            this->last_name = last_name;
            this->address = address;
            this->admin = admin;
        };
        Account(std::string user_name, std::string email, int phone_number, std::string first_name, std::string last_name, std::string address, bool admin){
            this->user_name = user_name;
            try{
                if (email_checker(email)){
                    this->email = email;
                }
                else{
                    throw "Invalid email";
                }
            }
            catch(const char* msg){
                std::cout<<std::endl;
                fmt::print(fmt::emphasis::bold | fg(fmt::color::red),msg);
                std::cout<<std::endl;
            }
            try{
                if (phone_no_length_checker(phone_number)){
                    this->phone_number = phone_number;
                }
                else{
                    throw "Invalid phone number, It must be 10 digits";
                }
            }
            catch(const char* msg){
                std::cout<<std::endl;
                fmt::print(fmt::emphasis::bold | fg(fmt::color::red),msg);
                std::cout<<std::endl;
            }
            this->first_name = first_name;
            this->last_name = last_name;
            this->address = address;
            this->admin = admin;
        };
        Account(){
            this->user_name = gen_random(5);
            this->pass_word = "";
            this->email = "";
            this->phone_number = 0;
            this->first_name = "";
            this->last_name = "";
            this->address = "";
            this->admin = false;
        };
        void add_password(string password){
            SHA256Hashing hash_class;
            this->pass_word = hash_class.hash(password);
        };
        string return_hash(string password){
            SHA256Hashing hash_class;
            this->pass_word = hash_class.hash(password);
        };

        Account create_account(user_type user_type_t){
            system("CLS");
            try{
                std::ofstream data;
                data.open("../../database/user/data.txt", std::ios::app);
                Account account;
                bool admin;
                if (user_type_t == admin_user){
                    admin = true;
                }
                else{
                    admin = false;
                }
                std::cout << fmt::format("{} \nAccount Creation", name) << std::endl;
                
                string first_name, last_name;
                cout<<"Enter your first name: "<<endl;
                cin>>first_name;

                cout<<"Enter your last name: "<<endl;
                cin>>last_name;
                    
                string password;
                cout<< "Enter the password: "<<endl;
                cin >> password;
                password = this->return_hash(password);

                try{
                    string email;
                    cout<< "Enter the email id: "<<endl;
                    cin >> email;
                    if (email_checker(email)){
                        account.email = email;
                    }
                    else{
                        throw "Invalid email";
                    }
                }catch(const char* msg){
                    std::cout<<std::endl;
                    fmt::print(fmt::emphasis::bold | fg(fmt::color::red),msg);
                    std::cout<<std::endl;
                    system("PAUSE");
                    void create_account(user_type user_type_t);
                };

                try{
                    int phone_number;
                    cout<< "Enter the you phone no: "<<endl;
                    cin >> phone_number;
                    if (phone_no_length_checker(phone_number)){
                        account.phone_number = phone_number;
                    }
                    else{
                        throw "Invalid phone number, It must be 10 digits";
                    }
                }
                catch(const char* msg){
                    std::cout<<std::endl;
                    fmt::print(fmt::emphasis::bold | fg(fmt::color::red),msg);
                    std::cout<<std::endl;
                    system("PAUSE");
                    void create_account(user_type user_type_t);
                };

                string address;
                cout<<"Enter address: "<<endl;
                cin>>address;

                data << this->user_name << " " << password << " " << email << " " << phone_number << " " << first_name << " " << last_name << " " << address << " " << admin << std::endl;
                data.close();
                system("CLS");
                cout << "Account created successfully with username as" << user_name << endl;
                cout << "Please note down your username" << endl;
                system("PAUSE");
                return account;
        }catch(...){
            fmt::print(fmt::emphasis::bold | fg(fmt::color::red),"There was some error, please try again!");
            system("PAUSE");
            void create_account(user_type user_type_t);
        }
        };
};

#endif