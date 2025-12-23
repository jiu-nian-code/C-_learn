#include"stack.h"

void test1(Stack* ps)
{
	StackInit(ps);
	int result = StackEmpty(ps);
	printf("%d\n", result);
	StackPush(ps, 1);
	StackPush(ps, 2);
	StackPush(ps, 3);
	StackPush(ps, 4);
	StackPush(ps, 5);
	StackPop(ps);
	StackPop(ps);
	StackPop(ps);
	StackPush(ps, 6);
	StackPush(ps, 7);
	STDataType get = StackTop(ps);
	printf("%d\n", get);
	int num = StackSize(ps);
	printf("%d\n", num);
	result = StackEmpty(ps);
	printf("%d\n", result);
	StackDestroy(ps);
	StackDestroy(ps);
	result = StackEmpty(ps);
	printf("%d\n", result);
	return;
}
//用栈模拟队列
typedef struct {
	Stack* first;
	Stack* second;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* newQueue = (MyQueue*)calloc(1, sizeof(MyQueue));
	newQueue->first = (Stack*)calloc(1, sizeof(Stack));
	newQueue->second = (Stack*)calloc(1, sizeof(Stack));
	StackInit(newQueue->first);
	StackInit(newQueue->second);
	return newQueue;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(obj->first, x);
}

int myQueuePop(MyQueue* obj) {
	if (StackEmpty(obj->second))
	{
		while (StackEmpty(obj->first))
		{
			int ex = StackTop(obj->first);
			StackPop(obj->first);
			StackPush(obj->second, ex);
		}
	}
	int ret = StackTop(obj->second);
	StackPop(obj->second);
	return ret;
}

int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(obj->second))
	{
		while (!StackEmpty(obj->first))
		{
			int ex = StackTop(obj->first);
			StackPop(obj->first);
			StackPush(obj->second, ex);
		}
	}
	int ret = StackTop(obj->second);
	return StackTop(obj->second);
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(obj->first) && StackEmpty(obj->second);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(obj->first);
	StackDestroy(obj->second);
	obj->first = NULL;
	obj->second = NULL;
}


void test_2()
{
	MyQueue* obj = myQueueCreate();
	myQueuePush(obj, 1);
	//myQueuePush(obj, 2);
	myQueuePop(obj);
}




int main()
{
	////Stack ps;
	////test1(&ps);
	//test_2();
	//return 0;
}