#include <stdio.h>
#include <stdlib.h>

_declspec(dllimport) int dll_add(int add1, int add2);
_declspec(dllimport) int dll_sub(int sub1, int sub2);
_declspec(dllimport) int dll_mul(int mul1, int mul2);

// link lib -> auto link dll file
#pragma comment(lib, "../Debug/Calclib_dynamic.lib")

int main()
{
	int sum = 0;
	int sub = 0;
	int mul = 0;
	sum = dll_add(5, 3);
	sub = dll_sub(5, 3);
	mul = dll_mul(5, 3);
	printf("sum=%d, sub=%d, mul=%d\n", sum, sub, mul);
	system("pause");
	return 0;
}