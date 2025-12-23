#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include"UnOrderedSet.h"

#include<set>

using namespace std;

int main()
{
	bit::unordered_set<int> x;
	x.insert(1);
	auto it = x.begin();

	return 0;
}