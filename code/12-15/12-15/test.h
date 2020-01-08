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
//���ٽڵ�
SlistNode* CreatSlistNode(SLTDateType x);
//��ӡ����
void SlistPrint(SlistNode* head);
//β��
void SlistPushBack(SlistNode* head, SLTDateType x);
//ͷ��
void SlistPushFront(SlistNode* head, SLTDateType x);
//βɾ
void SlistPopBack(SlistNode* head, SLTDateType x);
//ͷɾ
void SlistPopFront(SlistNode* head, SLTDateType x);
//����
void SlistFind(SlistNode* head, SLTDateType x);
//��pos�����루pos������룩
void SlistInsterAfter(SlistNode* pos, SLTDateType x);
//��pos��ɾ����pos����ɾ����
void SlistEraseAfter(SlistNode* pos, SLTDateType x);