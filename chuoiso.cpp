#include<stdio.h>
#include<math.h>
int main()
{
long long i,n;
 long double s=0;
printf("nhap vao n: \n");
scanf("%d",&n);
for (i=2; i<=n; i++)
s+=(i*sin(exp(log(i)/3)+1))/sqrt(exp(log(i)/3)+1);
printf("%f",s);

}
