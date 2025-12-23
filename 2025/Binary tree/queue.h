#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<assert.h>

#include<errno.h>

#include<stdbool.h>

typedef struct BinaryTreeNode* QUDataType;

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

void QueueInit(Queue* q);

void QueueDestory(Queue* q);

void QueuePush(Queue* q, QUDataType x);

void QueuePop(Queue* q);

int QueueSize(Queue* q);

int QueueEmpty(Queue* q);

QUDataType QueueFront(Queue* q);

QUDataType QueueBack(Queue* q);

void QueueTest();