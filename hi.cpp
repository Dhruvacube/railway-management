#include <string>
#include <fstream>
#include <iostream>
#include <iostream>
#include <sstream>

using namespace std;

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

int main(){
    ifstream data;
    data.open("database/user/data.csv");
    string headers;
    getline(data,headers);
    string *headers_list;
    headers_list = split(headers, ','); 
    cout<<headers_list[1]<<endl;
    data.close();
    return 0;
}