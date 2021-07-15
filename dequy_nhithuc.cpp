#include <iostream>
using namespace std;
// Calculate C(n,k)
int C1(int n, int k)
{
    if (k == n || k == 0)
        return 1;
    return C1(n - 1, k) + C1(n - 1, k - 1);
}
int C2(int n, int k);
int n = 10, k = 5;
int D[10][5];
int main()
{
    int i,j;
    for (i = 0; i < n; i++)
        for (j = 0; j < k; j++)
        {
            if (j == i || j == 0)
                D[i][j] = 1;
            else
                D[i][j] = 0;
        }

    cout << C1(n, k) << endl
         << C2(n, k);
}
int C2(int n, int k)
{
    if (D[n][k] > 0)
        return D[n][k];
    else
    {
        D[n][k] = C2(n - 1, k - 1) + C2(n - 1, k);
        return D[n][k];
    }
}