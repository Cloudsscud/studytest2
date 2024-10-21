#include "DoubleList.h"

ListNode* BuyListNode(TypeData x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->val = x;
	return newnode;
}

ListNode* ListInit(ListNode* phead)
{
	phead = BuyListNode(0);
	phead->prev = phead;
	phead->next = phead;
	return phead;
}

void ListClear(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	phead->prev = phead;
	phead->next = phead;
}

void ListDestroy(ListNode** pphead)
{
	assert(*pphead);
	ListClear(*pphead);
	free(*pphead);
	*pphead = NULL;
}

ListNode* ListPushBack(ListNode* phead, TypeData x)
{
	/*assert(phead);
	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
	return phead;*/

	ListInsert(phead, x);
}

void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void ListPopBack(ListNode* phead)
{
	/*assert(phead);
	ListNode* tail = phead->prev;
	if(tail != phead)
	{
		ListNode* newtail = tail->prev;
		phead->prev = newtail;
		newtail->next = phead;
		free(tail);
	}
	else {
		printf("warning!no value to pop!\n");
	}*/
	assert(phead);
	ListNode* tail = phead->prev;
	if (tail != phead)
	{
		ListErase(phead->prev);
	}
	else 
	{
		printf("Warning!No value to pop now!\n");
	}
}

ListNode* ListPushFront(ListNode* phead, TypeData x)
{
	/*assert(phead);
	ListNode* newnode = BuyListNode(x);
	ListNode* first = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
	return phead;*/
	ListInsert(phead->next, x);
}

void ListPopFront(ListNode* phead)
{
	/*assert(phead);
	ListNode* first = phead->next;
	if (first != phead)
	{
		ListNode* newfirst = first->next;
		phead->next = newfirst;
		newfirst->prev = phead;
		free(first);
	}
	else{
		printf("warning!no value to pop!\n");
	}*/
	assert(phead);
	ListNode* first = phead->next;
	if (first != phead)
	{
		ListErase(first);
	}
	else{
		printf("warning!no value to pop!\n");
	}
}

ListNode* ListFind(ListNode* phead, TypeData x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos,TypeData x)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;

}