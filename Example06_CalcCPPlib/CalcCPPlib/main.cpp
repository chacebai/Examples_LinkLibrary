#include <iostream>
#include <windows.h>

typedef int(*ADD)(int m, int n);
typedef int(*SUB)(int m, int n);
typedef int(*MUL)(int m, int n);

int main()
{
	HINSTANCE hDll = LoadLibrary(TEXT("CalcCPPlib_dynamic.dll"));
	std::cout << "hDll:" << hDll << std::endl;

	// fist way use GetProcAddress
	ADD myAdd = (ADD)GetProcAddress(hDll, "dll_add");
	std::cout << "myAdd:" << myAdd << std::endl;
	int sum = myAdd(5, 3);

	SUB mySub = (SUB)GetProcAddress(hDll, "dll_sub");
	std::cout << "mySub:" << myAdd << std::endl;
	int sub = mySub(5, 3);

	// fist way use dll_mul function of export
	MUL myMul = (MUL)GetProcAddress(hDll, "?dll_mul@@YAHHH@Z");
	std::cout << "myMul:" << myAdd << std::endl;
	int mul = myMul(5, 3);

	FreeLibrary(hDll);

	// printf("sum=%d, sub=%d, mul=%d\n", sum, sub, mul);
	std::cout << "sum=" << sum << ", sub=" << sub << ", mul=" << mul << std::endl;
	system("pause");
	return 0;
}