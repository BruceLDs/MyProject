#ifndef SeqList_H_

#include <time.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#define size_t unsigned
typedef int DataType;
typedef struct SeqList
{
	DataType *_array; // ָ��̬���ٵ�����
	size_t  _size; // ��Ч���ݸ���
	size_t  _capicity; // �����ռ�Ĵ�С
}SeqList;
// ������ɾ��Ľӿ�
void InitSeqList(SeqList* sl);//��ʼ��˳���
void SeqListCheakCapacity(SeqList *sl);
void SeqListDestory(SeqList* sl);//����
void CheckCapacity(SeqList* sl);//�������
void SeqListPushBack(SeqList* sl, DataType x);//β��
void SeqListPopBack(SeqList* sl);//βɾ
void SeqListPushFront(SeqList* sl, DataType x);//ͷ��
void SeqListPopFront(SeqList* sl);//ͷɾ
size_t SeqListFind(SeqList* sl, DataType pos);//����
void SeqListInsert(SeqList* sl, size_t pos, DataType x);//����
void SeqListErase(SeqList* sl, size_t pos);//��λ��ɾ��
void SeqListRemove(SeqList* sl, DataType x);//������ɾ��
void SeqListModify(SeqList* sl, size_t pos, DataType x);//�޸�
void SeqListPrint(SeqList* sl);// ���
void SeqListBubbleSort(SeqList* sl);//ð������
int SeqListBinaryFind(SeqList* sl, DataType x);// ���ֲ��� ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
void SeqListRemoveAll(SeqList* sl, DataType x);//ɾ������ȫΪx��
#endif