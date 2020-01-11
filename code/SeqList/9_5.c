#define  _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
test(SeqList *s)
{
	InitSeqList(s);
	SeqListPushBack( s, 5);
	SeqListPushBack( s, 4);
	SeqListPushBack( s, 3);
	SeqListPushBack( s, 2);
	SeqListPushBack( s, 1);
	SeqListPushBack( s, 0);
	SeqListPrint(s);
	printf("\n");
	//SeqListDestory(s);
	SeqListPopBack(s);
	SeqListPopBack(s);
	SeqListPrint(s);
	printf("\n");
	SeqListPushFront(s, 666);
	SeqListPrint(s);
	printf("\n");
	SeqListInsert(s, 2, 999);
	SeqListPrint(s);
	printf("\n");
	SeqListPopFront(s);
	SeqListPrint(s);
	printf("\n");
	SeqListErase(s, 2);
	SeqListPrint(s);
	printf("\n");
	printf("%d\n",SeqListFind(s,1));
	printf("%d\n",SeqListFind(s,2));
	printf("%d\n",SeqListFind(s,3)); 
	SeqListModify(s, 3, 111);
	SeqListPrint(s);
	printf("\n");
}
int main()
{
	SeqList s;
	test(&s);
	return 0;
}