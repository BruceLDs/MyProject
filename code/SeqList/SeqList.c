#define  _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

void InitSeqList(SeqList *sl)//��ʼ��
{
	sl->_array = NULL;
	sl->_size = 0;
	sl->_capicity = 0;
}
void SeqListDestory(SeqList* sl)//����
{

	if (sl->_array){
		free(sl->_array);
		sl->_array = NULL;
		sl->_capicity = sl->_size = 0;
	}
}
void SeqListPushBack(SeqList* sl, DataType x)//β��
{
	assert(sl);
	SeqListCheakCapacity(sl);
	sl->_array[sl->_size] = x;
	++sl->_size;
}
void SeqListCheakCapacity(SeqList *sl)//�������
{
	if (sl->_size == sl->_capicity){
		size_t newCapacity = (sl->_capicity == 0 ? sizeof(DataType ) : 2 * sl->_capicity);
		sl->_array = (DataType *)realloc(sl->_array, newCapacity * sizeof(DataType));
		assert(sl->_array);
		sl->_capicity = newCapacity;
	}
}
void SeqListPushFront(SeqList* sl, DataType x)//ͷ��
{
	assert(sl);
	SeqListCheakCapacity(sl);
	for (size_t i = sl->_size; i > 0; i--){
		sl->_array[i] = sl->_array[i - 1];
	}
	sl->_array[0] = x;
	sl->_size++;
}

void SeqListInsert(SeqList* sl,size_t n,int x)//��λ�ò���
{
	size_t i = sl->_size;
	assert(sl && n<=sl->_size);
	SeqListCheakCapacity(sl);
	while (i >= n)
	{
		sl->_array[i] = sl->_array[i  - 1];
		--i;
	}
	sl->_array[i] = x;
	++sl->_size;
}
void SeqListPopBack(SeqList* sl)//βɾ
{
	assert(sl);
	if (sl->_size > 0)
		sl->_size--;
}
void SeqListPopFront(SeqList* sl){
	assert(sl);
	for (size_t i = 0; i < sl->_size - 1; i++){
		sl->_array[i] = sl->_array[i + 1];
	}
	sl->_size--;
}
void SeqListErase(SeqList* sl, size_t pos)//����λ��ɾ��
{
	assert(sl&&pos<=sl->_size);
	for (size_t i = pos-1; i < sl->_size; i++){
		sl->_array[i] = sl->_array[i + 1];
	}
	--sl->_size;
}
size_t SeqListFind(SeqList* sl, DataType x)//�����ݲ���,����λ��
{
	assert(sl);
	for (size_t i = 0; i < sl->_size; i++){
		if (x == sl->_array[i]){
			return i+1;
		}
	}
	return -1;
}
void SeqListModify(SeqList* sl, size_t pos, DataType x)//�޸�
{
	assert(sl&&pos<=sl->_size );
	if (pos<=sl->_size)
	sl->_array[pos-1] = x;
}

void SeqListPrint(SeqList* sl){
	assert(sl);
	for (size_t i = 0; i < sl->_size; i++){
		printf("%d   ", sl->_array[i]);
	}
}