#ifndef SeqList_H_

#include <time.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#define size_t unsigned
typedef int DataType;
typedef struct SeqList
{
	DataType *_array; // 指向动态开辟的数组
	size_t  _size; // 有效数据个数
	size_t  _capicity; // 容量空间的大小
}SeqList;
// 基本增删查改接口
void InitSeqList(SeqList* sl);//初始化顺序表
void SeqListCheakCapacity(SeqList *sl);
void SeqListDestory(SeqList* sl);//销毁
void CheckCapacity(SeqList* sl);//检查容量
void SeqListPushBack(SeqList* sl, DataType x);//尾插
void SeqListPopBack(SeqList* sl);//尾删
void SeqListPushFront(SeqList* sl, DataType x);//头插
void SeqListPopFront(SeqList* sl);//头删
size_t SeqListFind(SeqList* sl, DataType pos);//查找
void SeqListInsert(SeqList* sl, size_t pos, DataType x);//插入
void SeqListErase(SeqList* sl, size_t pos);//按位置删除
void SeqListRemove(SeqList* sl, DataType x);//按内容删除
void SeqListModify(SeqList* sl, size_t pos, DataType x);//修改
void SeqListPrint(SeqList* sl);// 输出
void SeqListBubbleSort(SeqList* sl);//冒泡排序
int SeqListBinaryFind(SeqList* sl, DataType x);// 二分查找 时间复杂度：O(N) 空间复杂度 O(1)
void SeqListRemoveAll(SeqList* sl, DataType x);//删除内容全为x的
#endif