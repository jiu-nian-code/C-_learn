#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}

void QueueDestory(Queue* q)
{
	assert(q);
	QueueNode* curr = q->_front;
	QueueNode* prev = NULL;
	while (curr != NULL)
	{
		prev = curr;
		curr = curr->_next;
		free(prev);
	}
	prev = NULL;
	q->_front = q->_rear = NULL;
}

void QueuePush(Queue* q, QUDataType x)
{
	assert(q);
	QueueNode* newnode = (QueueNode*)calloc(1, sizeof(QueueNode));
	newnode->_data = x;
	if (q->_front == NULL)
	{
		q->_rear = q->_front = newnode;
	}
	else
	{
		q->_rear->_next = newnode;
		q->_rear = newnode;
	}
}

void QueuePop(Queue* q)
{
	assert(q && q->_front);
	QueueNode* prev = q->_front;
	q->_front = q->_front->_next;
	free(prev);
	prev = NULL;
	if (q->_front == NULL)
	{
		q->_rear = NULL;
	}
}

int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	QueueNode* curr = q->_front;
	while (curr)
	{
		curr = curr->_next;
		++count;
	}
	return count;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return !(q->_front && q->_rear);
}

QUDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

QUDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}