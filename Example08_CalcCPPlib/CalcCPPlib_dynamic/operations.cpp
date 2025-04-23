#define DLLCLASS_EXPORTS
#include "operations.h"

// fist way use use extern "C" _declspec
extern "C" _declspec(dllexport) int dll_add(int add1, int add2)
{
	CMath math;
	return math.class_dll_add(add1, add2);
}
extern "C" _declspec(dllexport) int dll_sub(int sub1, int sub2)
{
	return sub1 - sub2;
}
// second way use _declspec
_declspec(dllexport) int dll_mul(int mul1, int mul2)
{
	return mul1 * mul2;
}


int CMath::class_dll_add(int add1, int add2)
{
	return add1 + add2;
}
int CMath::class_dll_sub(int sub1, int sub2)
{
	return sub1 - sub2;
}
int CMath::class_dll_mul(int mul1, int mul2)
{
	return mul1 * mul2;
}
extern "C" __declspec(dllexport) IMath* CreateIMathObjectFactory()
{
	return new CMath();
}
extern "C" __declspec(dllexport) CMath* CreateCMathObjectFactory()
{
	return new CMath();
}
