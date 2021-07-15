#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tu, mau, t, m, tg;

    printf("\n nhap tu so ");
    scanf("%d", &tu);
    printf("\n nhap mau so ");
    scanf("%d", &mau);
    tg = tu % mau;
    t = tu;
    m = mau;
    while (tg != 0)
    {
        tu = mau;
        mau = tg;
        tg = tu % mau;
    }

    printf("ps toi gian la %d / %d ", t / mau, m / mau);

    return 0;
}
