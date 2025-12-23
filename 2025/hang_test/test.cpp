#define _CRT_SECURE_NO_WARNINGS 1

#include"RB.h"

#include"AVL.h"

#include<time.h>

void test()
{
	RBTree<int, int> x;
	AVLTree<int, int> y;
	for (int i = 0; i < 100000000; ++i)
	{
		int tmp = rand() % 100000000 + i;
		pair<int, int>a(tmp, 0);
		x.Insert(a);
		y.Insert(a);
	}

	cout << "RB : " << "旋转次数 : " << x._rotateCount << " 高度 : " << x.Height() << endl;
	cout << "AVL : " << "旋转次数 : " << y._rotateCount << " 高度 : " << y.Height() << endl;
}

int main()
{
	srand(time(NULL));
	test();
	return 0;
}