// https://www.hackerrank.com/challenges/30-review-loop/problem
#include <string>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(); // xoa bo dem truoc khi nhap getline
    string s[10];
    for(int i = 0; i < T; i++){
        getline(cin, s[i]);
    }
    for(int j = 0; j < T; j++){
        int n = s[j].length();
        string s1, s2;
        for(int k = 0; k < n; k++){
            if(k%2 == 1) s1.push_back(s[j][k]);
            else s2.push_back(s[j][k]);
        }
        cout << s2 << " " << s1 << endl;
    }
}
