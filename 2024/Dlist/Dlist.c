#define _CRT_SECURE_NO_WARNINGS 1

#include"Dlist.h"


ListNode* ListCreate()
{
	ListNode* newnode = calloc(1, sizeof(ListNode));
	newnode->_next = newnode;
	newnode->_prev = newnode;
	return newnode;
}

void ListDestory(ListNode* pHead)
{
	ListNode* curr = pHead;
	ListNode* prev = NULL;
	do
	{
		ListNode* prev = curr;
		curr = curr->_next;
		free(prev);
	} while (curr != pHead);
}

void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* curr = pHead->_next;
	printf("<=> head <=> ");
	while (curr != pHead)
	{
		printf("%d <=> ", curr->_data);
		curr = curr->_next;
	}
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListNode* newnode = buynode(x);
	newnode->_next = pHead;
	newnode->_prev = pHead->_prev;
	pHead->_prev->_next = newnode;
	pHead->_prev = newnode;
}

ListNode* buynode(LTDataType x)
{
	ListNode* newnode = calloc(1, sizeof(ListNode));
	newnode->_data = x;
	return newnode;
}

void ListPopBack(ListNode* pHead)
{
	assert(pHead->_next != pHead);
	ListNode* dele = pHead->_prev;
	dele->_prev->_next = dele->_next;
	dele->_next->_prev = dele->_prev;
	free(dele);
	dele = NULL;
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListNode* newnode = buynode(x);
	newnode->_next = pHead->_next;
	newnode->_prev = pHead->_next->_prev;
	pHead->_next->_prev = newnode;
	pHead->_next = newnode;
}

void ListPopFront(ListNode* pHead)
{
	assert(pHead->_prev != pHead);
	ListNode* dele = pHead->_next;
	dele->_prev->_next = dele->_next;
	dele->_next->_prev = dele->_prev;
	free(dele);
	dele = NULL;
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	ListNode* curr = pHead->_next;
	while (curr != pHead)
	{
		if (curr->_data == x)
		{
			return curr;
		}
		curr = curr->_next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newnode = buynode(x);
	newnode->_next = pos;
	newnode->_prev = pos->_prev;
	pos->_prev->_next = newnode;
	pos->_prev = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos && pos->_next != pos);
	ListNode* dele = pos;
	dele->_prev->_next = dele->_next;
	dele->_next->_prev = dele->_prev;
	free(dele);
	dele = NULL;
}