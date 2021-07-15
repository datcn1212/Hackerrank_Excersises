#include <windows.h>
#include <stdio.h>
#include <time.h> 
int main()
{
  STARTUPINFO si;
  PROCESS_INFORMATION  pi;
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);

  printf("Parent process isrunning ...\n\n");  	
  sleep(2000);//Waiting 2000ms and then create a process
  printf("Fork a child process ...\n\n");  
  if(! CreateProcess("Child.exe",NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi))
     printf("\nSorry! CreateProcess() failed.\n\n");
  else{
    printf("Child is running...\n\n");
    printf("Parent is waiting for child  process in 5000ms\n\n"); 
    WaitForSingleObject(pi.hProcess,7000);//INFINITE  
    printf("Kill the child process now\n");
    TerminateProcess(pi.hProcess, 0);
    printf("Parent ends\n");
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
   return 0;
  }
}
