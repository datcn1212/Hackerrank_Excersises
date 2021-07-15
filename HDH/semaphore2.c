#include <windows.h>
#include <stdio.h>
#define Max 20000
#define numThreads 5
int Counter;
HANDLE S;
void counterThread(){
	int i;
	for(i=0; i < Max; i++) {
		WaitForSingleObject(S,INFINITE); //P(S)
		Counter++;
		ReleaseSemaphore(S,1,NULL); //V(S)
	}
}
int main(){
HANDLE hThreads[numThreads];
DWORD Id;
int i;
S = CreateSemaphore(NULL,1,1,NULL);
for(i=0; i < numThreads;i++)
	hThreads[i] = CreateThread(NULL,0, (LPTHREAD_START_ROUTINE)counterThread,NULL,0,&Id);
WaitForMultipleObjects(numThreads, hThreads, TRUE, INFINITE);
printf("\nKet qua : %d\n", Counter);
return 0;
} 
