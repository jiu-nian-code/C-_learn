#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"

void swap(int* a, int* b)//交换算法
{
	int ex = *a;
	*a = *b;
	*b = ex;
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}

int PartSort1(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
			--right;
		while (left < right && a[left] <= a[keyi])
			++left;
		if (left = right)
			break;
		swap(&a[left], &a[right]);
	}
	swap(&a[keyi], &a[left]);
	keyi = left;
	return keyi;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	//int randi = left + (rand() % (right - left));
	//swap(&a[left], &a[randi]);//随机取key
	//int mid = (left + right) / 2;
	//if (a[left] < a[mid])
	//{
	//	if (a[mid] < a[right])
	//	{
	//		swap(&a[left], &a[mid]);
	//	}
	//	else if(a[left] < a[right])
	//	{
	//		swap(&a[left], &a[right]);
	//	}
	//}
	//else
	//{
	//	if (a[right] < a[mid])
	//	{
	//		swap(&a[left], &a[mid]);
	//	}
	//	else if(a[right] < a[left])
	//	{
	//		swap(&a[left], &a[right]);
	//	}
	//}//三数取中
	int ret = PartSort3(a, left, right);
	QuickSort(a, left, ret - 1);
	QuickSort(a, ret + 1, right);
}

int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] > key)
			--right;
		a[left] = a[right];
		while (left < right && a[left] < key)
			++left;
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}

int PartSort3(int* a, int left, int right)
{
	int keyi = left;
	int curr = left + 1;
	int prev = left;
	while (curr <= right)
	{
		if (a[curr] < a[keyi] && ++prev != curr)
		{
			swap(&a[prev], &a[curr]);  
		}
		++curr;
	}
	swap(&a[keyi], &a[prev]);
	keyi = prev;
	return keyi;
}

void QuickSortNonR(int* a, int left, int right)
{
	if (left >= right)
		return;
	Stack* ptr = (Stack*)calloc(1, sizeof(Stack));
	if (ptr == NULL)
	{
		perror("QuickSortNonR:calloc");
		return;
	}
	Stack* tmp = ptr;
	StackInit(tmp);
	StackPush(tmp, right);
	StackPush(tmp, left);
	while (StackEmpty(tmp) != 1)
	{
		int begin = StackTop(tmp);
		StackPop(tmp);
		int end = StackTop(tmp);
		StackPop(tmp);
		int ret = PartSort3(a, begin, end);
		if (ret + 1 < end)
		{
			StackPush(tmp, end);
			StackPush(tmp, ret + 1);
		}
		if (begin < ret - 1)
		{
			StackPush(tmp, ret - 1);
			StackPush(tmp, begin);
		}
	}
}