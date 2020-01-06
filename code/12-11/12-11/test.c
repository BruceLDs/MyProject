#include<stdio.h>
#include<malloc.h>
//1.编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
//
//给定一个链表的头指针 Node* pHead，请返回重新排列后的链表的头指针。
//注意：分割以后保持原来的数据顺序不变。
//typedef struct Node {
//int val;
//struct Node *next;
//}Node;
//
//Node* partition(Node* pHead, int x)
//{
//	if (pHead == NULL || pHead->next == NULL)
//		return pHead;
//	Node* Cur = pHead;
//	Node* LessHead = (Node*)malloc(sizeof(Node));
//	Node* GreatHead = (Node*)malloc(sizeof(Node));
//	Node* LessList = LessHead;
//	Node* GreatList = GreatHead;
//	while (Cur)
//	{
//		if (Cur->val < x)
//		{
//			LessHead->next = Cur;
//			LessHead = Cur;
//			Cur = Cur->next;
//		}
//		else
//		{
//			GreatHead->next = Cur;
//			GreatHead = Cur;
//			Cur = Cur->next;
//		}
//	}
//	LessHead->next = GreatList->next;
//	GreatHead->next = NULL;
//	return LessList->next;
//}

//2.对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//
//测试样例：
//1->2->2->1
//返回：true

//typedef struct Node {
//int val;
//struct Node *next;
//}Node;
//
//	int  chkPalindrome(Node* A)
//	{
//		Node* slow = A;
//		Node* fast = A;
//		Node* New = NULL;
//		while (fast != NULL && fast->next != NULL)
//		{
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//		while (slow)
//		{
//			Node* next1 = slow->next;
//			slow->next = New;
//			New = slow;
//			slow = next1;
//		}
//		while (New)
//		{
//			if (New->val != A->val)
//				return 1;
//			else
//			{
//				New = New->next;
//				A = A->next;
//			}
//
//		}
//		return -1;
//
//	}
//
	//int main()
	//{
	//	Node* p1 = (Node*)malloc(sizeof(Node));
	//	Node* p2 =  (Node*)malloc(sizeof(Node));
	//	Node* p3 = (Node*)malloc(sizeof(Node));
	//	Node* p4 = (Node*)malloc(sizeof(Node));
	//	Node* p5 = (Node*)malloc(sizeof(Node));
	//	Node* p6 = (Node*)malloc(sizeof(Node));
	//	//p1->val = 1;
	//	//p2->val = 2;
	//	//p3->val = 5;
	//	//p4->val = 5;
	//	//p5->val = 2;
	//	//p6->val = 1;
	//	//p1->next = p2;
	//	//p2->next = p3;
	//	//p3->next = p4;
	//	//p4->next = p5;
	//	//p5->next = p6;
	//	//p6->next = NULL;
	//	p1->val = 1;
	//	p2->val = 2;
	//	p3->val = 2;
	//	p4->val = 2;
	//	p5->val = 1;
	//	p1->next = p2;
	//	p2->next = p3;
	//	p3->next = p4;
	//	p4->next = p5;
	//	p5->next = NULL;

	//int ret = chkPalindrome(p1);
	//if (ret == 1)
	//{
	//	printf("不是\n");
	//}
	//else
	//	printf("是\n");
	//return 0;
	//}

//3.编写一个程序，找到两个单链表相交的起始节点。
// struct Node {
//     int val;
//     struct Node *next;
// };
//
//typedef struct Node Node;
//struct Node *getIntersectionNode(struct Node *headA, struct Node *headB)
//{
//	int ret = 0;
//	int lenA = 0;
//	int lenB = 0;
//	Node* curA = headA;   
//	Node* curB = headB;
//	while (curA || curB)
//	{
//		if (curA)
//		{
//			curA = curA->next;
//			++lenA;
//		}
//		if (curB)
//		{
//			curB = curB->next;
//			++lenB;
//		}
//	}
//	ret = abs(lenA - lenB);
//	if (lenA > lenB)
//	{
//		while (ret)
//		{
//			headA = headA->next;
//			--ret;
//		}
//		while (headA)
//		{
//			if (headA == headB)
//				return headA;
//			else
//			{
//				headA = headA->next;
//				headB = headB->next;
//			}
//		}
//	}
//	else
//	{
//		while (ret)
//		{
//			headB = headB->next;
//			--ret;
//		}
//		while (headA)
//		{
//			if (headA == headB)
//				return headA;
//			else
//			{
//				headA = headA->next;
//				headB = headB->next;
//			}
//		}
//	}
//
//	return NULL;
//
//}
//int main()
//{
//	Node* p1 = (Node*)malloc(sizeof(Node));
//	Node* p2 = (Node*)malloc(sizeof(Node));
//	Node* p3 = (Node*)malloc(sizeof(Node));
//	Node* p4 = (Node*)malloc(sizeof(Node));
//	Node* p5 = (Node*)malloc(sizeof(Node));
//	Node* p6 = (Node*)malloc(sizeof(Node));        //4 1 8 4 5        5 0 1 8 4 5
//	Node* p7 = (Node*)malloc(sizeof(Node));
//	Node* p8 = (Node*)malloc(sizeof(Node));
//	Node* p9 = (Node*)malloc(sizeof(Node));
//	Node* p10 = (Node*)malloc(sizeof(Node));
//	Node* p11= (Node*)malloc(sizeof(Node));
//	p1->val = 4;
//	p2->val = 1;
//	p3->val = 8;
//	p4->val = 4;
//	p5->val = 5;
//	p1->next = p2;
//	p2->next = p3;
//	p3->next = p4;
//	p4->next = p5;
//	p5->next = NULL;
//
//	p6->val = 5;
//	p7->val = 0;
//	p8->val = 1;
//	p9->val = 8;
//	p10->val =4;
//	p11->val = 5;
//	p6->next = p7;
//	p7->next = p8;
//	p8->next = p9;
//	p9->next = p10;
//	p10->next = p11;
//	p11->next = NULL;
//
//	getIntersectionNode(p1, p6);
//}


