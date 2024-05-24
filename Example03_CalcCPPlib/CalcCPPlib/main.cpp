#include <iostream>
#pragma comment(lib, "../Debug/Calclib_static.lib")

// because of cpp
extern "C" {
	int lib_add(int add1, int add2);
	int lib_sub(int sub1, int sub2);
}
// end declare

int main()
{
	int sum = 0;
	int sub = 0;
	sum = lib_add(5, 3);
	sub = lib_sub(5, 3);
	// printf("sum=%d, sub=%d\n", sum, sub);
	std::cout << "sum=" << sum << ", sub=" << sub << std::endl;
	system("pause");
	return 0;
}