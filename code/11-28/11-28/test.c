#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//����һ��������n������n��쳲�����������С��ֵ(����ֵ)
//
//˵����
//쳲����������壺
//��0��1��ʼ�������ֵΪǰ������֮��, ����������Ϊ��һ�͵ڶ�����֮��
//���磺0��1��1��2��3��5��8��13��21��������  ����3Ϊ1��2�ĺͣ�5Ϊ2��3�ĺͣ�8Ϊ3��5�ĺ͵ȵ�
//Ҫ�������ֵ������
//����15����쳲��������������13����ľ���ֵ��2����21����ľ���ֵ��6�����ڶ�쳲��������������С��ֵΪ2
//�������15�����2
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
//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ� % 20����
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are % 20Happy��
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