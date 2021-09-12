#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <math.h>

using namespace std;

const int INFO_BUFFER_SIZE = 32767;
const int WIDTH = 7;

int main()
{
  TCHAR infoBuf[INFO_BUFFER_SIZE], lpTempPathBuffer[MAX_PATH];
  SYSTEM_INFO siSysInfo;
  MEMORYSTATUSEX statex;

  statex.dwLength = sizeof(statex);

  // 1
  cout << "1)" << endl;
  if (GetWindowsDirectory(infoBuf, INFO_BUFFER_SIZE))
  {
    cout << "Windows directory: " << infoBuf << endl;
  }

  if (GetTempPath(MAX_PATH, lpTempPathBuffer))
  {
    cout << "Windows temp files directiry: " << lpTempPathBuffer << endl;
  }

  // 2
  cout << "2)" << endl;
  GetSystemInfo(&siSysInfo);

  cout << "Number of processors: " << siSysInfo.dwNumberOfProcessors << endl;
  cout << "Processor type: " << siSysInfo.dwProcessorType << endl;
  cout << "Minimum app adress: " << siSysInfo.lpMinimumApplicationAddress << endl;
  cout << "Maximum app adress: " << siSysInfo.lpMaximumApplicationAddress << endl;

  // 3
  cout << "3)" << endl;
  GlobalMemoryStatusEx(&statex);

  int del = pow(2, 20);
  // _tprintf(TEXT("Total physics memory in KB: %*I64d \n"), WIDTH, statex.ullTotalPhys / 1024 );
  // cout << "Pow: " << pow(2, 10) << endl;
  cout << "Total physical memory in MB: " << statex.ullTotalPhys / del << endl;
  cout << "Free physical memory in MB: " << statex.ullAvailPhys / del << endl;
  cout << "Total virtual memory in MB: " << statex.ullTotalVirtual / del << endl;
  cout << "Free virtual memory in MB: " << statex.ullAvailVirtual / del << endl;
}