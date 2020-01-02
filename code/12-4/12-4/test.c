#include"test.h"

void SeqListInit(SeqList* ps)  //��ʼ��
{
	ps->size = 0;
	ps->capicity = 0;
	ps->s = NULL;

}
void CheckSeq(SeqList *ps)   //�˶Կռ��Ƿ�����
{
	if (ps->size == ps->capicity)
	{
		int Newcapicity =ps->capicity == 0 ? 4 : ps->capicity * 2;
		ps->s = (SeqDataType*)realloc(ps->s, sizeof(SeqDataType)*Newcapicity);
	}
}
void SeqListDestory(SeqList* ps)    //����
{
	assert(ps);
	free(ps->s);
	ps->s = NULL;
}

void SeqListPrint(SeqList* ps)   //��ӡ
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->s[i]);
	}
	printf("\n");
}
void SeqListPushBack(SeqList* ps, SeqDataType x)    //β��
{
	assert(ps);
	CheckSeq(ps);
	ps->s[ps->size] = x;
	++ps->size;
}
void SeqListPushFront(SeqList* ps, SeqDataType x)   //ͷ��
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
void SeqListPopFront(SeqList* ps)       //ͷɾ
{
	assert(ps);
	CheckSeq(ps);
	for (int i = 0; i < ps->size - 1; ++i)
	{
		ps->s[i] = ps->s[i + 1];
	}
	--ps->size;

}
void SeqListPopBack(SeqList* ps)       //βɾ
{
	assert(ps);
	CheckSeq(ps);
	ps->s[ps->size - 1] = 0;
	--ps->size;
}

// ˳������
void SeqListFind(SeqList* ps, SeqDataType x)
{
	assert(ps);
	CheckSeq(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->s[i] == x)
		{
			printf("���ݵ�λ��Ϊ%d\n", i+1);
			return;
		}
	}
	printf("��ѯ�����ݲ�����\n");
}
// ˳�����posλ�ò���x
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
// ˳���ɾ��posλ�õ�ֵ
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