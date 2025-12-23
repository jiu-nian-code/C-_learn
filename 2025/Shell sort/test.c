#include"Shell_sort.h"

void test()
{
	int a[10] = { 5,4,9,6,7,2,8,1,3,10 };
	//InsertSort(a, 10);
	ShellSort(a, 10);
}

int main()
{
	test();
	return 0;
}