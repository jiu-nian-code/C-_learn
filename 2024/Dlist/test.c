#define _CRT_SECURE_NO_WARNINGS 1

#include"Dlist.h"

void TestList1()
{
	ListNode*  Phead = ListCreate();
	ListPushBack(Phead, 1);
	ListPushBack(Phead, 2);
	ListPushBack(Phead, 3);
	ListPushBack(Phead, 4);
	ListPopBack(Phead);
	ListPopBack(Phead);
	ListPopBack(Phead);
	ListPushFront(Phead, 2);
	ListPushFront(Phead, 3);
	ListPushFront(Phead, 4);
	ListPopFront(Phead);
	ListPopFront(Phead);
	//ListPopFront(Phead);
	//ListPopBack(Phead);
	//ListPopBack(Phead);
	ListInsert(Phead->_next->_next, 5);
	//ListErase(Phead->_next->_next);
	ListPrint(Phead);
	printf("\n");
	ListNode*  find = ListFind(Phead, 10);
	if (find == NULL)
	{
		printf("Ã»ÕÒµ½");
		return;
	}
	printf("%d", find->_data);
}

int main()
{
	TestList1();

	return 0;
}