#include <auth.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include "utility/constants.h"
using namespace std;

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
    Auth auth;
    public:
        Handler()
        {
            this->auth = Auth();
        }

        void handle(login_type login_type_t) {
            string username;
			string password;
			cout << "Enter the username: "<<endl;
			cin >> username;
			cout << "Enter the password: "<<endl;
			password = takePasswdFromUser();
			if (login_type_t == login_type::admin) {
				if (this->auth.admin_login(username, password)) {
					cout << "You have successfully logged in as admin!" << endl;
				} else {
					cout << "You have entered wrong credentials!" << endl;
				}
			} else if (login_type_t == login_type::user) {
				if (this->auth.user_login(username, password)) {
					cout << "You have successfully logged in as user!" << endl;
				} else {
					cout << "You have entered wrong credentials!" << endl;
				}
			}
        }


};