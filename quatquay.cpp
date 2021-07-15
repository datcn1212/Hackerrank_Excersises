#include <stdio.h>
#include <conio.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int n,t=1,l;
	printf("Nhap so nguyen N: ");
	scanf("%d",&n);
	printf("Nhap ki tu: ");
	char x;scanf(" ");
	scanf("%c",&x);
	
	printf("\nHinh vuong:\n");
	int i,j;
	for (i = 1 ; i <= n ; ++i) {
		for (j = 1 ; j <= n ; ++ j) printf("%c ",x);printf("\n");
	};Sleep(6666);system("cls");
	printf("\nHinh canh quat dang quay:\n\n");
	for (t=1 ; t>0 ; ++t)
	if (t%2==0){
	for (i = 1 ; i <= 2*(2*n-1) ; ++ i) {
		for (j = 1 ; j <= 2*(2*n-1) ; ++ j) {
			if (i <= (2*n-1) && j <= (2*n-1)) 
				if ((i+j)%2==0 && j+i>=2*n && j>=i) printf("%c ",x); else printf("  ");
			if (i <= (2*n-1) && j > (2*n-1))
				if ((i+j-2*n+1)%2==0 && j+i-2*n+1>=2*n && j-2*n+1<=i) printf("%c ",x); else printf("  ");
			if (i > (2*n-1) && j > (2*n-1)) 
				if ((i+j)%2==0 && j+i-2*(2*n-1)<=2*n && j<=i) printf("%c ",x); else printf("  ");;
			if (i > (2*n-1) && j <= (2*n-1)) 
				if ((i+j-2*n+1)%2==0 && j+i-2*n+1<=2*n && j>=i-2*n+1) printf("%c ",x); else printf("  ");;
					} 
		printf("\n");
		}Sleep(80);system("cls");printf("\nHinh canh quat:\n\n");}else{
	for (i = 1 ; i <= 2*n ; ++ i) {
		for (l=1; l<=n-3 ; ++l) printf(" ");
		for (j = 1 ; j <= 2*n ; ++ j) {
			if (i <= n && j <= n) 
				if (i >= j) printf("  %c",x); else printf("   ");
			if (i <= n && j > n)
				if (j-n <= n-i+1) printf(" %c ",x); else printf("   ");
			if (i > n && j >n) 
				if (j >= i) printf(" %c ",x); else printf("   ");
			if (i > n && j <= n) 
				if (j >= 2*n-i+1) printf("  %c",x); else printf("   ");
		} 
		if(i==n) printf("\n"); else printf("\n\n");
	}Sleep(80);system("cls");printf("\nHinh canh quat:\n\n");}
	getch();
}
