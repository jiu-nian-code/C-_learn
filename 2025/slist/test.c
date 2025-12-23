#include"slist.h"

void test1()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
}

void test2()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);
}

void test3()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	//SListPopBack(&plist);
	SListPrint(plist);
}

void test4()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	//SListPopFront(&plist);
	SListPrint(plist);
}

void test5()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListFind(plist, 1);
	SListFind(plist, 2);
	SListFind(plist, 3);
	SListFind(plist, 4);
	SListFind(plist, 0);
}

void test6()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListInsertAfter(plist->next, 5);
	SListInsertAfter(plist->next, 6);
	SListInsertAfter(plist->next, 7);
	SListInsertAfter(plist->next, 8);
	SListInsertAfter(plist->next, 9);
	SListPrint(plist);
}

void test7()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListInsertAfter(plist->next, 5);
	SListInsertAfter(plist->next, 6);
	SListInsertAfter(plist->next, 7);
	SListInsertAfter(plist->next, 8);
	SListInsertAfter(plist->next, 9);
	SListEraseAfter(plist->next);
	SListEraseAfter(plist->next);
	SListEraseAfter(plist->next);
	SListEraseAfter(plist->next);
	SListEraseAfter(plist->next);
	SListEraseAfter(plist->next);
	SListEraseAfter(plist->next);
	//SListEraseAfter(plist->next);
	SListPrint(plist);
}

int main()
{
	test6();
	return 0;
}