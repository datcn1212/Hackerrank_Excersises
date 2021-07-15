// https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup&h_r=next-challenge&h_v=zen
#include <iostream>
using namespace std;

int countingValleys(int steps, string path)
{
    int sum = 0;
    int a[1000];
    int index = 0;
    for (int i = 0; i < steps; i++)
    {
        if (path[i] == 'U')
            a[index] = 1;
        else
            a[index] = -1;
        index++;
    }
    int b[1000];
    b[0] = a[0];
    for (int k = 1; k < steps; k++)
    {
        b[k] = a[k] + b[k - 1];
    }
    for (int j = 1; j < steps; j++)
    {
        if (b[j] == 0 && b[j - 1] == -1)
            sum++;
    }
    return sum;
}
int main()
{
    cout << countingValleys(12, "DDUUUDUDUDDU");
}
