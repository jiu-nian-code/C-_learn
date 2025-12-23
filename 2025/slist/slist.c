#include"slist.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = calloc(1, sizeof(SListNode));
	newnode->data = x;
	if (newnode == NULL)
	{
		perror("BuySListNode:calloc");
		return NULL;
	}
	return newnode;
}

void SListPrint(SListNode* plist)
{
	for (SListNode* curr = plist; curr != NULL; curr = curr->next)
	{
		printf("%d -> ", curr->data);
	}
	printf("NULL");
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* curr = *(pplist);
	SListNode* newnode = BuySListNode(x);
	if (curr == NULL)
	{
		*(pplist) = newnode;
		return;
	}
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = newnode;
}

void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* curr = *(pplist);
	SListNode* newnode = BuySListNode(x);
	newnode->next = *(pplist);
	*(pplist) = newnode;
}

void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	SListNode* curr = *(pplist);
	SListNode* prev = NULL;
	if (curr->next == NULL)
	{
		*(pplist) = NULL;
		free(curr);
		curr = NULL;
		return;
	}
	//while (curr->next != NULL)
	//{
	//	prev = curr;
	//	curr = curr->next;
	//}
	//prev->next = NULL;
	//free(curr);
	//curr = NULL;
	while (curr->next->next != NULL)
	{
		curr = curr->next;
	}
	free(curr->next);
	curr->next= NULL;
}

void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* curr = *(pplist);
	*(pplist) = (*(pplist))->next;
	free(curr);
	curr = NULL;
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* curr = plist;
	int num = 1;
	while (curr != NULL)
	{
		if (curr->data = x)
		{
			printf("找到了，是第%d个元素。\n", curr->data);
			return NULL;
		}
		curr = curr->next;
		num++;
	}
	printf("找不到。\n");
}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* curr = pos;
	SListNode* newnode = BuySListNode(x);
	newnode->next = curr->next;
	curr->next = newnode;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos && pos->next);
	SListNode* dock = pos->next->next;
	free(pos->next);
	pos->next = dock;
}