#include"test.h"

//反转一个单链表。

//示例:
//
//输入 : 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL
typedef struct ListNode 
{
    int val;
    struct ListNode *next;
}ListNode, Node;


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	ListNode* cur = l1;
	ListNode* ret = l2;
	ListNode* NewNode = NULL;
	//if (l1 == NULL)
	//	return l2;
 //   if (l2 == NULL)
	//	return l1;
	while (cur && ret)
	{
		if (cur == NULL && ret != NULL)
		{
			ListNode* next2 = ret->next;
			ret->next = NewNode;
			NewNode = ret;
			ret = next2;
		}
		else if(cur != NULL && ret == NULL)
		{
			ListNode* next1 = cur->next;
			cur->next = NewNode;
			NewNode = cur;
			cur = next1;
		}
		if (cur->val <= ret->val)
		{
			ListNode* next1 = cur->next;
			cur->next = NewNode;
			NewNode = cur;
			cur = next1;
		}
		else
		{
			ListNode* next2 = ret->next;
			ret->next = NewNode;
			NewNode = ret;
			ret = next2;
		}
	}
	return NewNode;
}
struct ListNode* reverseList(struct ListNode* head)
{
	Node* cur = head;
	Node* newNode = NULL;
	while (cur)
	{
		Node* next = cur->next;
		cur->next = newNode;
		newNode = cur;
		cur = next;
	}

	return newNode;
}
int main()
{

	ListNode* p1 = (ListNode *)malloc(sizeof(ListNode));
	ListNode* p2 = (ListNode *)malloc(sizeof(ListNode));
	ListNode* p3 = (ListNode *)malloc(sizeof(ListNode));
	ListNode* p4 = (ListNode *)malloc(sizeof(ListNode));
	ListNode* p5 = (ListNode *)malloc(sizeof(ListNode));
	ListNode* p6 = (ListNode *)malloc(sizeof(ListNode));
	ListNode* head = (ListNode *)malloc(sizeof(ListNode));
	p1->val = 1;
	p2->val = 2;
	p3->val = 4;
	p4->val = 1;
	p5->val = 3;
	p6->val = 4;
	p1->next = p2;
	p2->next = p3;
	p3->next = NULL;
	p4->next = p5;
	p5->next = p6;
	p6->next = NULL;
	head ->next = mergeTwoLists(p1, p4);
	reverseList(head);
}
// 模拟栈列
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define SizeOfQueue 6
//
//typedef struct Queue
//{
//	int data[SizeOfQueue];
//	int head;
//	int tail;
//	int cnt;
//}queue;
//queue* queue_init()
//{
//	queue* qe = (queue*)malloc(sizeof(queue));
//	if (NULL == qe)
//	{
//		printf("Init queue erroe");
//		exit(1);
//	}
//	memset(qe, 0, sizeof(queue));
//	qe->head = 0;
//	qe->tail = SizeOfQueue - 1;
//	qe->cnt = 0;
//	return qe;
//};
//void en_queue(queue* qe, int data1)
//{
//	if (qe->cnt == SizeOfQueue)//判断栈满；
//	{
//		printf("Queue is full");
//		exit(1);
//	}
//	qe->tail = (qe->tail + 1) % SizeOfQueue;
//	qe->data[qe->tail] = data1;
//	qe->cnt += 1;
//};
//void de_queue(queue* qe)
//{
//	int tmp_data;
//	if (qe->cnt == 0)
//	{
//		printf("Queue is empty");
//		exit(1);
//	}//判断栈空
//	tmp_data = qe->data[qe->head];
//	qe->head = (qe->head + 1) % SizeOfQueue;
//	qe->cnt -= 1;
//};
//int main()
//{
//	queue* que;
//	que = queue_init();
//	int data[5] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < 5; i++)
//	{
//		en_queue(que, data[i]);
//	}
//	de_queue(que);
//	de_queue(que);
//	en_queue(que, 6);
//	en_queue(que, 7);
//	en_queue(que, 8);
//	en_queue(que, 9);
//};