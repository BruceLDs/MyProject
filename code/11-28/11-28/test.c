#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//给定一个正整数n，计算n与斐波那契数的最小差值(绝对值)
//
//说明：
//斐波那契数定义：
//从0，1开始后面的数值为前面两者之和, 即第三个数为第一和第二个数之和
//形如：0，1，1，2，3，5，8，13，21。。。。  其中3为1与2的和，5为2与3的和，8为3与5的和等等
//要计算的数值案例：
//输入15，与斐波那契数相减，与13相减的绝对值是2，与21相减的绝对值是6，与众多斐波那契数相减的最小差值为2
//因此输入15，输出2
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int f1 = 0, f2 = 1, f3;
//	while (n>f2)
//	{
//		f3 = f1 + f2;
//		f1 = f2;
//		f2 = f3;
//	}
//	int m1 = n - f1;
//	int m2 = f2 - n;
//	int ret = m1<m2 ? m1 : m2;
//	printf("%d\n", ret);
//	return 0;
//}
//
//请实现一个函数，将一个字符串中的每个空格替换成“ % 20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are % 20Happy。
char *rep(char *str, int num)
{
	int count = 0;
	char *p = str;
	char *s = '0';
	*s = *(str + num - 1);
	while (*p)
	{
		if (*(str) == ' ')
			++count;
		++p;
	}
	int sum = count * 2 + num;
	char *str_1 = (char*)malloc(sizeof(char)* sum);
	strcpy(str_1, str);
	for (int i = 0; i < sum; ++i)
	{
		//if (*(str_1 + i) == ' ')
		//{
		//	*(str_1 + i) = '%';    //We%20ArHappy
		//	char tmp_1 = '0';
		//	char tmp_2 = '0';
		//	tmp_1 = *(str_1 + i + 1);
		//	tmp_2 = *(str_1 + i + 2);
		//	*(str_1 + i + 1) = '2';
		//	*(str_1 + i + 2) = '0';
		//	*(str_1 + i + 3) = tmp_1;
		//	*(str_1 + i + 4) = tmp_2;
		//}
		if (*(str_1 + i) == ' ')
		{
			*(str_1 + i) = '%'; 
			int k = i;
			for (k; i < sum; ++k)
			{
				*(str + i + 3) = *(str + i + 1);
				if (i = sum - 1)
					*(str + i) = *s;					
			}
			*(str_1 + i + 1) = '2';
			*(str_1 + i + 2) = '0';
		}
	}
	return str_1;

}
int main()
{
	char str[] = "We Are Happy";
	int len = strlen(str);
	printf("%s\n", rep(str, len));
	return 0;
}
//int *sum(char *s)
//{
//	char *s1 = (char*)malloc(sizeof(char)* 10);
//	strcpy(s1, s);
//	return s1;
//}
//int main()
//{
//	char *s = "hello";
//	printf("%s\n", sum(s));
//	return 0;
//}