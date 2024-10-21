#pragma once;
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int TypeData;

//双向有头循环链表
typedef struct ListNode ListNode;
struct ListNode
{
	ListNode* prev;
	ListNode* next;
	TypeData val;
};

ListNode* ListInit(ListNode* phead);
void ListClear(ListNode* phead);
void ListDestroy(ListNode** pphead);
ListNode* BuyListNode(TypeData x);
ListNode* ListPushBack(ListNode* phead, TypeData x);
void ListPopBack(ListNode* phead);
void ListPrint(ListNode* phead);
ListNode* ListPushFront(ListNode* phead, TypeData x);
void ListPopFront(ListNode* phead);
ListNode* ListFind(ListNode* phead, TypeData x);
void ListInsert(ListNode* pos, TypeData x);
void ListErase(ListNode* pos);