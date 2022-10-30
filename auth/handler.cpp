#include <format>
#include <auth.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;

enum TT_Input {

	// ASCII code of backspace is 8
	BACKSPACE = 8,
	RETURN = 32
};

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

        void handle() {
            this->auth.login("username", "password");
        }


};