#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int print()
{
	printf("\n\n+++++++++++++��ῴ�������ֺ������+++++++++++++\n");
	printf("+++++++++++++++++��������ǽ��+++++++++++++++++\n\n");
	return 0;
}

int main()
{
	system("title ������Ϸ");
	system("mode con cols=48 lines=25");
	system("color 1A");
	system("date /T");
	system("TIME /T");
	int time0;
	int a, c, i, j, n = 0;
	char b, d, f, g, h, k, l, m1, m2, e[4] = { '+', '-', '*', '/' };
	print();
	printf("\n��Ϸ����3s��ʼ�ˣ�׼��������\n");
	for (time0 = 3; time0>0; time0--)
	{
		printf("%d\n", time0);
		Sleep(1000);
	}
	system("cls");
	print();
	for (i = 1; i <= 10; i++)
	{
		c = rand() % 4 + 1;
		for (j = 1; j <= c; j++)
		{
			b = rand() % 26 + 'a';
			printf("%c", b);
		}
		g = rand() % 9 + 1;
		printf("%d", g);
		for (j = 1; j <c; j++)
		{
			h = rand() % 26 + 'a';
			printf("%c", h);
		}
		d = e[rand() % 4];
		printf("%c", d);
		for (j = 1; j <c; j++)
		{
			f = rand() % 26 + 'a';
			printf("%c", f);
		}
		k = rand() % 9 + 1;
		printf("%d", k);
		for (j = 1; j <= c; j++)
		{
			l = rand() % 26 + 'a';
			printf("%c", l);
		}
		Sleep(1000);
		system("cls");
		print();
		printf("��������������Ľ��:\n");
		scanf("%d", &a);
		system("cls");
		print();
		if (d == '+')
			m1 = g + k;
		else if (d == '-')
		{
			m1 = g - k;
			m2 = k - g;
		}
		else if (d == '*')
			m1 = g * k;
		else if (d == '/')
		{
			m1 = g / k;
			m2 = k / g;
		}

		if (a == m1 || a == m2)
			n++;
	}
	if (n<3)
		printf("�Ŵ����%d�⣬��������\n", n);
	else if (n >= 3 && n<8)
		printf("�����%d��,����\n", n);
	else if (n >= 8)
		printf("666,��ϲ������%d��,�����ˣ���\n", n);
	system("pause");
	return(0);
}
