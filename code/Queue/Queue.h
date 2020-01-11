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
	QueueNode* _front; // 队头
	QueueNode* _rear; // 队尾
}Queue;

void QueueInit(Queue* pq);
QueueNode* NewQueueNode(QUDataType x);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QUDataType x);//入队（尾插）
void QueuePop(Queue* pq);//出队（头删）
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
void TestQueue();