#include <windows.h>
#include <stdio.h>
int x = 0, y = 1;
HANDLE S;
void T1();
void T2();
int main(){
HANDLE h1, h2;
DWORD ThreadId;
S = CreateSemaphore( NULL,0, 1,NULL);
h1 = CreateThread(NULL,0,T1, NULL,0,&ThreadId);
h2 = CreateThread(NULL,0,T2, NULL,0,&ThreadId);
getch();
return 0;
}
void T1(){
	while(1){
		WaitForSingleObject(S,INFINITE);
		x = y + 1;
		ReleaseSemaphore(S,1,NULL);
		printf("%4d",x);
	}
}
void T2(){
	while(1){
		y = 2;
		//y = 2 * y;  print: 5
		ReleaseSemaphore(S,1,NULL);
		WaitForSingleObject(S,INFINITE);
		y = 2 * y;  //print: 3
	}
}
