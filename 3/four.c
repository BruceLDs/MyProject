#define  _CRT_SECURE_NO_WARNINGS
#if 0
#include<stdio.h>
#include<stdlib.h>

int test(int n)//��ӡ��n��쳲�������
{
	if (n <= 2){
		return 1;
	}
	return test(n - 1) + test(n - 2);
}
int main(){
	int k = 0;
	int n = 0;
	scanf("%d", &n);
	k = test(n);
	printf("��%d��쳲�������Ϊ%d\n", n, k);
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
int mul(int n, int k){//kΪָ����nΪ����
	if (k == 1)
		return n;
	else
		return n*mul(n, k - 1);
}
int main(){
	int sum;
	int k = 0;
	int n = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	sum = mul(n, k);
	printf("%d\n", sum);//sum=^n
	system("pause");
	return 0;
}//��n��k����
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
int sum = 0;
int DigitSum(unsigned int k)
{
	if (k < 10)
		return k;
	else
		return sum = DigitSum(k / 10) + k % 10;
}
int main()
{
	unsigned int a = 0;
	scanf("%d", &a);
	printf("%d\n", DigitSum(a));//���磺1234 �����  1+2+3+4
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int My_strle1(char*arr)
{
	int sum = 0;
	int i = 0;
	while (1)
	{
		if (*arr == '\0')
			break;
		else
		{
			sum++;
			arr++;
		}
	}
	return sum;
}
int My_strle2(char* arr)
{
	if (*arr == '\0')
		return 0;
	else
		return 1 + My_strle2(arr + 1);
}
int main()
{
	char arr[] = { "abcde" };
	printf("%d\n", My_strle1(arr));
	printf("%d\n", My_strle2(arr));
	system("pause");
	return 0;
}//���ַ�������
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
int Factorial1(int k)
{
	int i = 0;
	int sum = 1;
	for (i = 1; i <= k; i++)
	{
		sum = sum*i;
	}
	return sum;
}
int Factorial2(int k)
{
	if (k == 1)
		return 1;
	else
		return k*Factorial2(k - 1);
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d\n", Factorial1(a));
	printf("%d\n", Factorial2(a));
	system("pause");
	return 0;
}//�ݹ�ͷǵݹ����n��쳲�������
#endif

#if 0
//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 
#include<stdio.h>
#include<stdlib.h>
void Printf(int k)
{
	if (k > 9)
	{
		Printf(k / 10);
	}
	printf("%d ", k % 10);
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	Printf(a);
	system("pause");
	return 0;
}

#endif