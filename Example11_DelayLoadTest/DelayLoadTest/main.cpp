#include <iostream>
#include <tchar.h>
#include <Windows.h>
#include <StrSafe.h>

#pragma comment(lib, "MyLib.lib")

//#include "MyDll.h"	// dll对应的那个头文件
__declspec(dllimport) int Add(int a, int b);

// 卸载需要的头文件
#include <delayimp.h>
#pragma comment(lib, "delayimp")

// 在项目属性中添加dll对应.lib路径，附加依赖项里添加dll对应的.lib文件名
// 或者 #pragma comment (lib,"D:/Project Files/MyDll/Debug/MyDll.lib")

//延迟加载DLL的名字
TCHAR g_szDelayLoadModuleName[] = TEXT("MyLib");

//延迟加载DLL的异常捕获
LONG WINAPI DelayLoadDllExceptionFilter(PEXCEPTION_POINTERS pep);

//检查是否加载
void IsModuleLoaded(PCTSTR pszModuleName)
{
	HMODULE hmod = GetModuleHandle(pszModuleName);
	//HMODULE hmod = LoadLibraryEx(pszModuleName, NULL, 0);
	char sz[100] = { 0 };
	StringCchPrintfA(sz, _countof(sz), "MyDll.dll is %S loaded.", (hmod == NULL) ? L"not" : L"");
	MessageBoxA(NULL, sz, 0, 0);
}

//延迟加载及异常捕获演示：
int main()
{
	__try
	{
		IsModuleLoaded(g_szDelayLoadModuleName);	// 还未加载
		int sum = Add(2, 43);						// 加载MyDll，调用MyDll.dll中导出的API
		printf("sum = %d", sum);					// 已加载DLL
		IsModuleLoaded(g_szDelayLoadModuleName);

		BOOL TestReturn = __FUnloadDelayLoadedDLL2("MyLib.dll");
		IsModuleLoaded(g_szDelayLoadModuleName);	// 已经卸载
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
