#ifndef OPERATIONS_H
#define OPERATIONS_H

#ifdef DLLCLASS_EXPORTS
#define EXT_CLASS _declspec(dllexport)
#else
#define EXT_CLASS _declspec(dllimport)
#endif

// export function address
class EXT_CLASS CMath
{
public:
	int dll_add(int add1, int add2);
	int dll_sub(int sub1, int sub2);
	int dll_mul(int mul1, int mul2);
};

#endif // OPERATIONS_H
