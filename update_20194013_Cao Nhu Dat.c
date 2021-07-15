#include <stdio.h>
#include <limits.h>
int n, maxsum, sum;
int a[1000], i, j, k;
int x = 0, y = 0;

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int maxsub1() // duyet toan bo
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
            {
                maxsum = sum;
                x = i;
                y = j;
            }
        }
    }
    printf("maxsub1 = %d, day con la: ", maxsum);
    for (i = x; i <= y; i++)
        printf("%d ", a[i]);
}

int maxsub2() //duyet toan bo co cai tien
{
    maxsum = INT_MIN;
    for (i = 0; i < n; ++i)
    {
        sum = 0;
        for (j = i; j < n; ++j)
        {
            sum = sum + a[j];
            if (sum > maxsum)
            {
                maxsum = sum;
                x = i;
                y = j;
            }
        }
    }
    printf("maxsub2 = %d, day con la: ", maxsum);
    for (i = x; i <= y; i++)
        printf("%d ", a[i]);
}

struct MS
{
    int weight;
    int x_inx;
    int y_inx;
};

struct MS ml(int a[], int low, int high)
{
    int maxsum = INT_MIN, sum = 0;
    struct MS max;
    int k;
    for (k = high; k >= low; k--)
    {
        sum += a[k];
        if (sum > maxsum)
        {
            maxsum = sum;
            max.x_inx = k;
        }
    }
    max.weight = maxsum;
    return max;
}

struct MS mr(int a[], int low, int high)
{
    int maxsum = INT_MIN, sum = 0;
    struct MS max;
    int k;
    for (k = low; k <= high; k++)
    {
        sum += a[k];
        if (sum > maxsum)
        {
            maxsum = sum;
            max.y_inx = k;
        }
    }
    max.weight = maxsum;
    return max;
}

struct MS maxsub3(int a[], int low, int high)
{
    struct MS max;
    if (low == high)
    {
        max.weight = a[low];
        max.x_inx = low;
        max.y_inx = low;
        return max;
    }
    else
    {
        int mid = (low + high) / 2;
        struct MS w1 = maxsub3(a, low, mid);
        struct MS w2 = maxsub3(a, mid + 1, high);
        int u3 = ml(a, low, mid).weight + mr(a, mid + 1, high).weight;
        if (u3 > w1.weight && u3 > w2.weight)
        {
            max.weight = u3;
            max.x_inx = ml(a, low, mid).x_inx;
            max.y_inx = mr(a, mid + 1, high).y_inx;
        }
        else if (w1.weight > w2.weight)
        {
            max.weight = w1.weight;
            max.x_inx = w1.x_inx;
            max.y_inx = w1.y_inx;
        }
        else
        {
            max.weight = w2.weight;
            max.x_inx = w2.x_inx;
            max.y_inx = w2.y_inx;
        }
        return max;
    }
}

int maxsub4() // quy hoach dong
{
    int u = a[0], maxsum = INT_MIN;
    for (i = 1; i < n; ++i)
    {
        u = max(a[i], u + a[i]);
        if (maxsum < u)
        {
            maxsum = u;
            if (u == a[i])
            {
                x = i;
                y = i;
            }
            else
            {
                y = i;
            }
        }
    }
    printf("maxsub4 = %d, day con la: ", maxsum);
    for (i = x; i <= y; i++)
        printf("%d ", a[i]);
}

int main()
{
    printf("Nhap vao n: ");
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", a + i);
    maxsub1();
    printf("\n");
    maxsub2();
    printf("\n");
    printf("maxsub3 = %d, day con la: ", maxsub3(a, 0, n - 1).weight);
    for (i = maxsub3(a, 0, n - 1).x_inx; i <= maxsub3(a, 0, n - 1).y_inx; i++)
        printf("%d ", a[i]);
    printf("\n");
    maxsub4();
}