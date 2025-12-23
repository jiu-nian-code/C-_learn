#define _CRT_SECURE_NO_WARNINGS 1

#include"Quick_sort.h"

int main()
{
	int a[20] = { 2,3,8,5,6,4,1,7,9,10,12,19,11,20,17,56,23,89,100,55 };
	//BubbleSort(a, 10);
	/*QuickSort(a, 0, 9);*/
	QuickSortNonR(a, 0, 19);
	return 0;
}