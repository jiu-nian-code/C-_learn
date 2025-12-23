#include"SeqList.h" 

void SeqListInit(SeqList* ps)//初始化
{
	assert(ps);
	SLDateType* ptr = calloc(10, sizeof(SLDateType));
	if (ptr == NULL)
	{
		perror("SeqListInit:calloc");
		return;
	}
	ps->a = ptr;
	ps->size = 10;
	ps->capacity = 0;
}

void SeqListDestroy(SeqList* ps)//销毁
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SeqList* ps)//打印
{
	assert(ps);
	for (int i = 0; i < ps->capacity; i++)
	{
		printf("%d ", (ps->a[i]));
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDateType x)//尾插
{
	assert(ps);
	capa(ps);
	ps->a[ps->capacity] = x;
	ps->capacity++;
}

void capa(SeqList* ps)//扩容
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		SLDateType * ptr = realloc(ps->a, (ps->size) * 2 * sizeof(SLDateType));
		if (ptr == NULL)
		{
			perror("capa:realloc");
			return;
		}
		ps->a = ptr;
		ps->size *= 2;
	}
}

void SeqListPushFront(SeqList* ps, SLDateType x)//头插
{
	assert(ps);
	capa(ps);
	memmove(ps->a + 1, ps->a, sizeof(SLDateType) * (ps->capacity));
	ps->a[0] = x;
	ps->capacity++;
}

void SeqListPopFront(SeqList* ps)//头删
{
	assert(ps);
	memmove(ps->a, ps->a + 1, sizeof(SLDateType) * (ps->capacity - 1));
	ps->capacity--;
}

void SeqListPopBack(SeqList* ps)//尾删
{
	assert(ps);
	ps->capacity--;
}

int SeqListFind(SeqList* ps, SLDateType x)//查找
{
	assert(ps);
	for (int i = 0; i < ps->capacity - 1; i++)
	{
		if (memcmp(&x, &(ps->a[i]), sizeof(SLDateType)) == 0)
		{
			printf("找到了,是第%d个元素\n", i + 1);
		}
	}
}

void SeqListInsert(SeqList* ps, int pos, SLDateType x)//指定位置插入
{
	assert(ps);
	capa(ps);
	memmove(ps->a + pos, ps->a + pos - 1, (ps->capacity - pos + 1) * sizeof(SLDateType));
	ps->a[pos - 1] = x;
	ps->capacity++;
}

void SeqListErase(SeqList* ps, int pos)//指定位置删除
{
	assert(ps);
	memmove(ps->a + pos - 1, ps->a + pos, (ps->capacity - pos) * sizeof(SLDateType));
	ps->capacity--;
}