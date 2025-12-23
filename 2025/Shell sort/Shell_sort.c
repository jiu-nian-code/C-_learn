#include"Shell_sort.h"

//int sizenum(int* a)
//{
//	int* curr = a;
//	int ret = 0;
//	while (*curr)
//	{
//		++curr;
//		++ret;
//	}
//	return ret;
//}

//void InsertSort(int* a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i - 1; j >= 0; j--)
//		{
//			if (*(a + i) < *(a + j) && *(a + i) > *(a + j - 1))
//			{
//				int ex = *(a + i);
//				memmove(a + j + 1, a + j, sizeof(int) * (i - j));
//				*(a + j) = ex;
//				break;
//			}
//		}
//	}
//}

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

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;
		for (int j = 0; j < n - gap; j++)
		{
			int end = j;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}