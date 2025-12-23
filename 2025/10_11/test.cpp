#include<iostream>

class A
{
public:
	int _a;
};

class B : public A
	// class B : virtual public A
{
public:
	int _b;
};

class C : public A
	// class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	std::cout << d.B::_a << std::endl; //出错，有二义性，得指定作用域
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}