#define _CRT_SECURE_NO_WARNINGS 1

#include"RBTree.h"

#include"AVL.h"

#include<time.h>

void test_1()
{
	RB_Tree<int, int>x;
	//x.insert(85, 0);
	//x.insert(19, 0);
	//x.insert(37, 0);
	//x.insert(86, 0);
	//x.insert(101, 0);
	//x.insert(56, 0);
	//x.insert(53, 0);
	//x.insert(75, 0);
	//x.insert(57, 0);
	//x.insert(30, 0);

	//85 19 37 86 101 56 53 75 57 30

	for (int i = 0; i < 100000000; ++i)
	{
		int y = rand() % 100000000 + i;
		//cout << y << " ";
		x.insert(y, 0);
	}
	cout << endl;

	cout << x.IsBalance();
}

void test()
{
	RB_Tree<int, int> x;
	AVL_Tree<int, int> y;
	for (int i = 0; i < 10000000; ++i)
	{
		int tmp = rand() % 10000000 + i;
		x.insert(tmp, 0);
		y.insert(tmp, 0);
	}

	cout << "RB : " << "旋转次数 : " << x.rotation_num << " 高度 : " << x.Height() << endl;
	cout << "AVL : " << "旋转次数 : " << y.rotation_num << " 高度 : " << y.high() << endl;
}

int main()
{
	srand(time(NULL));

	test();
	return 0;
}