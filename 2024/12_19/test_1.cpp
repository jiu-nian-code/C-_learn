#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

//typedef int a[10];

void Stack(int a, int b)
{
	printf("hehe");
}

void Stack(int a, double b)
{
	printf("hehe");
}

void test(int (*a) [10])
{
	int b[10] = {1,2,3,4,5,6,7,8,9,10};
	for (auto x : *a)
	{
		std::cout << x << " ";
	}
}

int main()
{
	//exit(-1);
	//Stack(1, 1);
	//Stack(1, 0.1);
	int (*arr)[10];
	int a[10] = {10,9,8,7,6,5,4,3,2,1};
	arr = &a;
	test(&a);
	return 0;
}