#define  _CRT_SECURE_NO_WARNINGS
#include"LIST.H"
int main(){
	Node head;
	Node *q;
	InitList(&head);
	InsertHead(&head, 1);
	InsertHead(&head, 2);
	InsertHead(&head, 3);
	InsertHead(&head, 4);
	InsertHead(&head, 5);
	InsertHead(&head, 6);
	InsertHead(&head, 7);
	InsertHead(&head, 8);
	Show(&head);
	Node *m = FindMidleNode(&head);//查找中间节点
	printf("%d\n", m->data);
	q=LastNode(&head, 4); 
	printf("%d\n", q->data);
	Delete(&head,4);
	Show(&head);
	InverseList(&head);
	Show(&head);
	Node *p = ReverseLink(&head);
	Show1(p);
	return 0;
}