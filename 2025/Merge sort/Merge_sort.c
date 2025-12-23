#include"Merge_sort.h"

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[i + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void MergeSort(int* a, int n)
{
	if (n < 10)
	{
		InsertSort(a, n);
		return;
	}
	int* arr = (int*)calloc(n, sizeof(int));
	if (arr == NULL)
	{
		perror("MergeSort:calloc");
		return;
	}
	int left = 0;
	int right = n / 2;
	MergeSort(a + left, n / 2);
	MergeSort(a + right, n - n / 2);
	int i = 0;
	while (left < n / 2 && right < n)
	{
		if (a[left] < a[right])
		{
			arr[i++] = a[left++];
		}
		else
		{
			arr[i++] = a[right++];
		}
	}
	while (left < n / 2)
	{
		arr[i++] = a[left++];
	}
	while (right < n)
	{
		arr[i++] = a[right++];
	}
	for (int j = 0; j < n; ++j)
	{
		a[j] = arr[j];
	}
	free(arr);
	arr = NULL;
}

void MergeSortNonR(int* a, int n)
{
	int* arr = (int*)calloc(n, sizeof(int));
	if (arr == NULL)
	{
		perror("MergeSortNonR:calloc");
	}
	int gap = 2;
	while (gap / 2 <= n)//控制间隔
	{
		for (int i = 0; i < n; i += gap)//单趟
		{
			int num = 0;
			int left = i + 0;
			int leftend = i + gap / 2 - 1;
			int right = i + gap / 2;
			int rightend = i + gap - 1;
			//printf("[%d, %d] [%d, %d]\n", left, leftend, right, rightend);//观察用
			if (leftend < n - 1 && rightend > n - 1)
			{
				rightend = n - 1;
			}
			else if(leftend >= n - 1)
			{
				break;
			}
			while (left <= leftend && right <= rightend)//一个间隔内的比较
			{
				if (a[left] <= a[right])
				{
					arr[num++] = a[left++];
				}
				else
				{
					arr[num++] = a[right++];
				}
			}
			while (left <= leftend)
			{
				arr[num++] = a[left++];
			}
			while (right <= rightend)
			{
				arr[num++] = a[right++];
			}
			memcpy(a + i, arr, num * sizeof(int));
		}
		gap *= 2;
	}
	free(arr);
	arr = NULL;
}

void CountSort(int* a, int n)
{
	int min = 0;
	int max = 0;//千万别用地址，坑死人!
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int size = max - min + 1;
	int* arr = (int*)calloc(1, sizeof(int) * size);
	if (arr == NULL)
	{
		perror("CountSort:calloc");
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		++arr[a[i] - min];
	}
	int j = 0;
	for (int i = 0; i < size; ++i)
	{
		int num = arr[i];
		while (num > 0)
		{
			a[j++] = i + min;
			--num;
		}
	}
	free(arr);
	arr = NULL;
}