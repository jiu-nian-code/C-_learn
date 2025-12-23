#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

void QueueTest()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	/*int result = QueueSize(&q);
	printf("%d ", result);*/
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	/*int bool = QueueEmpty(&q);
	printf("%d ", bool);
	int result = QueueSize(&q);
	printf("%d ", result);
	QueuePop(&q);
	result = QueueSize(&q);
	printf("%d ", result);
	QueuePop(&q);
	result = QueueSize(&q);
	printf("%d ", result);
	QueuePop(&q);
	result = QueueSize(&q);
	printf("%d ", result);
	bool = QueueEmpty(&q);
	printf("%d ", bool);
	QueuePop(&q);
	result = QueueSize(&q);
	printf("%d ", result);
	QueuePop(&q);
	result = QueueSize(&q);
	printf("%d ", result);
	bool = QueueEmpty(&q);
	printf("%d ", bool);*/
	//QueuePop(&q);
	int ret = QueueFront(&q);
	printf("%d\n", ret);
	ret = QueueBack(&q);
	printf("%d\n", ret);
	QueueDestory(&q);
	//int bool = QueueEmpty(&q);
	//printf("%d ", bool);
}
//用队列实现栈
typedef struct {
	Queue* first;
	Queue* sceond;
} MyStack;


MyStack* myStackCreate() {
	MyStack* newstack = calloc(1, sizeof(MyStack));
	newstack->first = (Queue*)calloc(1, sizeof(Queue));
	newstack->sceond = (Queue*)calloc(1, sizeof(Queue));
	return newstack;
}

void myStackPush(MyStack* obj, int x) {
	assert(obj);
	if (!QueueEmpty(obj->first))
	{
		QueuePush(obj->first, x);
	}
	else
	{
		QueuePush(obj->sceond, x);
	}
}

int myStackPop(MyStack* obj) {
	// assert(obj && obj->first->_front && obj->sceond->_front);
	Queue* out = obj->first;
	Queue* tran = obj->sceond;
	if (QueueEmpty(out))
	{
		out = obj->sceond;
		tran = obj->first;
	}
	while (out->_front->_next)
	{
		int ex = QueueFront(out);
		QueuePop(out);
		QueuePush(tran, ex);
	}
	int ret = out->_front->_data;
	QueuePop(out);
	return ret;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(obj->first))
	{
		return QueueBack(obj->first);
	}
	return QueueBack(obj->sceond);
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(obj->first) && QueueEmpty(obj->sceond);
}

void myStackFree(MyStack* obj) {
	QueueDestory(obj->first);
	QueueDestory(obj->sceond);
}

void test()
{
	MyStack* stack = myStackCreate();
	myStackPush(stack, 1);
	myStackPush(stack, 2);
	myStackTop(stack);
	myStackPop(stack);
}

int main()
{
	test();
	return;
}