#define  _CRT_SECURE_NO_WARNINGS
#include "LIST.H"

void InitList(pList plsit)
{
	assert(plsit != NULL);
	plsit->data = -1;
	plsit->next = NULL;
}

//得到一个节点
Node *GetNode(int val)
{
	Node *pGet = (Node *)malloc(sizeof(Node));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}

//头插   plist:  头结点的地址
void InsertHead(pList plist, int val)//55
{
	Node *pGet = GetNode(val);
	assert(plist != NULL);
	pGet->next = plist->next;
	plist->next = pGet;
}

void InsertTail(pList plist, int val){
	Node *pGet = GetNode(val);
	Node *p = plist;
	assert(plist != NULL);
	while (p->next != NULL){
		p = p->next;
	}
	p->next = pGet;
}

Node *LastNode(pList plist, int k){

	Node *p = plist;
	Node *q = plist;
	assert(plist != NULL);
	while (--k){
		if (p->next == NULL){
			return NULL;
		}
		p = p->next;
	}
	while (p->next != NULL){
		p = p->next;
		q = q->next;
	}
	return q;
	//printf("%p为第k个节点的地址，%d为第k个节点的值",q, q->data);
}
void Delete(pList plist, int k){
	Node *p = plist;
	Node *q;
	assert(plist != NULL);
	while (--k){
		if (p->next != NULL){
			p = p->next;
		}
		else{
			printf("未找到你想删除的节点！\n");
			return;
		}
	}
	q = p -> next;
	p->next = q->next;
	printf("删除成功！\n");
}
void InverseList(pList plist){
	Node *pCur = plist->next;
	Node *pCurN = NULL;
	assert(plist != NULL);
	plist->next = NULL;
	while (pCur!=NULL){
		pCurN = pCur->next;
		pCur->next = plist->next;
		plist->next = pCur;
		pCur = pCurN;
	}
}

Node* ReverseLink(pList plist){
	Node *rever_Head = NULL;
	Node *prev = NULL;
	Node *pCur = plist;
	Node *pCurN = NULL;
	assert(plist != NULL);
	while (pCur != NULL){
		pCurN = pCur->next;
		if (pCurN == NULL){
			rever_Head = pCur;
		}
		pCur->next = prev;
		prev = pCur;
		pCur = pCurN;
	}
	return rever_Head;
}
void Show(pList plist)
{
	Node *p = plist->next;
	assert(plist != NULL);
	p = plist->next;
	while (p != NULL){
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}
void Show1(pList plist)
{
	Node *p = plist;
	assert(plist != NULL);
	while (p != NULL){
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

Node *FindMidleNode(pList plist)
{
	Node *pFast = plist->next;
	Node *pSlow = plist->next;
	while (pFast != NULL&&pFast->next != NULL)
	{
			pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}