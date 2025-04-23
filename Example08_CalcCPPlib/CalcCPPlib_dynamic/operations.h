#ifndef OPERATIONS_H
#define OPERATIONS_H

#ifdef DLLCLASS_EXPORTS
#define EXT_CLASS _declspec(dllexport)
#else
#define EXT_CLASS _declspec(dllimport)
#endif

class IMath {
public:
	virtual int class_dll_add(int add1, int add2) = 0;
	virtual int class_dll_sub(int sub1, int sub2) = 0;
	virtual int class_dll_mul(int mul1, int mul2) = 0;
};

// export class
class CMath : public IMath
{
public:
	int class_dll_add(int add1, int add2);
	int class_dll_sub(int sub1, int sub2);
	int class_dll_mul(int mul1, int mul2);

public:
	int key = 10;
	long value = 20;
};

#endif // OPERATIONS_H
