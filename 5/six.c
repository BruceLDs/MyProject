#define  _CRT_SECURE_NO_WARNINGS
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//这个函数的返回值是value的二进制位模式从左到右翻转后的值。
unsigned int reverse_bit(unsigned int value)
{
	unsigned int sum = 0;
	int i = 0;
	for (i = 31; i >= 0; i--)
	{
		if (value & 1)
		{
			sum = sum + (int)pow(2, i);
		}
		value = value >> 1;
	}
	return sum;
}
int main()
{
	int a = 0;
	unsigned int k = 0;
	scanf("%d", &a);
	k = reverse_bit(a);
	printf("%d\n", k);
	system("pause");
	return 0;
}
#endif

#if 0
//不使用（a + b） / 2这种方式，求两个数的平均值。
#include<stdio.h>
#include<stdlib.h>
double ave(int a, int b){
	double k = 0;
	k = (a - b) / 2.0 + b;
	return k;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	double k = ave(a, b);
	printf("%lf", k);
	system("pause");
	return 0;
}
#endif



#if 0
//一组数据中只有一个数字出现了一次。
//其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
#include<stdio.h>
#include<stdlib.h>
int Find_one_num(int *arr, int len)
{
	int i = 0;
	int k = 0;
	for (i = 0; i < len; i++){
		k = k^ arr[i];
	}
	return k;
}
int main(){
	int arr[] = { 1, 3, 5, 7, 9, 3, 7, 8, 5, 1, 9 };
	int len = sizeof (arr) / sizeof(arr[0]);
	int k = Find_one_num(arr, len);
	printf("%d\n", k);
	system("pause");
	return 0;
}


#endif 



#if 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = { 1, 3, 2, 5, 5, 3, 2, 7, 1, 9;
	int x = 0;
	int y = 0;
	int a = 0;
	int i = 0;
	int k = 0;
	int count = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		a = arr[i] ^ arr[i + 1];//--->a+b
	}
	for (i = 0; i < 32; i++)
	{
		count = a & 1;
		a = a >> 1;
		k = i;
		if (count)
		{
			break;
		}
	}
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> (k + 1)) & 1) == 1)
			x = arr[i] ^ x;
		else
			y = arr[i] ^ y;
	}

	printf("%d\n", x);
	printf("%d\n", y);
	system("pause");
	return 0;
}
#endif





#if 0
//有一个字符数组的内容为:"student a am i", 
//请你将数组的内容改为"i am a student".
//要求：
//不能使用库函数。
//只能开辟有限个空间（空间个数和字符串的长度无关）。
#include<stdio.h>
#include<stdlib.h>
int my_sizeof(char*arr)
{
	int count = 0;
	while (arr[count] != '\0')
	{
		count++;
	}
	return count;
}
void my_strcpy(char* arr, char* arr0, int k)
{
	int i = 0;
	int count = 0;
	while (1)
	{
		int n = i;
		int j = 0;
		int h = count;
		while (arr[i] != ' '&&arr[i] != '\0')
		{
			count++;
			i++;
		}
		for (j = k - count; j < k - h; j++)
		{
			arr0[j] = arr[n];
			n++;
		}
		if (arr[i] == '\0')
		{
			break;
		}
		arr0[k - count - 1] = ' ';
		i++;
		count++;
	}
}
int main()
{
	char arr[] = { "student a am i" };
	char arr0[20] = { 0 };
	int m = 0;
	m = my_sizeof(arr);
	my_strcpy(arr, arr0, m);
	int i = 0;
	printf("%s\n", arr);
	printf("%s\n", arr0);
	system("pause");
	return 0;
}
#endif