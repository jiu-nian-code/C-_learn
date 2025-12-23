#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"

#include<vector>

template<class T>
struct a
{
	T _a = 1;
};

int main()
{
	a<int> x;
	std::cout << x._a;
	return 0;
}