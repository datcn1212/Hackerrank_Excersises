#include <windows.h>
#include <stdio.h>

void ThreadRoutine(int  *n){
	printf("My argument is %d\n",  *n);
}

int main(){
	int i, P[15];
	HANDLE hHandles[50];
	DWORD ThreadId;
	
	for (i=0;i < 15;i++) {
		P[i] = i;
		hHandles[i] = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadRoutine, &P[i],0,&ThreadId);
		printf("Thread %d was created\n",ThreadId);
	}

	for (i=0;i < 15;i++) 
		WaitForSingleObject(hHandles[i],INFINITE);
getch();
	return 0;
}

