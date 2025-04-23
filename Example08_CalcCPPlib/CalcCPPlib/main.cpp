#include <iostream>
#include <windows.h>
// 卸载需要的头文件
#include <delayimp.h>
#pragma comment(lib, "delayimp")

//#pragma comment(lib, "D:/code/VS2022/CalcCPPlib/x64/Debug/CalcCPPlib_dynamic.lib")


typedef int(*ADD)(int m, int n);
typedef int(*SUB)(int m, int n);
typedef int(*MUL)(int m, int n);

class IMath {
public:
	virtual int class_dll_add(int add1, int add2) = 0;
	virtual int class_dll_sub(int sub1, int sub2) = 0;
	virtual int class_dll_mul(int mul1, int mul2) = 0;
};
class CMath
{
public:
	int class_dll_add(int add1, int add2);
	int class_dll_sub(int sub1, int sub2);
	int class_dll_mul(int mul1, int mul2);
public:
	int key = 10;
	long value = 20;
};
typedef IMath* (*CreateIMathObjectFactory)();
typedef CMath* (*CreateCMathObjectFactory)();

int main()
{
	while (1)
	{
		{

			HINSTANCE hDll = LoadLibrary(TEXT("CalcCPPlib_dynamic.dll"));
			//HMODULE hDll = GetModuleHandle(L"CalcCPPlib_dynamic.dll");
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

			// fist way use dll_mul function of export
			CreateIMathObjectFactory myMathfunc = (CreateIMathObjectFactory)GetProcAddress(hDll, "CreateIMathObjectFactory");
			IMath *myMath = myMathfunc();
			//std::cout << "CMath.key:" << myMath->key << std::endl;
			//std::cout << "CMath.value:" << myMath->value << std::endl;
			std::cout << "myMath:" << myMath->class_dll_add(1, 2) << std::endl;
			std::cout << "myMath:" << myMath->class_dll_sub(2, 3) << std::endl;
			std::cout << "myMath:" << myMath->class_dll_mul(3, 4) << std::endl;

			BOOL freeSucc = FreeLibrary(hDll);
			std::cout << "freeSucc=" << freeSucc << std::endl;

			// printf("sum=%d, sub=%d, mul=%d\n", sum, sub, mul);
			std::cout << "sum=" << sum << ", sub=" << sub << ", mul=" << mul << std::endl;
		}
		Sleep(10 * 1000);
	}
	system("pause");
	return 0;
}
