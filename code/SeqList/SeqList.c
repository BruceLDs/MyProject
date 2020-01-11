#define  _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

void InitSeqList(SeqList *sl)//初始化
{
	sl->_array = NULL;
	sl->_size = 0;
	sl->_capicity = 0;
}
void SeqListDestory(SeqList* sl)//销毁
{

	if (sl->_array){
		free(sl->_array);
		sl->_array = NULL;
		sl->_capicity = sl->_size = 0;
	}
}
void SeqListPushBack(SeqList* sl, DataType x)//尾插
{
	assert(sl);
	SeqListCheakCapacity(sl);
	sl->_array[sl->_size] = x;
	++sl->_size;
}
void SeqListCheakCapacity(SeqList *sl)//检查容量
{
	if (sl->_size == sl->_capicity){
		size_t newCapacity = (sl->_capicity == 0 ? sizeof(DataType ) : 2 * sl->_capicity);
		sl->_array = (DataType *)realloc(sl->_array, newCapacity * sizeof(DataType));
		assert(sl->_array);
		sl->_capicity = newCapacity;
	}
}
void SeqListPushFront(SeqList* sl, DataType x)//头插
{
	assert(sl);
	SeqListCheakCapacity(sl);
	for (size_t i = sl->_size; i > 0; i--){
		sl->_array[i] = sl->_array[i - 1];
	}
	sl->_array[0] = x;
	sl->_size++;
}

void SeqListInsert(SeqList* sl,size_t n,int x)//按位置插入
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
void SeqListPopBack(SeqList* sl)//尾删
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
void SeqListErase(SeqList* sl, size_t pos)//任意位置删除
{
	assert(sl&&pos<=sl->_size);
	for (size_t i = pos-1; i < sl->_size; i++){
		sl->_array[i] = sl->_array[i + 1];
	}
	--sl->_size;
}
size_t SeqListFind(SeqList* sl, DataType x)//按数据查找,返回位置
{
	assert(sl);
	for (size_t i = 0; i < sl->_size; i++){
		if (x == sl->_array[i]){
			return i+1;
		}
	}
	return -1;
}
void SeqListModify(SeqList* sl, size_t pos, DataType x)//修改
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