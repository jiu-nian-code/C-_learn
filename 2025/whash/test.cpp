#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include"Set.h"


void test_6()
{
	My_Unordered_Set<int> x;
	x.insert(1);

	auto it = x.begin();
	cout << *it << endl;
}

int main()
{
	test_6();
	return 0;
}