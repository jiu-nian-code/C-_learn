#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<string>

using namespace std;

class person
{
	string name;
public:
	person(const string& x = string()):
		name(x)
	{
	}

	void name_print()
	{
		cout << name << endl;
	}
};

class father
{
	int fa_money;
public:
	father(int a = 1000000, const string& x = string("little head")) :
		fa_money(a)
		//person(x)
	{
		//cout << "father(int a = 1000000)" << endl;
	}

	father(const father& x):
		fa_money(x.fa_money)
	{
		//cout << "father(const father& x)" << endl;
	}

	~father()
	{
		//cout << "~father()" << endl;
	}

	father* operator&()
	{
		return this;
	}
	
	const father* operator&()const
	{
		return this;
	}

	father& operator=(const father & x)
	{
		//cout << "father& operator=(const father & x)" << endl;
		fa_money = x.fa_money;
		return *this;
	}

	void print()
	{
		cout << fa_money << endl;
	}
};

class son : protected father
{
	int so_money;
public:
	son(int a = 1000, int b = 1000000, const string& x = string("big head")):
		father(b),
		//person(x),
		so_money(a)
	{
		//cout << "son(int a = 1000, int b = 1000000)" << endl;
	}

	son(const son& x):
		father(x),
		so_money(x.so_money)
	{
		//cout << "son(const son& x):" << endl;
	}

	~son()
	{
		//father::~father();
		//cout << "~son()" << endl;
	}

	son* operator&()
	{
		return this;
	}
	
	const son* operator&()const
	{
		return this;
	}

	son& operator=(const son& x)
	{
		//cout << "son& operator=(const son& x)" << endl;
		so_money = x.so_money;
		father::operator=(x);
		return *this;
	}

	void print(int a)
	{
		cout << so_money << endl;
	}
};

class A
{
public:
	int _a;
};

// class B : public A
class B : virtual public A
{
public:
	int _b;
};

// class C : public A
class C : virtual public A
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
	B b;
	b._a = 1;
	b._b = 2;
	d.B::_a = 1;
	d.C::_a = 2;
	cout << d._a << endl; //结果: 2， _a可以直接调用，不会有二义性，即使使用域名调用也不会出错
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}