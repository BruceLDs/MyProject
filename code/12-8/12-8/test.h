#include<stdio.h>
#include<malloc.h>

typedef int SLTdataType;
typedef struct pListNode
{
	SLTdataType val;
	struct pListNode* next;
}pListNode;
