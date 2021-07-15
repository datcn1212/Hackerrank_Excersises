#include <windows.h>
#include <stdio.h>

#define Max 5000000
#define numThreads 10

int Counter = 0;

void counterThread(){
	int i;
	int temp;
	for(i=0; i < Max; i++) {
		temp = Counter;
		temp = temp + 1;  
		Counter = temp;
	}
}

int main(){
	HANDLE hThreads[numThreads];
	DWORD Id;
	int i;
	for(i=0; i < numThreads;i++)
		hThreads[i] = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)counterThread, NULL,0,&Id);
	WaitForMultipleObjects(numThreads,hThreads,TRUE,INFINITE);
	printf("\nKet qua : %d \n", Counter);
	getch();
	return 0;
}

