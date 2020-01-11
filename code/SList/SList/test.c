#include "sList.h"

void TestSList1()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);

	SListPrint(pList);

	SListPushFront(&pList, 0);
	SListPrint(pList);

	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrint(pList);
}

void TestSList2()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);

	SListNode* ret = SListFind(pList, 3);
	//ret->data = 30;
	SListInsertAfter(ret, 30);
	SListPrint(pList);

	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrint(pList);
}


void TestSList3()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);

}
//int main()
//{
//	TestSList3();
//
//	return 0;
//}

//// Definition for singly - linked list.
// struct ListNode {
//	int val;
//	struct ListNode *next;
//	
//};
//
//typedef struct ListNode Node;
//
//struct ListNode* reverseList(struct ListNode* head){
//	Node* n1, *n2, *n3;
//
//	if (head == NULL || head->next == NULL)
//		return head;
//
//	n1 = NULL;
//	n2 = head;
//	n3 = n2->next;
//
//	while (n2)
//	{
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//		if (n3)
//			n3 = n3->next;
//	}
//
//	return n1;
//}
//
//int main()
//{
//	Node* n1 = (Node*)malloc(sizeof(Node));
//	Node* n2 = (Node*)malloc(sizeof(Node));
//	Node* n3 = (Node*)malloc(sizeof(Node));
//	Node* n4 = (Node*)malloc(sizeof(Node));
//	Node* n5 = (Node*)malloc(sizeof(Node));
//	n1->val = 1;
//	n2->val = 2;
//	n3->val = 3;
//	n4->val = 4;
//	n5->val = 5;
//
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = NULL;
//
//	reverseList(n1);
//
//	TestSList2();
//
//	return 0;
//}


struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode Node;
Node* FindKthToTail(Node* pListHead, unsigned int k) {
	Node* fast = pListHead;
	Node* slow = pListHead;

	while (k--)
	{
		if (fast == NULL)
			return NULL;

		fast = fast->next;
	}

	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}

int main()
{
	Node* n1 = (Node*)malloc(sizeof(Node));
	Node* n2 = (Node*)malloc(sizeof(Node));
	Node* n3 = (Node*)malloc(sizeof(Node));
	Node* n4 = (Node*)malloc(sizeof(Node));
	Node* n5 = (Node*)malloc(sizeof(Node));
	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 4;
	n5->val = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	Node* ret = FindKthToTail(n1, 10);

	//TestSList2();

	return 0;
}
