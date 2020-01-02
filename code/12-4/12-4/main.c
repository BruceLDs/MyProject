#include"test.h"

test(SeqList *s)
{
	SeqListInit(s);
	SeqListPushBack(s, 10);
	SeqListPushBack(s, 9);
	SeqListPushBack(s, 8);
	SeqListPushBack(s, 7);
	SeqListPushBack(s, 6);
	SeqListPushBack(s, 5);
	SeqListPrint(s);
	printf("\n");
	//SeqListDestory(s);
	SeqListPopBack(s);   //尾删
	SeqListPopFront(s);   //头删
	SeqListPrint(s);   
	printf("\n");
	SeqListPushFront(s, 100);    //头插
	SeqListPrint(s);
	printf("\n");
	SeqListInsert(s, 2, 500);   //任意插
	SeqListPrint(s);
	printf("\n");
	SeqListPopFront(s);  //头删
	SeqListPrint(s);
	printf("\n");
	SeqListErase(s, 2);  //任意删
	SeqListPrint(s);
	printf("\n");
    SeqListFind(s, 7);
    SeqListFind(s, 6);
    SeqListFind(s, 3);
	SeqListPrint(s);
	printf("\n");
}
int main()
{
	SeqList s;
	test(&s);
	return 0;
}