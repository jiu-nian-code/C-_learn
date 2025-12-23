#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<assert.h>

#include<errno.h>

#include<stdbool.h>

typedef int QUDataType;

typedef struct QueueNode//队列的节点
{
	QUDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue//管理队列的信息，队头队尾
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue* q);//队列初始化

void QueueDestory(Queue* q);//队列销毁

void QueuePush(Queue* q, QUDataType x);//队尾入队列

void QueuePop(Queue* q);//队头出队列

int QueueSize(Queue* q);//获取队列中有效元素的个数

int QueueEmpty(Queue* q);//检验队列是否为空

QUDataType QueueFront(Queue* q);//获取队列头部元素

QUDataType QueueBack(Queue* q);//获取队列尾部元素

void QueueTest();