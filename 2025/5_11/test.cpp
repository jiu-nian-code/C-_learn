#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

class A
{
public:
	int _a = 1;
	A()
	{

	}

	A(const A& x)
	{
		cout << "copy" << endl;
	}
};

void func()
{
	const A x;
	throw &x;
}

int main()
{
	try
	{
		func();
	}
	catch (void* x)
	{
		cout << "func" << endl;
	}
	return 0;
}