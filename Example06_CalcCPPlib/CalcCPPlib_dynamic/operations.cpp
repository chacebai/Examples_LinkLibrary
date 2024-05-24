//#include "operations.h"

// fist way use define .def file
int dll_add(int add1, int add2)
{
	return add1 + add2;
}
int dll_sub(int sub1, int sub2)
{
	return sub1 - sub2;
}
// second way use _declspec
_declspec(dllexport) int dll_mul(int mul1, int mul2)
{
	return mul1 * mul2;
}