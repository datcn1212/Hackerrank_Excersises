// https://www.hackerrank.com/challenges/electronics-shop/problem
#include<iostream>
#include<vector>
using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    /*
     * Write your code here.
     */
    int sum = 0;
    for(int i = 0; i < keyboards.size(); i++){
        if(keyboards.at(i) <= b){
            for(int j = 0; j < drives.size(); j++){
                if(drives.at(j) <= b){
                    if(keyboards.at(i) + drives.at(j) > sum && keyboards.at(i) + drives.at(j) <= b) sum = keyboards.at(i) + drives.at(j);
                }
            }
        }
    }
    if(sum == 0) return -1;
    return sum;
}

int main(){
    vector<int> keyboard,drives;
    int b, m, n;
    cin >> b >> m >> n;
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        keyboard.push_back(temp);
    }
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        drives.push_back(temp);
    }
    cout << getMoneySpent(keyboard, drives, b);
}