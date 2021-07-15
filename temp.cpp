#include<iostream>
#include<string>
using namespace std;

string timeConversion(string s) {
    string temp = "00:00:00";
    if(s.at(8)=='A'){
        if(s.at(1)=='2'){
            temp = strcat("00" ,s.substr(2,6));
        }
        else temp = s.substr(0,8);
    }
    else{
        if(s.at(1)=='2') temp = s.substr(0,8);
        else{
            temp = strcat((string)((int)(s.substr(0,2) + 12)), s.substr(2,6));
        }
    }
    return temp;
}
int main(){
    cout << timeConversion("12:00:00AM");
}
