// https://www.hackerrank.com/challenges/30-2d-arrays/problem
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a[6][6];
    vector<int> v;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            cin >> a[i][j];
    for (int x = 1; x < 5; x++)
    {
        for (int y = 1; y < 5; y++)
        {
            int sum = a[x][y] + a[x - 1][y - 1] + a[x - 1][y] + a[x - 1][y + 1] + a[x + 1][y - 1] + a[x + 1][y] + a[x + 1][y + 1];
            v.push_back(sum);
        }
    }

    int max = v.at(0);
    for (int k = 0; k < v.size(); k++)
    {
        if (v.at(k) > max)
            max = v.at(k);
    }
    cout << max;
}