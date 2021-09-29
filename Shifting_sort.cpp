//https://codeforces.com/contest/1579/problem/B
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int shift1(int a[], int n){
    if(n==1) return 0;
    int sum = 0;
    int max = a[n-1];
    int index = n;
    for(int i = 0; i < n-1; i++){
        if(a[i] > max){
            max = a[i];
            index = i+1;
        } 
    }
    if(index != n){
        for(int i = index-1; i < n-1; i++){
            a[i] = a[i+1];
        }
        sum++;
        return shift1(a,n-1)+1;
    }
    return shift1(a,n-1);
}

void shift(int a[], int n){
    if(n==1) return;
    int sum = 0;
    int max = a[n-1];
    int index = n;
    for(int i = 0; i < n; i++){
        if(a[i] > max){
            max = a[i];
            index = i+1;
        } 
    }
    if(index != n){
        for(int i = index-1; i < n-1; i++){
            a[i] = a[i+1];
        }
        cout << index <<" "<< n << " "<< 1<< endl;
    }
    return shift(a,n-1);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int a[n], b[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        
        cout << shift1(a,n) << endl;
        shift(b,n);
    }
}