#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
char s[10][30];//10 la so ten, 30 la do dai max cua mot ten
int i,j;
char a[10];
for (i=0;i<10;i++)
   { printf("\n nhap ten ban thu %d:",i+1);
    fflush(stdin); gets(s[i]);
    }
for(i=0;i<10;i++)
for(j=i+1;j<10;j++)
  if (strcmp(s[i],s[j])>0) { strcpy(a,s[i]);strcpy(s[i],s[j]);strcpy(s[j],a);}
printf("\n thu tu ten la: \n");
for(i=0;i<10;i++) printf("\n %s",s[i]);
	
	}
	
