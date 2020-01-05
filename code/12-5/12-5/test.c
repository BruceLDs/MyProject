//1.给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//
//如果有两个中间结点，则返回第二个中间结点。
//输入：[1, 2, 3, 4, 5]
//输出：此列表中的结点 3 (序列化形式：[3, 4, 5])
//返回的结点值为 3 。(测评系统对该结点序列化表述是[3, 4, 5])。
//注意，我们返回了一个 ListNode 类型的对象 ans，这样：
//ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
//示例 2：
//
//输入：[1, 2, 3, 4, 5, 6]
//输出：此列表中的结点 4 (序列化形式：[4, 5, 6])
//由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。

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


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

//2.删除链表中等于给定值 val 的所有节点。
//
//示例 :
//
//输入 : 1->2->6->3->4->5->6, val = 6
//输出 : 1->2->3->4->5
//typedef struct ListNode ListNode;
//struct ListNode* removeElements(struct ListNode* head, int val){
//	ListNode* prev = NULL, *cur = head;
//	while (cur != NULL)
//	{
//		if (cur->val == val)
//		{
//			ListNode* next = cur->next;
//			free(cur);
//			// 删除
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
