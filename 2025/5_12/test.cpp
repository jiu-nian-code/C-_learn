#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<string>

using namespace std;

class A
{
	int _a;
public:
	A(int a = 1):
		_a(a)
	{

	}

	virtual void print()
	{
		cout << _a << endl;
	}
};

class B : virtual public A
{
	int _b;
public:
	B(int a = 1, int b = 2):
		A(a),
		_b(b)
	{

	}

	virtual void print()
	{
		cout << _b << endl;
	}

	virtual void B_func()
	{
	}
};

class C : virtual public A
{
	int _c;
public:
	C(int a = 1, int c = 3):
		A(a),
		_c(c)
	{

	}

	virtual void print()
	{
		cout << _c << endl;
	}

	virtual void C_func()
	{
	}
};

class D : public B, public C
{
	int _d;
public:
	D(int a = 1, int b = 2, int c = 3, int d = 4):
		B(a, b),
		C(a, c),
		_d(d)
	{

	}

	virtual void print()//
	{
		cout << _d << endl;
	}

	virtual void D_func()
	{

	}
};

int main()
{
	D d;
	return 0;
}