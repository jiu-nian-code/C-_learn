#include"heapsort.h"

void HeapInit(Heap* php)
{
	assert(php);
	Heap* ptr = (HPDataType*)calloc(8, sizeof(HPDataType));
	if (ptr == NULL)
	{
		perror("HeapInit:calloc");
		return;
	}
	php->_a = ptr;
	php->_capacity = 8;
	php->_size = 0;
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	Expansion(hp);
	hp->_a[hp->_size] = x;
	++hp->_size;
	raise(hp->_a, hp->_size);
}

void Expansion(Heap* hp)
{
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		Heap* ptr = (Heap*)realloc(hp->_a, sizeof(HPDataType) * hp->_capacity * 2);
		if (ptr == NULL)
		{
			perror("Expansion:realloc");
			return;
		}
		hp->_a = ptr;
		hp->_capacity *= 2;
	}
}

void HeapPop(Heap* hp)
{
	assert(hp && hp->_size);
	swap(hp->_a, &(hp->_a[hp->_size - 1]));
	--hp->_size;
	down(hp->_a, hp->_size, 1);
}

void down(HPDataType* a, int n, int start)//向下调整算法
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

void swap(int* a, int* b)//交换算法
{
	int ex = *a;
	*a = *b;
	*b = ex;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
	{
		return 0;
	}
	return 1;
}

void raise(HPDataType* a, int n)//向上调整算法
{
	int child = n;
	int parents = child / 2;
	while (child > 1)
	{
		if (a[child - 1] > a[parents - 1])
		{
			swap(&(a[child - 1]), &(a[parents - 1]));
			child = parents;
			parents = child / 2;
		}
		else
		{
			break;
		}
	}
}


HPDataType HeapTop(Heap* hp)
{
	assert(hp && HeapEmpty(hp));
	return hp->_a[0];
}

void HeapSort(int* a, int n)// 对数组进行堆排序(向下调整)
{
	int num = n / 2;//最后一个数的父结点
	while (num)
	{
		down(a, n, num--);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[end], &a[0]);
		down(a, n, 0);
		--end;
	}
}

//void HeapSort(int* a, int n)// 对数组进行堆排序(向上调整，效率过低)
//{
//	for (int i = 2; i < n; ++i)
//	{
//		raise(a, i);
//	}
//}


/*
1                                         3 * 2^0         (f - 1) * 2^0
2 3                                       2 * 2^1         (f - 2) * 2^1
4 5 6 7                                   1 * 2^2         (f - 3) * 2^2
8 9 10 11 12 13 14 15



2^f - 1         2^(f - 1)



N  
//向下
    T(N) =  (f - 1) * 2^0 + (f - 2) * 2^1 + (f - 3) * 2^2 + ………… + 2 * 2^(f - 3) + 1 * 2^(f - 2)
2 * T(N) =                  (f - 1) * 2^1 + (f - 2) * 2^2 + ………… + 2 * 2^(f - 2) + 1 * 2^(f - 1)
    T(N) = -(f - 1) * 2^0 + 2^1 + 2^2 + ................ + 2^(f - 2) + 1 * 2^(f - 1)
	     = 1 - f + 2^1 * (1 - 2^(f - 1)) / (1 - 2)
		 = 1 - f + 2^f - 2
		 = 2^f - 1 - f
		 =N + 1 - 1 - log(N + 1)
		 =N - log(N + 1)
		 =N

		 O(N)




		f = log(N + 1)


//向上
	T(N) = 2^1 * 1 + 2^2 * 2 + 2^3 * 3 + ………… + 2^(h - 2) * (h - 2) + 2^(h - 1) * (h - 1)
   2T(N) =           2^2 * 1 + 2^3 * 2 + ………… + 2^(h - 2) * (h - 3) + 2^(h - 1) * (h - 2) + 2^h * (h - 1)
   -T(N) = 2^1 + 2^2 + 2^3 + ………… + 2^(h - 1) - 2^h * (h - 1)
   -T(N) = 2 * (1 - 2^(h - 1)) / (1 - 2) - 2^h * (h - 1)
   -T(N) = 2^h - 2 - 2^h * (h - 1)
   -T(N) = 2^h * (2 - h) - 2
    T(N) = 2^h * (h - 2) + 2
	     = (N + 1) * (log(N + 1) - 2) + 2
		 = NlogN
*/

/*
	4 3 2 1 5 6
	*/