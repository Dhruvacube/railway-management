#ifndef HANDLER_H
#define HANDLER_H
#include <conio.h>
#include "auth/auth.h"
#include <string>
#include <fstream>
#include <iostream>
#include "../utility/constants.h"
#include <sstream>

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

string * split(string s, char del){
    stringstream ss(s);
    string word;
    string arr[20];
    int n=0;
    while (!ss.eof()) {
        getline(ss, word, del);
        arr[n] = word;
        n+=1;
    }
}

class Handler {
    Auth auth;
    public:
        Handler(){
            this->auth = Auth();
        };
        bool user_login(string user_name, string pass_word, login_type login_type_t){
            ifstream data;
            data.open("../../database/user/data.csv");
            string headers;
            getline(data,headers);
            string headers_list[7];
            int n=0;
            for (int i = 0; i < headers.size(); i++){
                if (headers[i] == ','){
                    headers_list[n] = headers.substr(n,i);
                    n+=1;
                }
            }
            data.close();
            // string name; int ph_no; string address; string emailid; string username; string password; bool admin;
            // while(in.read_row(name,ph_no,address,emailid,username,password,admin)){
            //     if (username == user_name && password == pass_word) {
            //         if (login_type_t == login_type::admin) {
            //             if (admin) {
            //                 return true;
            //             } else {
            //                 return false;
            //             }
            //         } else if (login_type_t == login_type::user) {
            //             if (admin) {
            //                 return false;
            //             } else {
            //                 return true;
            //             };
            //         };
            //     };
            // };
                return false;
        };
        void handle(login_type login_type_t) {
            string username;
            string password;
            cout << "Enter the username: "<<endl;
            cin >> username;
            cout << "Enter the password: "<<endl;
            password = HANDLER_H::takePasswdFromUser();
            if (login_type_t == login_type::admin) {
                if (this->user_login(username, password, login_type_t)) {
                    cout << "You have successfully logged in as admin!" << endl;
            } else {
                cout << "You have entered wrong credentials!" << endl;
            };
            } else if (login_type_t == login_type::user) {
                if (this->user_login(username, password, login_type_t)) {
                    cout << "You have successfully logged in as user!" << endl;
                } else {
                    cout << "You have entered wrong credentials!" << endl;
                };
            };
        };
};

#endif