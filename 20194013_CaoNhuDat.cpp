#include <stdio.h>
#include<limits.h>
int n,sum,maxsum;
int a[1000],i,j,k;
int max (int a, int b)
{
	if (a<b) return b;
	else return a;
}
int maxsub1()
	{
     maxsum=INT_MIN;
     for ( i=0;i<n;++i){
        for ( j=i;j<n;++j){
            sum=0;
            for ( k=i;k<=j;++k){
                sum=sum+a[k];
            }
            if (sum > maxsum) maxsum=sum;
        }
    }
    printf("%d",maxsum);
}
int maxsub2(){
    maxsum=INT_MIN;
    for ( i=0;i<n;++i){
        sum=0;
        for (j=i;j<n;++j){
            sum=sum+a[j];
            if (sum> maxsum) maxsum=sum;
        }
    }
    printf("%d",maxsum);
}
int maxr(int a[], int low, int high){
    maxsum=INT_MIN; sum=0;
    for (i=low;i<=high;i++){
        sum+=a[i];
        if (maxsum<sum) maxsum=sum;
    }
    return maxsum;
}
int maxl(int a[], int low, int high){
    maxsum=INT_MIN; sum=0;
    for (i=high;i>=low;i--){
        sum+=a[i];
        if (maxsum<sum) maxsum=sum;
    }
    return maxsum;
}
int maxsub3(int a[],int low, int high){
    if (low==high) return a[low];
    int mid=(low+high)/2;
    int ml=maxsub3(a,low,mid);
    int mr=maxsub3(a,mid+1,high);
    int mm=maxl(a,low,mid)+maxr(a,mid+1,high);
    int m=max(ml,mr);  m=max(m,mm);
    return m;

}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",a+i);
    maxsub1();
    printf("\n");
    maxsub2();
    printf("\n");
    printf("%d",maxsub3(a,0,n-1));
}





