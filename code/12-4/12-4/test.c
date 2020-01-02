#include"test.h"

void SeqListInit(SeqList* ps)  //初始化
{
	ps->size = 0;
	ps->capicity = 0;
	ps->s = NULL;

}
void CheckSeq(SeqList *ps)   //核对空间是否满了
{
	if (ps->size == ps->capicity)
	{
		int Newcapicity =ps->capicity == 0 ? 4 : ps->capicity * 2;
		ps->s = (SeqDataType*)realloc(ps->s, sizeof(SeqDataType)*Newcapicity);
	}
}
void SeqListDestory(SeqList* ps)    //销毁
{
	assert(ps);
	free(ps->s);
	ps->s = NULL;
}

void SeqListPrint(SeqList* ps)   //打印
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->s[i]);
	}
	printf("\n");
}
void SeqListPushBack(SeqList* ps, SeqDataType x)    //尾插
{
	assert(ps);
	CheckSeq(ps);
	ps->s[ps->size] = x;
	++ps->size;
}
void SeqListPushFront(SeqList* ps, SeqDataType x)   //头插
{
	assert(ps);
	CheckSeq(ps);
	for (int i = ps->size - 1; i >= 0; --i)
	{
		ps->s[i + 1] = ps->s[i];
	}
	ps->s[0] = x;
	++ps->size; 
}
void SeqListPopFront(SeqList* ps)       //头删
{
	assert(ps);
	CheckSeq(ps);
	for (int i = 0; i < ps->size - 1; ++i)
	{
		ps->s[i] = ps->s[i + 1];
	}
	--ps->size;

}
void SeqListPopBack(SeqList* ps)       //尾删
{
	assert(ps);
	CheckSeq(ps);
	ps->s[ps->size - 1] = 0;
	--ps->size;
}

// 顺序表查找
void SeqListFind(SeqList* ps, SeqDataType x)
{
	assert(ps);
	CheckSeq(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->s[i] == x)
		{
			printf("数据的位置为%d\n", i+1);
			return;
		}
	}
	printf("查询的数据不存在\n");
}
// 顺序表在pos位置插入x
int SeqListInsert(SeqList* ps, size_t pos, SeqDataType x)
{
	assert(ps);
	CheckSeq(ps);
	for (int i = ps->size - 1; i >= pos; --i)
	{
		ps->s[i + 1] = ps->s[i];
	}
	ps->s[pos] = x;
	++ps->size;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	CheckSeq(ps);
	for (size_t i = pos; i < ps->size - 1; ++i)
	{
		ps->s[i] = ps->s[i + 1];
	}
	--ps->size;
}