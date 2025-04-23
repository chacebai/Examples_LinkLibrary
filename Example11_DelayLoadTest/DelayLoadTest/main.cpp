#include <iostream>
#include <tchar.h>
#include <Windows.h>
#include <StrSafe.h>

#pragma comment(lib, "MyLib.lib")

//#include "MyDll.h"	// dll��Ӧ���Ǹ�ͷ�ļ�
__declspec(dllimport) int Add(int a, int b);

// ж����Ҫ��ͷ�ļ�
#include <delayimp.h>
#pragma comment(lib, "delayimp")

// ����Ŀ���������dll��Ӧ.lib·�������������������dll��Ӧ��.lib�ļ���
// ���� #pragma comment (lib,"D:/Project Files/MyDll/Debug/MyDll.lib")

//�ӳټ���DLL������
TCHAR g_szDelayLoadModuleName[] = TEXT("MyLib");

//�ӳټ���DLL���쳣����
LONG WINAPI DelayLoadDllExceptionFilter(PEXCEPTION_POINTERS pep);

//����Ƿ����
void IsModuleLoaded(PCTSTR pszModuleName)
{
	HMODULE hmod = GetModuleHandle(pszModuleName);
	//HMODULE hmod = LoadLibraryEx(pszModuleName, NULL, 0);
	char sz[100] = { 0 };
	StringCchPrintfA(sz, _countof(sz), "MyDll.dll is %S loaded.", (hmod == NULL) ? L"not" : L"");
	MessageBoxA(NULL, sz, 0, 0);
}

//�ӳټ��ؼ��쳣������ʾ��
int main()
{
	__try
	{
		IsModuleLoaded(g_szDelayLoadModuleName);	// ��δ����
		int sum = Add(2, 43);						// ����MyDll������MyDll.dll�е�����API
		printf("sum = %d", sum);					// �Ѽ���DLL
		IsModuleLoaded(g_szDelayLoadModuleName);

		BOOL TestReturn = __FUnloadDelayLoadedDLL2("MyLib.dll");
		IsModuleLoaded(g_szDelayLoadModuleName);	// �Ѿ�ж��
	}
	__except (DelayLoadDllExceptionFilter(GetExceptionInformation()))
	{
	}
	// we can do otherthing ...
}

LONG WINAPI DelayLoadDllExceptionFilter(PEXCEPTION_POINTERS pep)
{
	return -1;
}
