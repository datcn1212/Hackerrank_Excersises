#include<stdio.h>

int M[100],n,i,j;
int main()
{
do{
	printf("nhap so phan tu cua mang: ");
	scanf("%d",&n);
  } while (n<1||n>100);
for (i=0;i<n;i++) {printf("\n M[%d]= ",i);scanf("%d",&M[i]);}
for (i=0;i<n;i++) printf("\n M[%d] = %d",i,M[i]);
////sap xep thu tu tang dan cac phan tu cua mang
int a;
printf("\n");
for(i=0;i<n;i++)
    for(j=i+1;j<n;j++) if(M[i]>M[j]) {a=M[i];M[i]=M[j];M[j]=a;}
printf("thu tu tu nho den lon(bubble sort): \n");
for(i=0;i<n;i++)  printf("   %d ",M[i]);
//selection sort
int min,k;
printf("\n");
for(i=0;i<n;i++)
    {min=i;
     for(j=i+1;j<n;j++)
     if(M[min]>M[j]) min=j;
	k=M[i];M[i]=M[min];M[min]=k;
	}
printf("thu tu tu nho den lon(selection sort): \n");
for (i=0;i<n;i++) printf("    %d",M[i]);
return 0;
}
