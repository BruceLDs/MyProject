#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include<malloc.h>

typedef int SeqDataType;   //����
typedef struct SeqList
{
	SeqDataType *s;   //ָ��̬���ٵ�����
	size_t size;       //��Ч���ݵĳ���
	size_t capicity; // unsigned int     //����
}SeqList;

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SeqDataType x);
void SeqListPushFront(SeqList* ps, SeqDataType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// ˳������
void SeqListFind(SeqList* ps, SeqDataType x);
// ˳�����posλ�ò���x
int SeqListInsert(SeqList* ps, size_t pos, SeqDataType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);