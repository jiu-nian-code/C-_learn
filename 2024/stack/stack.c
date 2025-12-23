#include"stack.h"

void StackInit(Stack* ps)//初始化
{
	assert(ps);
	STDataType* ptr = (STDataType*)calloc(10, sizeof(STDataType));
	if (ptr == NULL)
	{
		perror("StackInit:calloc");
		return;
	}
	ps->_a = ptr;
	ps->_capacity = 10;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType data)//入栈
{
	assert(ps);
	if (ps->_capacity == ps->_top)
	{
		Capacity(ps);
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}

void Capacity(Stack* ps)//扩容
{
	assert(ps);
	STDataType* ptr = (STDataType*)realloc(ps->_a, 2 * (ps->_capacity) * sizeof(Stack));
	if (ptr == NULL)
	{
		perror("Capacity:realloc");
		return;
	}
	ps->_a = ptr;
	ps->_capacity *= 2;
}

void StackPop(Stack* ps)//出栈
{
	assert(ps && !StackEmpty(ps));
	ps->_top--;
}

STDataType StackTop(Stack* ps)//获取栈顶元素
{
	assert(ps && !StackEmpty(ps));
	return ps->_a[ps->_top - 1];
}

int StackSize(Stack* ps)// 获取栈中有效元素个数 
{
	assert(ps);
	return ps->_top;
}

int StackEmpty(Stack* ps)// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
{
	assert(ps);
	if (ps->_top == 0)
		return 1;
	return 0;
}

void StackDestroy(Stack* ps)// 销毁栈 
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}