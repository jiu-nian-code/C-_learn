#include"heap.h"

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
	raise(hp->_a,hp->_size);
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
	down(hp->_a, hp->_size);
}

void down(HPDataType* a, int n)//向下调整算法
{
	int parents = 1;
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

HPDataType HeapTop(Heap* hp)
{
	assert(hp && HeapEmpty(hp));
	return hp->_a[0];
}