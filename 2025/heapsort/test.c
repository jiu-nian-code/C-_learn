#include"heapsort.h"

void test1()
{
	int b[100] = {22, 55, 15, 100, 1000, 561, 89, 564, 12, 34};
	HeapSort(b, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", b[i]);
	}
}

int main()
{
	test1();
	return 0;
}