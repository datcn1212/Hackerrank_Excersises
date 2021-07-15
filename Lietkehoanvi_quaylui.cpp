#include<iostream>
using namespace std;
int n = 4;
int a[100];
int count = 0;
void ghinhan(){
	count ++;
	cout << "hoan vi thu" <<count<<" la: ";
	for (int i = 1; i <= n; i++){
		cout << a[i];
	}
}
bool test(int j, int k) // kiem tra xem j co trong S[k] chua
{
	for(int i=1; i<=k-1; i++)
		if(a[i]==j) return 0;
	return 1;
}
void Try(int k){
	for(int i = 1; i <= n; i++)
	if(test(i,k)){
		a[k] = i;
		if(k==n) ghinhan();
		else Try(k+1);
	}
}
int main()
{
	Try(1);
}
