// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem

#include <iostream>
#include <math.h>
using namespace std;

bool isBeautifulday(int x, int k)
{
    int different;
    int n = log10(x);
    int reverse = 0;
    for (int i = 0; i <= n; i++)
    {
        int temp = (int)(x / (pow(10, i))) % 10;
        reverse += temp * pow(10, n - i);
    }
    different = (x - reverse > 0 ? x - reverse : reverse - x);
    if (different % k == 0)
        return true;
    return false;
}

int main()
{
    int i, j, k;
    int count = 0;
    cin >> i >> j >> k;
    for (int a = i; a <= j; a++)
    {
        if (isBeautifulday(a, k))
            count++;
    }
    cout << count;
}