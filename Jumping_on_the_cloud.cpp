// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
#include<iostream>
#include<vector>
using namespace std;

int jumpingOnClouds(vector<int> c) {
    int temp = 0;
    int result = 0;
    for(int i = 0; i < c.size(); i++){
        if(c.at(i) == 0) temp++;
        if(c.at(i) == 1){
            result = result + 1 + (int)temp/2;
            temp = 0;
        }
        if(i == c.size() - 1) result += (int)temp/2;
    }
    return result;
}

int main(){
    vector<int> c;
    c.push_back(0);
    c.push_back(1);
    c.push_back(0);
    c.push_back(0);
    c.push_back(0);
    c.push_back(1);
    c.push_back(0);
    cout << jumpingOnClouds(c);
}