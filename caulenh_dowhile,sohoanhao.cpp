#include <stdio.h> //standard input output
#include <conio.h> //thu vien chua lenh getch
// viet chuong trinh nhap vao so n kiem tra xem co phai so hoan hao hay khong?


int main()
{
int n,i,t=0;
char c;

do{
	printf("nhap vao so n: \n "); scanf("%d",&n);
	printf("cac uoc so duong cua n la: \n");
	for (i=1;i<n;i++)
	 if(n%i==0) {printf("%d \n",i); t=t+i;}
	if (t==n) printf ("n la so hoan hao \n");
	else printf("n khong la so hoan hao \n");
	
	printf("Ban co muon tiep tuc khong? (c/k) ");
	fflush(stdin); scanf("%c",&c);	
   } while ((c!='k')&&(c!='K'));  // cau lenh do...while la phai co dau ; o cuoi while


getch();
}
