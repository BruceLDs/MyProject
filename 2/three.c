#define  _CRT_SECURE_NO_WARNINGS
#if 0
#include<stdio.h>
#include<stdlib.h>
void test(int n){
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= i; j++){
			printf("%d*%d=%d\t", j, i, i*j);
		}
		printf("\n");
	}

}
int main(){
	int n = 0;
	scanf("%d", &n);
	test(n);
	system("pause");
	return 0;
}
//打印乘法口诀表
#endif




#if 0
#include<stdio.h>
#include<stdlib.h>
void exchange(int *a, int *b){
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;

}
int main(){
	int a, b;
	printf("请输入两个数:");
	scanf("%d%d", &a, &b);
	exchange(&a, &b);
	printf("两个数交换之后a=%d,b=%d\n", a, b);
	system("pause");
	return 0;
}
#endif
//用函数实现；两个数的交换



#if 0

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void init(int dst[], int n, const int src[])
{
	for (int i = 0; i < n; i++)
	{
		dst[i] = src[i];
	}
}
void printarray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');
}
void swapargs(int *pa, int *pb)
{
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void empty(int a[], int n)
{
	memset(a, 0, n * sizeof(int));
}

void reverse(int a[], int n)
{
	int i, j;
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		swapargs(&a[i], &a[j]);
	}
}
int main(){
	int a[10] = { 0 };
	int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	init(a, 10, b);
	printarray(a, 10);
	reverse(a, 10);
	printarray(a, 10);
	empty(a, 10);
	printarray(a, 10);
	system("pause");
	return 0;
}
#endif
//初始化两个数组，并数组逆置清空
#if 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int prime(int n){
	int i = 2;
	for (i = 2; i <= sqrt(n); i++){
		if (n %i == 0){
			return 0;
		}
	}
	return 1;
}
void test(){
	int n = 0;
	printf("请输入你想要测试的数\n");
	scanf("%d", &n);
	int tmp = prime(n);
	if (tmp == 1){
		printf("%d是素数", n);
	}
	else
		printf("%d不是素数", n);
	putchar('\n');
}
int main(){
	test();
	system("pause");
	return 0;
}//测试一个数是不是素数
#endif