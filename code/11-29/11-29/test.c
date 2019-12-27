#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
// ģ��ʵ��ջ
/*ջԪ�ؽṹ�壨��������ÿ��ջԪ�أ�*/
struct List{
	int data;
	struct List *next;

};
/*ջ�ṹ�壨ջ��Ԫ��ָ�룬ջ��С��Ϣ��*/
struct Stack{
	struct List *head;
	int size;
};

/*ջ��ʼ��*/
struct Stack * StackInit(void)
{
	struct Stack  *stack = NULL;
	stack = (struct Stack *)malloc(sizeof(struct Stack)); //Ϊջ����һ���ڴ��
	stack->head = (struct List *)malloc(sizeof(struct List));//����һ��ջԪ���ڴ��
	stack->head->next = NULL;
	stack->size = 0;
	return stack;
}
/*��ջ����*/
int StackPush(struct Stack *stack, int data)
{
	struct List *tmp = (struct List *)malloc(sizeof(struct List)); //����һ��ջԪ���ڴ��
	tmp->data = data;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	stack->size++;
	printf("push:%d\n", data);
	return 0;
}
/*�ж�ջ�Ƿ�Ϊ��*/
int IsStackEmpty(struct Stack *stack)
{
	if (stack->head->next == NULL)
		return 1;
	else
		return 0;
}
/*��ջ����*/
int StackPop(struct Stack *stack, int *data)
{
	if (IsStackEmpty(stack))return -1;
	struct List *tmp = NULL;
	tmp = stack->head->next;
	data = tmp->data;
	stack->head->next = tmp->next;
	stack->size--;
	free(tmp); //�ͷŸ�ջԪ���ڴ��
	printf("pop:%d \n", data);

	return 0;
}


/*�����򣬲���ջ�ܷ���������*/
int main(void){
	int data;
	struct Stack *stack = StackInit(); //��ʼ��һ���d
	printf("Stack,start run !\n");
	StackPush(stack, 1);
	StackPush(stack, 88);
	printf("Current Stack Size:%d \n", stack->size);
	StackPop(stack, &data);
	StackPop(stack, &data);
	printf("Current Stack Size:%d \n", stack->size);
	printf("Stack,finish��\n");
	return 0;
}
//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ� % 20����
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are % 20Happy��
//char *rep(char *str, int num)
//{
//	int count = 0;
//	char *p = str;
//	while (*str)
//	{
//		if (*(str) == ' ')
//			++count;
//		++str;
//	}
//	str = p;
//	int sum = count * 2 + num;
//	char *str_1 = (char*)malloc(sizeof(char)* sum);
//	/*memset(str_1, 0, sum);*/
//	strcpy(str_1, str);
//	for (int i = 0; i < sum; ++i)
//	{
//		if (*(str_1 + i) == ' ')
//		{
//			*(str_1 + i) = '%';
//			for (int k = sum - 1; k > i + 2; --k)
//			{
//				*(str_1 + k) = *(str_1 + k - 2);
//
//			}
//			*(str_1 + i + 1) = '2';
//			*(str_1 + i + 2) = '0';
//		}
//	}
//	return str_1;
//
//}
//int main()
//{
//	char str[] = "We Are Happy Every Day ";
//	int len = strlen(str);
//	char *p = rep(str, len);
//	printf("%s\n", p);
//	return 0;
//}