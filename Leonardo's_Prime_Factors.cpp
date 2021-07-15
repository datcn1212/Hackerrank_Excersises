//https://www.hackerrank.com/challenges/leonardo-and-prime/problem

#include <iostream>
using namespace std;
int prime[15] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47};

int result(long long int n){
    long long int mul = 1;
    int sum = 0;
    for(int i = 0; i < 15; i++){
        mul = mul*prime[i];
        if(mul <= n) sum++;
    }
    return sum;
}

int main()
{
    int q; // number of test cases
    long long int a[100000]; //test cases;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> a[i];
    }
    for(int i = 0; i < q; i++){
        cout << result(a[i]) << endl;
    }
    return 0;
}
