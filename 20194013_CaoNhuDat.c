#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
int n, sum, maxsum;
int a[100000000], i, j, k;
int max(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}
int maxsub1()
{
    maxsum = INT_MIN;
    for (i = 0; i < n; ++i)
    {
        for (j = i; j < n; ++j)
        {
            sum = 0;
            for (k = i; k <= j; ++k)
            {
                sum = sum + a[k];
            }
            if (sum > maxsum)
                maxsum = sum;
        }
    }
    printf("maxsub1 = %d", maxsum);
}
int maxsub2()
{
    maxsum = INT_MIN;
    for (i = 0; i < n; ++i)
    {
        sum = 0;
        for (j = i; j < n; ++j)
        {
            sum = sum + a[j];
            if (sum > maxsum)
                maxsum = sum;
        }
    }
    printf("maxsub2 = %d", maxsum);
}
int maxr(int a[], int low, int high)
{
    maxsum = INT_MIN;
    sum = 0;
    for (i = low; i <= high; i++)
    {
        sum += a[i];
        if (maxsum < sum)
            maxsum = sum;
    }
    return maxsum;
}
int maxl(int a[], int low, int high)
{
    maxsum = INT_MIN;
    sum = 0;
    for (i = high; i >= low; i--)
    {
        sum += a[i];
        if (maxsum < sum)
            maxsum = sum;
    }
    return maxsum;
}
int maxsub3(int a[], int low, int high)
{
    if (low == high)
        return a[low];
    int mid = (low + high) / 2;
    int ml = maxsub3(a, low, mid);
    int mr = maxsub3(a, mid + 1, high);
    int mm = maxl(a, low, mid) + maxr(a, mid + 1, high);
    int m = max(ml, mr);
    m = max(m, mm);
    return m;
}
int maxsub4()
{
    int smax = a[0];
    int u = a[0];
    for (i = 1; i < n; ++i)
    {
        u = max(a[i], u + a[i]);
        smax = max(smax, u);
    }
    return smax;
}
int main()
{
    for (i = 0; i < n; ++i)
        scanf("%d", a + i);
    scanf("%d", &n);

    srand(time(0));
    for (i = 0; i < n; i++)
        a[i] = rand() % 100 - 40;

    // clock_t t1 = clock();
    // maxsub1();
    // clock_t t2 = clock();
    // printf("\n");
    // printf("Time to excute: %lf \n",(t2-t1)/(double)CLOCKS_PER_SEC);

    clock_t t3 = clock();
    maxsub2();
    clock_t t4 = clock();
    printf("\n");
    printf("Time to excute: %lf \n", (t4 - t3) / (double)CLOCKS_PER_SEC);

    clock_t t5 = clock();
    printf("maxsub3 = %d\n", maxsub3(a, 0, n - 1));
    clock_t t6 = clock();
    printf("Time to excute: %lf \n", (t6 - t5) / (double)CLOCKS_PER_SEC);

    clock_t t7 = clock();
    printf("maxsub4 = %d\n", maxsub4());
    clock_t t8 = clock();
    printf("Time to excute: %lf \n", (t8 - t7) / (double)CLOCKS_PER_SEC);
}
