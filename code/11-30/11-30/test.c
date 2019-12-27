#define _CRT_SECURE_NO_WARNINGS
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
//SeqList
#define OK 1
#define ERROR -1
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode *next;
} Lnode;

//ͷ�巨
Lnode *create_LinkList()
{
	int data;
	Lnode *head;
	Lnode *p;
	head = (Lnode*)malloc(sizeof(Lnode));
	head->next = NULL;
	printf("����Ҫ��������֣� ������-1ʱ �������\n");
	while (1)
	{
		scanf("%d", &data);
		if (data == -1) break;
		p = (Lnode*)malloc(sizeof(Lnode));
		p->data = data;
		p->next = head->next;
		head->next = p;
	}

	return (head);
}


//���� i ����ֵ
ElemType Get_Elem(Lnode *L, int i)
{
	int j;
	Lnode *p;
	p = L->next;
	j = 1;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (j != i) return (-1);
	else return (p->data);
}
//����ֵΪkey�Ľڵ�
Status Locate_Node(Lnode *L, ElemType key)
{
	int i = 1;
	Lnode *p = L->next;

	while (p)
	{
		if (p->data == key)
			return i;
		i++;
		p = p->next;

	}
	if (!p)
		return ERROR;
	return OK;
}
//����eֵ ��iλ�ô�
Status Insert_Lnode(Lnode *L, int i, ElemType e)
{
	int j = 0;

	Lnode *p, *pos;
	Lnode *q;
	p = L->next;

	pos = (Lnode*)malloc(sizeof(Lnode));

	while (p != NULL && j < i - 1)
	{
		pos = p;
		p = p->next;
		j++;
	}
	if (!p)
	{
		printf("iֵ������\n");
	}

	else
	{
		q = (Lnode*)malloc(sizeof(Lnode));
		q->data = e;
		pos->next = q;
		q->next = p;
	}
	return OK;
}
//ɾ��i����ֵ ��E������ֵ
Status Delete_LinkList1(Lnode *L, int i, ElemType *e)
{
	int j = 1;
	Lnode *p;
	Lnode *q;
	p = L;
	q = L->next;
	while (p->next != NULL && j < i)
	{
		p = q;
		q = q->next;
		j++;
	}
	if (j != i)
		printf("iֵ������\n");
	else
	{
		p->next = q->next;
		*e = q->data;
		free(q);
	}
	return OK;
}
//ɾ��ֵΪkey�Ľ��
void Delete_LinkList2(Lnode*L, int key)
{
	Lnode * p = L;
	while (p->next != NULL){
		if (p->next->data == key){
			p->next = p->next->next;
		}
		p = p->next;
	}
}
//ɾ��������������ֵ��ͬ�Ľ��
void Delete_LinkList3(Lnode *L)
{
	Lnode *p = L->next;
	Lnode *q;
	Lnode *ptr;
	while (p != NULL)
	{
		q = p;
		ptr = p->next;
		while (ptr != NULL)
		{
			if (ptr->data == p->data)
			{
				q->next = ptr->next;
				free(ptr);
				ptr = q->next;
			}
			else
			{
				q = ptr;
				ptr = ptr->next;
			}
		}
		p = p->next;
	}
}

//���
Status Traverse_LinkList(Lnode *L)
{
	Lnode *p;
	p = L->next;
	while (p)
	{

		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;


}
//�󳤶�
int LinkList_Length(Lnode *L)
{
	int count = 0;
	Lnode *p = L->next;
	while (p)
	{
		count++;
		p = p->next;
	}
	return count;
}
//�������
Status clear_List(Lnode *L)
{
	Lnode *p = L->next;
	Lnode *q;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}
Status ListEmpty(Lnode *L)
{
	Lnode *p = L->next;
	if (!p)
		return OK;
	else
		return ERROR;
}


int main()
{
	ElemType i, res, key, e;

	Lnode *La = (Lnode*)malloc(sizeof(Lnode));


	if (!La)
		return ERROR;

	printf("ͷ���뷨����La��\n");
	La = create_LinkList();
	printf("��ӡ�½�����La:\n");
	Traverse_LinkList(La);
	printf("La�ĳ���Ϊ��%d\n", LinkList_Length(La));

	printf("������Ҫ���ҵ�λ�ã�");
	scanf("%d", &i);
	res = Get_Elem(La, i);
	printf("���ҵ�ֵΪ��%d\n", res);

	printf("������Ҫ���ҵ�ֵ��");
	scanf("%d", &key);
	res = Locate_Node(La, key);
	printf("��ֵ��λ���ǣ�%d\n", res);

	printf("��������ֵ��");
	scanf("%d", &key);
	printf("����Ҫ�����λ�ã�");
	scanf("%d", &i);
	Insert_Lnode(La, i, key);
	printf("����Ϊ��\n");
	Traverse_LinkList(La);

	printf("����Ҫɾ����λ�ã�");
	scanf("%d", &i);
	Delete_LinkList1(La, i, &e);
	printf("ɾ����ֵΪ��%d", e);
	printf("����Ϊ��\n");
	Traverse_LinkList(La);

	printf("\n");
	printf("����Ҫɾ����ֵ��");
	scanf("%d", &key);
	Delete_LinkList2(La, key);
	printf("����Ϊ��\n");
	Traverse_LinkList(La);


	Delete_LinkList3(La);
	printf("ɾ����ͬ�������ʽ��\n");
	Traverse_LinkList(La);
	printf("��ʱ������Ϊ %d\n", LinkList_Length(La));

	i = ListEmpty(La);
	printf("La�Ƿ�Ϊ�գ� i=%d(1:�� -1:��)\n", i);

	printf("���La\n");
	clear_List(La);
	i = ListEmpty(La);
	printf("La�Ƿ�Ϊ�գ� i=%d(1:�� -1:��)\n", i);

	return 0;
}


//���� nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2,    //0 1 
//
//����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0 1  
//
//ע�������Ԫ�ؿ�Ϊ����˳��

//int *removeElement1(int* nums, int numsSize, int val)
//{
//	int end = numsSize - 1;
//	int start = 0;
//	while (start < end)
//	{
//		if (nums[start] != val)
//		{
//			++start;
//		}
//		else
//		{
//			if (nums[end] == val)
//			{
//				--end;
//			}
//			else
//			{
//				int ret = nums[start];
//				nums[start] = nums[end];
//				nums[end] = ret;
//			}
//		}
//	}
//
//	return nums;
//}
//int removeElement(int* nums, int numsSize, int val){
//	int index = 0;
//	for (int i = 0; i<numsSize; i++){
//		if (nums[i] != val)
//			nums[index++] = nums[i];
//	}
//	return nums;
//}
//int main()
//{
//	int arr[] = { 0, 1, 2, 2, 3, 0, 4, 2 };
//	int *p;
//	p = removeElement(arr, 8, 3);
//	int *p1;
//	p1 = removeElement1(arr, 8, 3);
//	for (int i = 0; i < 8; ++i)
//	{
//		printf("%d ", p[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 8; ++i)
//	{
//		printf("%d ", p1[i]);
//	}
//	return 0;
//}

