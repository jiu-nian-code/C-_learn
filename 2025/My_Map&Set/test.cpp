#define _CRT_SECURE_NO_WARNINGS 1

#include"set.h"

#include"map.h"

#include<time.h>

void test_1()
{
	My_Set<int> a;
	//for (int i = 0; i < 100000000; ++i)
	//{
	//	int x = rand() % 100000000 + i;
	//	a.insert(x);
	//}

	//for (auto& e : a)
	//{
	//	cout << e << endl;
	//}

	//cout << a.Height();

	//auto it = a.begin();
	//*it = 1;

	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.insert(7);
	a.insert(8);
	a.insert(9);

	cout << a.find(1) << endl;
	cout << a.find(2) << endl;
	cout << a.find(3) << endl;
	cout << a.find(4) << endl;
	cout << a.find(5) << endl;
	cout << a.find(6) << endl;
	cout << a.find(7) << endl;
	cout << a.find(8) << endl;
	cout << a.find(9) << endl;
	cout << a.find(10) << endl;
}

void test_2()
{
	My_Map<int, int> a;

	for (int i = 0; i < 100; ++i)
	{
		int x = rand() % 100 + i;
		//a.insert(make_pair(x, x));
		a[x] = 1;
	}

	auto it = a.begin();

	//it->first = 1;
	//it->second = 1;

	for (auto& e : a)
	{
		cout << e.first << " : " << e.second << endl;
	}
}

int main()
{
	srand(time(NULL));
	test_1();
	return 0;
}