#include <iostream>
#include "../CalcCPPlib_dynamic/operations.h"

// link lib -> auto link dll file
#pragma comment(lib, "../Debug/CalcCPPlib_dynamic.lib")

int main()
{
	CMath math;
	int sum = math.dll_add(5, 3);
	int sub = math.dll_sub(5, 3);
	int mul = math.dll_mul(5, 3);
	// printf("sum=%d, sub=%d, mul=%d\n", sum, sub, mul);
	std::cout << "sum=" << sum << ", sub=" << sub << ", mul=" << mul << std::endl;
	system("pause");
	return 0;
}
