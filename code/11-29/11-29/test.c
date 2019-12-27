#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
// 模拟实现栈
/*栈元素结构体（用来描述每个栈元素）*/
struct List{
	int data;
	struct List *next;

};
/*栈结构体（栈顶元素指针，栈大小信息）*/
struct Stack{
	struct List *head;
	int size;
};

/*栈初始化*/
struct Stack * StackInit(void)
{
	struct Stack  *stack = NULL;
	stack = (struct Stack *)malloc(sizeof(struct Stack)); //为栈分配一个内存块
	stack->head = (struct List *)malloc(sizeof(struct List));//分配一个栈元素内存块
	stack->head->next = NULL;
	stack->size = 0;
	return stack;
}
/*入栈函数*/
int StackPush(struct Stack *stack, int data)
{
	struct List *tmp = (struct List *)malloc(sizeof(struct List)); //分配一个栈元素内存块
	tmp->data = data;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	stack->size++;
	printf("push:%d\n", data);
	return 0;
}
/*判断栈是否为空*/
int IsStackEmpty(struct Stack *stack)
{
	if (stack->head->next == NULL)
		return 1;
	else
		return 0;
}
/*出栈函数*/
int StackPop(struct Stack *stack, int *data)
{
	if (IsStackEmpty(stack))return -1;
	struct List *tmp = NULL;
	tmp = stack->head->next;
	data = tmp->data;
	stack->head->next = tmp->next;
	stack->size--;
	free(tmp); //释放该栈元素内存块
	printf("pop:%d \n", data);

	return 0;
}


/*主程序，测试栈能否正常工作*/
int main(void){
	int data;
	struct Stack *stack = StackInit(); //初始化一个載
	printf("Stack,start run !\n");
	StackPush(stack, 1);
	StackPush(stack, 88);
	printf("Current Stack Size:%d \n", stack->size);
	StackPop(stack, &data);
	StackPop(stack, &data);
	printf("Current Stack Size:%d \n", stack->size);
	printf("Stack,finish！\n");
	return 0;
}
//请实现一个函数，将一个字符串中的每个空格替换成“ % 20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are % 20Happy。
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