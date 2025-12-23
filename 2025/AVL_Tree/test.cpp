#define _CRT_SECURE_NO_WARNINGS 1

#include"AVL.h"

#include<time.h>

void test_1()
{
	AVL<int, int>x;

	//x.insert(27, 1);
	//x.insert(8, 2);
	//x.insert(57, 3);
	//x.insert(28, 4);
	//x.insert(90, 5);
	//x.insert(32, 6);
	//x.insert(11, 7);
	//x.insert(39, 7);
	//x.insert(96, 7);
	//x.insert(99, 7);

	//27 8 57 28 90 32 11 39 96 99

	for (int i = 0; i < 10000000; i++)
	{
		int y = rand() % 10000000 + i;
		//cout << y << " ";
		x.insert(y, 1);
	}
	//cout << endl;

	x.check();
	//a.inorder();

	cout << x.high();
}

int main()
{
	srand(time(NULL));
	test_1();
	return 0;
}