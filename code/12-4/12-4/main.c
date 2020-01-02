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
	SeqListPopBack(s);   //βɾ
	SeqListPopFront(s);   //ͷɾ
	SeqListPrint(s);   
	printf("\n");
	SeqListPushFront(s, 100);    //ͷ��
	SeqListPrint(s);
	printf("\n");
	SeqListInsert(s, 2, 500);   //�����
	SeqListPrint(s);
	printf("\n");
	SeqListPopFront(s);  //ͷɾ
	SeqListPrint(s);
	printf("\n");
	SeqListErase(s, 2);  //����ɾ
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