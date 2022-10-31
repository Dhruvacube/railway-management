#include <string>
#include <fstream>
#include <iostream>
#include <iostream>
#include <sstream>
#include<array> 


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
    string headers_list[7];
    int n=0;
    for (int i = 0; i < headers.size(); i++){
        if (headers[i] == ','){
            headers_list[n] = headers.substr(n,i);
            cout<<n<<","<<i<<","<<headers.substr(n,i)<<endl;
            n=i;
        }
    }
    data.close();
    cout<<"hey";
    cout<<sizeof(headers_list)<<endl;
    return 0;
}