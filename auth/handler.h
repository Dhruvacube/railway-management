#ifndef HANDLER_H
#define HANDLER_H
#include <conio.h>
#include "auth/auth.h"
#include <string>
#include <fstream>
#include <iostream>
#include "../utility/constants.h"
#include "../utility/fmt/core.h"

//this password input function has been copied from https://www.geeksforgeeks.org/taking-password-as-input-in-c
enum TT_Input {

	// ASCII code of backspace is 8
	BACKSPACE = 8,
	RETURN = 32
};

//this password input function has been copied from https://www.geeksforgeeks.org/taking-password-as-input-in-c
std::string takePasswdFromUser()
{
	string ipt = "";
	char ipt_ch;
	while (true) {
		ipt_ch = getch();

		if (ipt_ch < TT_Input::RETURN
			&& ipt_ch != TT_Input::BACKSPACE) {
			cout << endl;
			return ipt;
		}

		// Check whether the user
		// pressed backspace
		if (ipt_ch == TT_Input::BACKSPACE) {

			// Check if ipt is empty or not
			if (ipt.length() == 0)
				continue;
			else {

				// Removes last character
				ipt.pop_back();

				continue;
			}
		}
		ipt.push_back(ipt_ch);
	}
}

class Handler {
    public:
        bool user_login(string user_name, string pass_word, login_type login_type_t){
            ifstream data;
            data.open("../../database/user/data.txt");
            string name,address,emailid,username,password;
            int ph_no;
            bool admin;
            while (data >> name >> ph_no >> address >> emailid >> username >> password >> admin) {
                if (username == user_name && password == pass_word) {
                    if (login_type_t == login_type::admin) {
                        if (admin) {
                            data.close();
                            return true;
                        } else {
                            data.close();
                            return false;
                        }
                    } else if (login_type_t == login_type::user) {
                        if (admin) {
                            data.close();
                            return false;                            
                        } else {
                            data.close();
                            return true;
                        };
                    };
                };};

            data.close();
            return false;
        };
        void handle(login_type login_type_t) {
            system("CLS");
            string username;
            string password;
            cout << "Enter the username: "<<endl;
            cin >> username;
            cout << "Enter the password: "<<endl;
            password = HANDLER_H::takePasswdFromUser();
            if (login_type_t == login_type::admin) {
                if (this->user_login(username, password, login_type_t)) {
                    fmt::print(fmt::emphasis::bold ,"\nYou have successfully logged in as admin!\n");
                    system("PAUSE");
                    return;
            } else {
                fmt::print(fmt::emphasis::bold | fg(fmt::color::red),"\nYou have entered wrong credentials or something is wrong or the user doesn't exists!\n");
            };
            } else if (login_type_t == login_type::user) {
                if (this->user_login(username, password, login_type_t)) {
                    fmt::print(fmt::emphasis::bold ,"\nYou have successfully logged in as user!\n");
                    return;
                } else {
                    fmt::print(fmt::emphasis::bold | fg(fmt::color::red),"\nYou have entered wrong credentials or something is wrong or the user doesn't exists!\n");
                };
            };
            system("PAUSE");
            this->handle(login_type_t);
        };
};

#endif