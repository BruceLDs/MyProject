#define  _CRT_SECURE_NO_WARNINGS
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()//打印100到200之间的素数
{
	printf("100~200之间的素数如下：\n");
	int i = 0;
	int j = 0;
	for (i = 100; i <= 200; i++){
		int count = 0;
		for (j = 2; j <= sqrt(i); j++){
			if (i%j == 0){
				count++;
				break;
			}
		}
		if (count != 1)
			printf("%d\t", i);
	}
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int main(){//利用变量交换a和b的值
	int a, b, c;
	printf("请按序输入a和b的值:\t");
	scanf("%d ", &a);
	scanf("%d", &b);
	c = a;
	a = b;
	b = c;
	printf("交换之后\n");
	printf("a的值为：%d\t", a);
	printf("b的值为：%d\n", b);
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int main(){//不引入变量交换两个数的值1
	int a;
	int b;
	printf("请输入a的值\t");
	scanf("%d", &a);
	printf("请输入b的值\t");
	scanf("%d", &b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("交换之后a的值为%d\t", a);
	printf("交换之后b的值为%d\n", b);
	system("pause");
	return 0;
}
#endif

#if 0

#include<stdio.h>
#include<stdlib.h>
int main(){//交换两个数组
	int arr1[] = { 1, 2, 3 };
	int arr2[] = { 4, 5, 6 };
	int i = 0;
	int zc = sizeof(arr2) / sizeof(arr2[0]);
	for (i = 0; i < zc; i++){
		arr1[i] = arr1[i] ^ arr2[i];
		arr2[i] = arr1[i] ^ arr2[i];
		arr1[i] = arr1[i] ^ arr2[i];
	}
	for (i = 0; i < zc; i++){
		printf("%d\t", arr1[i]);
	}
	putchar('\n');
	for (i = 0; i < zc; i++){
		printf("%d\t", arr2[i]);
	}
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int main(){//将一个串字符串的大写变小写  小写变大写
	char tmp;
	while (1){
		tmp = getchar();
		if (tmp <= 'Z'&&tmp >= 'A')
		{
			putchar(tmp + ('a' - 'A'));
		}
		else if (tmp <= 'z'&&tmp >= 'a')
		{
			putchar(tmp - ('a' - 'A'));
		}
		else if (tmp<'A'&&tmp>'z'){

		}
	}
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
void test(int n){//打印乘法口诀表
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
#endif


#if 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int array[10] = { 0 };
	int max = 0;
	int i = 0;
	printf("请输入10个整数：\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &array[i]);
	}
	max = array[0];
	for (i = 1; i < 10; i++)
	{
		if (array[i]>max)
		{
			max = array[i];
		}
	}
	printf("max=%d\n", max);
	system("pause");
	return 0;
}
#endif