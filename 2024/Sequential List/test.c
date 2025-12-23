#include"SeqList.h" 

int main()
{
	SeqList list;
	SeqListInit(&list);
	SeqListPushBack(&list, 1);
	SeqListPushBack(&list, 2);
	SeqListPushBack(&list, 3);
	SeqListPushBack(&list, 4);
	SeqListPushBack(&list, 5);
	SeqListPushFront(&list, -1);
	SeqListPushFront(&list, -2);
	SeqListPushFront(&list, -3);
	SeqListPushFront(&list, -4);
	SeqListPushFront(&list, -5);
	SeqListPrint(&list);
	SeqListPopFront(&list);
	SeqListPopBack(&list);
	SeqListPrint(&list);
	SeqListFind(&list, 1);
	SeqListInsert(&list, 3, 5);
	SeqListPrint(&list);
	SeqListErase(&list, 6);
	SeqListPrint(&list);
	return 0;
}