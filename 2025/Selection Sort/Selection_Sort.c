#define _CRT_SECURE_NO_WARNINGS 1

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int max = left;
		int min = left;
		for (int i = left; i <= right; ++i)
		{
			if (a[max] < a[i])
			{
				max = i;
				continue;
			}
			if (a[min] > a[i])
			{
				min = i;
			}
		}
		swap(&a[left++], &a[min]);
		swap(&a[right--], &a[max]);
	}
}

void down(int* a, int n, int start)//向下调整算法
{
	int parents = start;//or start = 0 -> child = parents * 2 + 1
	int child = parents * 2;
	while (child <= n)
	{
		if (child + 1 <= n && a[child - 1] < a[child])
		{
			++child;
		}
		if (a[child - 1] > a[parents - 1])
		{
			swap(&(a[child - 1]), &(a[parents - 1]));
			parents = child;
			child = parents * 2;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	int num = n / 2;
	while (num)
	{
		down(a, n, num--);
	}
	int end = n;
	while (end > 0)
	{
		swap(&a[--end], &a[0]);//数组序号本身就要减一位且交换完后也恰好要将end减一缩小范围保护交换完的元素
		down(a, end, 1);
		//--end;
	}
}