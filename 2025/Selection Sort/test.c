#define _CRT_SECURE_NO_WARNINGS 1

#include"Selection_Sort.h"

int main()
{
	int a[100] = { 2,3,1,5,8,7,9,4,6,10,100,123,56,59,45 };
	//SelectSort(a, 10);
	HeapSort(a, 15);
	return 0;
}

/*
10 9 8 5 6 7 2 4 3 1 
10 8 9 6 3 7 1 4 5 2
*/