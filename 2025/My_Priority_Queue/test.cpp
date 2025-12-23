#define _CRT_SECURE_NO_WARNINGS 1

#include"My_Priority_Queue.h"

template<class T>
struct compareruler
{
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};

void test()
{
	compareruler<int> com;
	int a = 0;
	int b = 1;
	cout << com(a, b) << endl;
}

int main()
{
	test();
	//jiunian::priority_queue<int, vector<int>, greater<int>> heap;
	//heap.push(2);
	//heap.push(5);
	//heap.push(1);
	//heap.push(4);
	//heap.push(3);
	//heap.push(6);
	//heap.push(1000);
	//heap.push(6);
	//heap.push(6);
	//heap.push(6);
	//heap.pop();

	//cout << heap.top();

	//vector<int>num{ 5, 6, 4, 2, 9, 1, 2, 7, 8, 0 };
	//jiunian::priority_queue<int, vector<int>, greater<int>> heap(num.begin(), num.end());
	//cout << heap.top();
	return 0;
}