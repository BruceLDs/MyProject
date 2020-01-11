#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front; // ��ͷ
	QueueNode* _rear; // ��β
}Queue;

void QueueInit(Queue* pq);
QueueNode* NewQueueNode(QUDataType x);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QUDataType x);//��ӣ�β�壩
void QueuePop(Queue* pq);//���ӣ�ͷɾ��
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
void TestQueue();