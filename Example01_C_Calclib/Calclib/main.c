#include <stdio.h>
#pragma comment(lib, "../Debug/Calclib_static.lib")

int main()
{
	int sum = 0;
	int sub = 0;
	sum = lib_add(5, 3);
	sub = lib_sub(5, 3);
	printf("sum=%d, sub=%d\n", sum, sub);
	system("pause");
	return 0;
}
