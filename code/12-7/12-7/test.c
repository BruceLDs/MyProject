//1.����һ����������������е�����k����㡣
//
//struct ListNode {
//int val;
//struct ListNode *next;
//ListNode(int x) :
//val(x), next(NULL) {
//}
//};
//typedef struct ListNode Node;
//class Solution {
//public:
//	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//		Node* quick = pListHead;
//		Node* slow = pListHead;
//		Node* ret = NULL;
//		int i = 0;
//		if (k == 0)
//			return NULL;
//
//		while (quick)
//		{
//			quick = quick->next;
//			++i;
//			if (i >= k)
//			{
//				ret = slow;
//				slow = slow->next;
//			}
//		}
//		return ret;
//	}
//};
//2.ɾ�������е��ڸ���ֵ val �����нڵ㡣
//
//ʾ�� :
//
//���� : 1->2->6->3->4->5->6, val = 6
//��� : 1->2->3->4->5
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

//typedef struct ListNode ListNode;
//struct ListNode* removeElements(struct ListNode* head, int val){
//	ListNode* prev = NULL, *cur = head;
//	while (cur != NULL)
//	{
//		if (cur->val == val)
//		{
//			ListNode* next = cur->next;
//			free(cur);
//			// ɾ��
//			if (cur == head)
//			{
//				head = next;
//			}
//			else
//			{
//				prev->next = next;
//			}
//
//			cur = next;
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//
//	return head;
//}
//3.��תһ��������
//
//ʾ�� :
//
//���� : 1->2->3->4->5->NULL
//��� : 5->4->3->2->1->NULL
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

//typedef struct ListNode Node;
//struct ListNode* reverseList(struct ListNode* head)
//{
//	Node* cur = head;
//	Node* newNode = NULL;
//	while (cur)
//	{
//		Node* next = cur->next;
//		cur->next = newNode;
//		newNode = cur;
//		cur = next;
//	}
//
//	return newNode;

//4.����һ������ͷ��� head �ķǿյ���������������м��㡣
//
//����������м��㣬�򷵻صڶ����м��㡣
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

//
//typedef struct ListNode ListNode;
//struct ListNode* middleNode(struct ListNode* head){
//	ListNode* slow = head, *fast = head;
//	//while(!(fast == NULL || fast->next == NULL))
//	while (fast != NULL && fast->next != NULL)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//
//	return slow;
//}