#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<vector>

using namespace std;

int main()
{
	//int a[10] = { 0 };
	//int* b = a + 10;
	//vector<int>num(a, b);
	//for (auto& e : num)
	//	cout << e << " ";

	vector<bool>num(10);
	vector<int>nums(10);
	cout << num.capacity() << endl;
	cout << nums.capacity() << endl;
	return 0;
}