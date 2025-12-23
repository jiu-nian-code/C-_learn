#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<stdlib.h>

#include<stdbool.h>

//设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
//
//循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
//
//你的实现应该支持如下操作：
//
//MyCircularQueue(k) : 构造器，设置队列长度为 k 。
//Front : 从队首获取元素。如果队列为空，返回 - 1 。
//Rear : 获取队尾元素。如果队列为空，返回 - 1 。
//enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
//deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
//isEmpty() : 检查循环队列是否为空。
//isFull() : 检查循环队列是否已满。

typedef struct Queue {
    int _data;
    struct Queue* _next;
}Queue;


typedef struct {
    Queue* _Front;
    Queue* _rear;
    int _max;
    int _size;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return !(obj->_size);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->_rear && obj->_Front == obj->_rear->_next && obj->_size != 0;
}

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* newcQueue = (MyCircularQueue*)calloc(1, sizeof(MyCircularQueue));
    int num = k;
    while (num--)
    {
        Queue* newnode = (Queue*)calloc(1, sizeof(Queue));
        if (newcQueue->_Front == NULL)
        {
            newcQueue->_Front = newcQueue->_rear = newnode;
        }
        else
        {
            newcQueue->_rear->_next = newnode;
            newcQueue->_rear = newnode;
        }
    }
    newcQueue->_rear->_next = newcQueue->_Front;
    newcQueue->_rear = NULL;
    newcQueue->_max = k;
    return newcQueue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    if (obj->_rear == NULL)
    {
        obj->_Front->_data = value;
        obj->_rear = obj->_Front;
    }
    else
    {
        obj->_rear->_next->_data = value;
        obj->_rear = obj->_rear->_next;
    }
    ++obj->_size;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->_Front = obj->_Front->_next;
    --obj->_size;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->_Front;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->_rear;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    Queue* curr = obj->_Front;
    int k = obj->_max - 1;
    while (k--)
    {
        Queue* prev = curr;
        curr = curr->_next;
        free(prev);
    }
    free(curr);
    free(obj);
}


void test1()
{
    MyCircularQueue* obj = myCircularQueueCreate(3);
    myCircularQueueEnQueue(obj, 1);
    myCircularQueueEnQueue(obj, 2);
    myCircularQueueEnQueue(obj, 3);
    myCircularQueueEnQueue(obj, 3);
    myCircularQueueFree(obj);
}


int main()
{
    test1();
    return 0;
}




/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/