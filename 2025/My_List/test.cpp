#define _CRT_SECURE_NO_WARNINGS 1

#include"My_List.h"

struct A
{
	A(int a = 0)
	{
		_a = a;
		_b = a + 1;
	}
	int _a;
	int _b;
};

void test_1()
{
	//jiunian::list<A> a;
	//a.push_back(1);
	//a.push_back(2);
	//a.push_back(3);
	//a.push_back(4);
	//a.erase(a.begin());
	//a.erase(a.begin());
	//a.erase(a.begin());
	//a.erase(a.begin());
	//auto it = a.begin();
	//auto It = a.begin();
	//while (it != a.end())
	//{
		//cout << (it != It) << " ";
	//}
}

void test_2()
{
	jiunian::list<int> a;
	a.push_front(1);
	a.push_front(2);
	a.push_front(3);
	a.push_front(4);
	//a.pop_back();
	//a.pop_front();
	//jiunian::list<int> b(a.begin(), --a.end());
	//jiunian::list<int> b;
	//a.swap(b);
	//auto it = b.begin();
	//while (it != b.end())
	//{
	//	cout << *(it++) << " ";
	//}
	//cout << endl;
	a.clear();
	auto it = a.begin();
	while (it != a.end())
	{
		cout << *(it++) << " ";
	}

	//cout << a.front() << "";
}

struct tmp
{
	tmp(int _a = 2):
		a(_a)
	{

	}
	int a = 2;
};

void test_3()
{
	jiunian::list<tmp> x;
	x.push_back(tmp(2));
	auto it = x.begin();
	cout << it->a << endl;
}

int main()
{
	test_3();
	return 0;
}