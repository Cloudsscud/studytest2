#include "DoubleList.h"

void List_test1()
{
	ListNode* phead = NULL;
	phead = ListInit(phead);
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushFront(phead, -1);
	ListPushFront(phead, 2);
	ListPrint(phead);

	ListPopBack(phead);
	ListPopBack(phead);
	/*ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);	*/
	ListPrint(phead);

	ListPopFront(phead);
	ListPopFront(phead);
	/*ListPopFront(phead);
	ListPopFront(phead);
	ListPopFront(phead);*/
	ListPrint(phead);

	ListDestroy(&phead);
}

void List_test2()
{
	ListNode* phead = NULL;
	phead = ListInit(phead);

	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);

	ListNode* pos = ListFind(phead,3);
	ListInsert(pos, 30);
	ListErase(pos);
	ListPrint(phead);

	ListDestroy(&phead);
}
int main()
{
	List_test1();

	//List_test2();
	return 0;
}