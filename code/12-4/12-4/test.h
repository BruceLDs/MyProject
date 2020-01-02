#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include<malloc.h>

typedef int SeqDataType;   //数据
typedef struct SeqList
{
	SeqDataType *s;   //指向动态开辟的数组
	size_t size;       //有效数据的长度
	size_t capicity; // unsigned int     //容量
}SeqList;

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SeqDataType x);
void SeqListPushFront(SeqList* ps, SeqDataType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// 顺序表查找
void SeqListFind(SeqList* ps, SeqDataType x);
// 顺序表在pos位置插入x
int SeqListInsert(SeqList* ps, size_t pos, SeqDataType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos);