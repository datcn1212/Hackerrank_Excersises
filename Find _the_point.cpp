//https://www.hackerrank.com/challenges/find-point/problem
#include<iostream>
#include<vector>
using namespace std;

typedef struct toado{
       int x; //hoanh do
       int y; //tung do
}toado;

toado reflection(toado p1, toado p2){
    toado p3;
    p3.x = 2*p2.x - p1.x;
    p3.y = 2*p2.y - p1.y;
    return p3;
}   
   
int main(){
   vector<toado> point;
   int n;
   cin >> n;
   for(int i = 0; i < n; i++){
       toado point1;
       toado point2;
       cin >> point1.x >> point1.y >> point2.x >> point2.y;
       point.push_back(reflection(point1, point2));
   }
   for(int j = 0; j < n; j++){
       cout << point.at(j).x << " " << point.at(j).y << endl;
   }
}
