#define _CRT_SECURE_ NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int SLTDateType;
typedef struct SlistNode
{
	SLTDateType val;
	struct SlistNode* next;
}SlistNode;
//开辟节点
SlistNode* CreatSlistNode(SLTDateType x);
//打印链表
void SlistPrint(SlistNode* head);
//尾插
void SlistPushBack(SlistNode* head, SLTDateType x);
//头插
void SlistPushFront(SlistNode* head, SLTDateType x);
//尾删
void SlistPopBack(SlistNode* head, SLTDateType x);
//头删
void SlistPopFront(SlistNode* head, SLTDateType x);
//查找
void SlistFind(SlistNode* head, SLTDateType x);
//在pos处插入（pos后面插入）
void SlistInsterAfter(SlistNode* pos, SLTDateType x);
//在pos处删除（pos后面删除）
void SlistEraseAfter(SlistNode* pos, SLTDateType x);