#define _CRT_SECURE_NO_WARNINGS 1

#include"My_Bitset.h"

void test_1()
{
	My_Bitset<1000> x;
	x.set(100);
	x.set(99);
	x.set(564);
	x.set(300);
	x.set(15);

	cout << x.test(100);
	cout << x.test(99);
	cout << x.test(564);
	cout << x.test(300);
	cout << x.test(15);
	//cout << x.test(10);
}

int main()
{
	test_1();
	int a = 0;
	return 0;
}