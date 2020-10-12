#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int main(){
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb=sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(NULL,"C:\\WINDOWS\\notepad.exe",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)){
        fprintf(stderr, "Create Process Failed");
        return -1;
    }
    WaitForSingleObject(pi.hProcess,INFINITE);
    printf("Child Complete");

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
//C:\\WINDOWS\\system32\\mspaint.exe
