#define  _CRT_SECURE_NO_WARNINGS
#if 0
#include<stdio.h>
#include<stdlib.h>
int count_one_bits(unsigned int value)//一个数的二进制序列里1的位数
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (value & 1)
		{
			count++;
		}
		value = value >> 1;
	}
	return count;
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d\n", count_one_bits(a));
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int h = 0;
	int arr1[16] = { 0 };
	int arr2[16] = { 0 };
	scanf("%d", &h);
	int j = 0;
	int k = 0;
	for (i = 0; i < 32; i++)
	{
		if (i % 2 == 0)
		{
			arr1[j] = h & 1;
			j++;
		}
		else
		{
			arr2[k] = h & 1;
			k++;
		}
		h = h >> 1;
	}
	printf("奇数序列：");
	for (i = 15; i >= 0; i--)
	{
		printf("%d", arr1[i]);
	}
	printf("\n偶数序列：");
	for (i = 15; i >= 0; i--)
	{
		printf("%d", arr2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int main()//例如1234->1 2 3 4
{
	int a = 0;
	scanf("%d", &a);
	int i = 0;
	int arr[10] = { 0 };
	while (a != 0)
	{
		arr[i] = a % 10;
		i++;
		a /= 10;
	}
	for (i = i - 1; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
#endif 

#if 0
#include<stdio.h>
#include<stdlib.h>
int main()//两个数的二进制序列有多少位不一样
{
	int a = 0;
	int b = 0;
	int count = 0;
	scanf("%d%d", &a, &b);
	for (int i = 0; i < 32; i++)
	{
		if ((a & 1) ^ (b & 1))//奇为1  偶为0
		{
			count++;
		}
		a = a >> 1;
		b = b >> 1;
	}
	printf("%d\n", count);//1010  0010
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int A = 0, B = 0, C = 0, D = 0, E = 0;
	for (A = 1; A <= 5; A++){
		for (B = 1; B <= 5; B++){
			for (C = 1; C <= 5; C++){
				for (D = 1; D <= 5; D++){
					for (E = 1; E <= 5; E++){
						if (A == 3 && B != 2 || A != 3 && B == 2){
							if (B == 2 && E != 4 || B != 2 && E == 4){
								if (C != 1 && D == 2 || C == 1 && D != 2){
									if (C == 5 && D != 3 || C != 5 && D == 3){
										if (E != 4 && A == 1 || E == 4 && A != 1){
											if (A*B*C*D*E == 120){
												printf("A=%d B=%d C=%d D=%d E=%d\n", A, B, C, D, E);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int flag = 0;
	for (flag = 'A'; flag <= 'D'; flag++)
	{
		if ((flag != 'A') + (flag == 'C') + (flag == 'D') + (flag != 'D') == 3)
			printf("%c\n", flag);
	}
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int main(){//杨辉三角
	int i = 0;
	int j = 0;
	int k = 0;
	int arr[7] = { 0 };
	int m = sizeof(arr) / sizeof(arr[0]) - 1;
	arr[0] = 1;
	printf("%2d\n", arr[0]);
	for (i = 1; i < m; i++)
	{
		for (j = i; j > 0; j--)
		{
			arr[j] = arr[j] + arr[j - 1];
		}
		for (k = 0; k <= i; k++)
		{
			printf("%2d ", arr[k]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int MyStrlen(const char *str)
{
	int count = 0;
	assert(str != NULL);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
void reverse(char *left, char *right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void reverseStr(char *str, int k)
{
	char *left = str;
	char *right = str + k - 1;
	reverse(left, right);	//i am a student   -->    tneduts a ma i
	char *cur = str;
	while (*cur != '\0')
	{
		char *start = cur;   //每个单词的开始
		while (*cur != ' '&&*cur != '\0'){
			cur++;
		}      //cur走到空格或者\0
		reverse(start, cur - 1);
		if (*cur != '\0')
			cur++;
	}
}
int main()//例如  i am a student->student a am i
{
	char str[] = "i am a student";
	printf("%s\n", str);
	int k = MyStrlen(str);
	reverseStr(str, k);
	printf("%s\n", str);
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n = 3;
	float *pfloat = (float*)&n;
	printf("%f\n", n);
	printf("%d\n", strlen("abcd\t\0xyz"));//   '\0'
	printf("%d\n", sizeof("abcd\t\0xyz"));//末尾存在NULL终止符
	printf("%lu\n", -1);
	printf("%f\n", *pfloat);
	system("pause");
	return 0;
}
#endif