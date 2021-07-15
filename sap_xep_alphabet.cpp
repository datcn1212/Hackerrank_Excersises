#include<stdio.h>
#include<string.h>
#include<conio.h>

int main()
{
	int n;
	do{
		printf(" Nhap n: \n");
		scanf("%d",&n);	
	} while (n<=0||n>9);
	char a[10][50];
	int i,j;
	for(i=0;i<n;i++) 
	{
		printf("nhap ho va ten hoc sinh thu %d: ",i+1);
		fflush(stdin);
		gets(a[i]);
		if(a[i][0]=='\0') break;
	}
	n=i;
	// sap xep selection sort
	char tg[50];
	int min;
	for ( i=0; i<n; i++ ) 
	{
		min=i;
		for (j=i+1;j<n;j++)
		if (strcmp(a[min],a[j])>0) min=j;
		if (min != i) 
		{
			strcpy(tg,a[i]);
			strcpy(a[i],a[min]);
			strcpy(a[min],tg);
		}
	}
	printf("\n Danh sach sau khi sap xep la: \n");
	for ( i=0; i<n; i++ ) printf("%s\n",a[i]);
}
