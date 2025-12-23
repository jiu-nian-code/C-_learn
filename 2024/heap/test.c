#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

void test1()
{
	Heap php;
	HeapInit(&php);
	/*int answer = HeapEmpty(&php);
	printf("%d ", answer);*/
	HeapPush(&php, 5);
	HeapPush(&php, 15);
	/*int result = HeapTop(&php);
	printf("%d ", result);*/
	/*int num = HeapSize(&php);
	printf("%d ", num);*/
	HeapPush(&php, 2);
	HeapPush(&php, 89);
	HeapPush(&php, 1);
	HeapPush(&php, 6);
	HeapPush(&php, 6);
	HeapPush(&php, 6);
	/*num = HeapSize(&php);
	printf("%d ", num);*/
	HeapPush(&php, 100);
	HeapPush(&php, 46);
	HeapPush(&php, 1);
	/*result = HeapTop(&php);
	printf("%d ", result);*/
	HeapPush(&php, 100);
	HeapPush(&php, 100);
	HeapPush(&php, 100);
	HeapPush(&php, 100);
	HeapPush(&php, 100);
	HeapPush(&php, 1000);
	/*answer = HeapEmpty(&php);
	printf("%d ", answer);*/
	/*num = HeapSize(&php);
	printf("%d ", num);*/
	/*result = HeapTop(&php);
	printf("%d ", result);*/
	for (int i = 0; i < php._size; i++)
	{
		printf("%d\t", php._a[i]);
	}
	printf("\n");
	HeapPop(&php);
	HeapPop(&php);
	HeapPop(&php);
	HeapPop(&php);
	HeapPop(&php);
	HeapPop(&php);
	HeapPop(&php);
	for (int i = 0; i < php._size; i++)
	{
		printf("%d\t", php._a[i]);
	}
	printf("\n");
	HeapPop(&php);
	HeapPop(&php);
	HeapPop(&php);
	for (int i = 0; i < php._size; i++)
	{
		printf("%d\t", php._a[i]);
	}
	printf("\n");
	HeapPop(&php);
	HeapPop(&php);
	HeapPop(&php);
	for (int i = 0; i < php._size; i++)
	{
		printf("%d\t", php._a[i]);
	}
	printf("\n");
	HeapPop(&php);
	HeapPop(&php);
	HeapPop(&php);
	HeapPop(&php);
	//HeapPop(&php);

	/*for (int i = 0; i < php._size; i++)
	{
		printf("%d\t", php._a[i]);
	}*/
}

int main()
{
	test1();
	return 0;
}

/*
100 
100 100 
89 46 100 100 
15 6 1 1 2 6 6 100 
5
*/