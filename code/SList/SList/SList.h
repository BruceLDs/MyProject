#pragma once

#include <stdio.h>
#include <malloc.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data; // val
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* pList);
void SListPushBack(SListNode** ppList, SLTDataType x);
void SListPushFront(SListNode** ppList, SLTDataType x);

void SListPopBack(SListNode** ppList);
void SListPopFront(SListNode** ppList);

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDataType x);
// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 单链表删除pos位置之后的值

void SListEraseAfter(SListNode* pos);


void SListDestory(SListNode** pplist);