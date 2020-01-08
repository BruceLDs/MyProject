#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
/*�����ڴ�Ĵ�СΪ512*/
#define MEMSIZE 512
/*��Сʣ���ڴ�*/
#define MINSIZE 2

/*�ڴ�����ռ��ṹ*/
typedef struct _MemoryInfomation
{
	/*��ʼ��ַ*/
	int start;
	/*��С*/
	int Size;
	/*״̬ F:����(Free) U:ռ��(Used) E ����(End)*/
	char status;
} MEMINFO;

/*�ڴ�ռ���Ϣ��*/
MEMINFO MemList[MEMSIZE];

/*��ʾ�ڴ�״̬*/
void Display()
{
	int i, used = 0;//��¼����ʹ�õ��ܿռ���
	printf("\n---------------------------------------------------\n");
	printf("%5s%15s%15s%15s", "����", "��ʼ��ַ", "��С", "״̬");
	printf("\n---------------------------------------------------\n");
	for (i = 0; i<MEMSIZE&&MemList[i].status != 'e'; i++)
	{
		if (MemList[i].status == 'u')
		{
			used += MemList[i].Size;
		}
		printf("%5d%15d%15d%15s\n", i, MemList[i].start, MemList[i].Size, MemList[i].status == 'u' ? "ռ��" : "����");
	}
	printf("\n----------------------------------------------\n");
	printf("�ڴ���Ϣ:%-10d ��ռ�ô�С:%-10d ���д�С:%-10d\n", MEMSIZE, used, MEMSIZE - used);
}

/*��ʼ�����б���*/
void InitMemList()
{
	int i;
	MEMINFO temp = { 0, 0, 'e' };
	//��ʼ���ռ���Ϣ��
	for (i = 0; i<MEMSIZE; i++)
	{
		MemList[i] = temp;
	}
	//��ʼ��ַΪ0
	MemList[0].start = 0;
	//�ռ��ʼΪ���
	MemList[0].Size = MEMSIZE;
	//״̬Ϊ����
	MemList[0].status = 'f';
}
void FirstFit_new()
{
	int i, j, flag = 0;
	int request;
	printf("�״���Ӧ�㷨:��������Ҫ����Ŀռ��С\n");
	scanf("%d", &request);
	//��������
	for (i = 0; i<MEMSIZE&&MemList[i].status != 'e'; i++)
	{
		//��������Ҫ�Ĵ�С,���ǿ��пռ�
		if (MemList[i].Size >= request&&MemList[i].status == 'f')
		{
			//���С�ڹ涨����С���������ռ�����ȥ
			if (MemList[i].Size - request <= MINSIZE)
			{
				MemList[i].status = 'u';
			}
			else
			{
				//��i�����Ϣ��Ԫ�غ���
				for (j = MEMSIZE - 2; j>i; j--)
				{
					MemList[j + 1] = MemList[j];
				}

				//��i�ֳ������֣�ʹ�õ͵�ַ����
				MemList[i + 1].start = MemList[i].start + request;
				MemList[i + 1].Size = MemList[i].Size - request;
				MemList[i + 1].status = 'f';
				MemList[i].Size = request;
				MemList[i].status = 'u';
				flag = 1;
			}
			break;
		}
	}
	//û���ҵ����Ϸ���Ŀռ�
	if (flag != 1 || i == MEMSIZE || MemList[i].status == 'e')
	{
		printf("�ڴ治��!!\n");
	}
	Display();
}
void BadFit_new()
{
	int i, j, k, flag, request;
	printf("���Ӧ�㷨:��������Ҫ����Ŀռ��С\n");
	scanf("%d", &request);
	j = 0;
	flag = 0;
	k = 0;
	//��������Ҫ������ռ�
	for (i = 0; i<MEMSIZE - 1 && MemList[i].status != 'e'; i++)
	{
		if (MemList[i].Size >= request&&MemList[i].status == 'f')
		{
			flag = 1;
			if (MemList[i].Size>k)
			{
				k = MemList[i].Size;
				j = i;
			}
		}
	}
	i = j;
	if (flag == 0)
	{
		printf("�ڴ治��!!\n");
		j = i;
	}
	else if (MemList[i].Size - request <= MINSIZE)
	{
		MemList[i].status = 'u';
	}
	else
	{
		for (j = MEMSIZE - 2; j>i; j--)
		{
			MemList[j + 1] = MemList[j];
		}
		MemList[i + 1].start = MemList[i].start + request;
		MemList[i + 1].Size = MemList[i].Size - request;
		MemList[i + 1].status = 'f';
		MemList[i].Size = request;
		MemList[i].status = 'u';
	}
	Display();
}


//�ͷ�һ���ڴ�
void del_t()
{
	int i, number;
	printf("\n���������ͷŵĿռ������:\n");
	scanf("%d", &number);
	//����Ŀռ���ʹ�õ�
	if (MemList[number].status == 'u')
	{
		MemList[number].status = 'f';//��־Ϊ����
		if (MemList[number + 1].status == 'f')//�Ҳ�ռ�Ϊ����ϲ�
		{
			MemList[number].Size += MemList[number].Size;//��С�ϲ�
			for (i = number + 1; i<MEMSIZE - 1 && MemList[i].status != 'e'; i++) //i����Ŀռ���Ϣ��Ԫ�غ���
			{
				if (i>0)
				{
					MemList[i] = MemList[i + 1];
				}
			}
		}
		//���ռ������ϲ�
		if (number>0 && MemList[number - 1].status == 'f')
		{
			MemList[number - 1].Size += MemList[number].Size;
			for (i = number; i<MEMSIZE - 1 && MemList[i].status != 'e'; i++)
			{
				MemList[i] = MemList[i + 1];
			}
		}
	}
	else
	{
		printf("��������ֲ���!\n");
	}
	Display();
}

void BestFit_new()
{
	int i, j, t, flag, request;
	printf("�����Ӧ�㷨:��������Ҫ����Ŀռ��С\n");
	scanf("%d", &request);
	j = 0;
	flag = 0;
	t = MEMSIZE;
	//��������Ҫ������ռ�
	for (i = 0; i<MEMSIZE&&MemList[i].status != 'e'; i++)
	{
		if (MemList[i].Size >= request&&MemList[i].status == 'f')
		{
			flag = 1;
			if (MemList[i].Size<t)
			{
				t = MemList[i].Size;
				j = i;
			}
		}
	}
	i = j;
	if (flag == 0)
	{
		printf("�ڴ治��\n");
		j = i;
	}
	else if (MemList[i].Size - request <= MINSIZE)  //���С�ڹ涨����С���������ռ�����ȥ
	{
		MemList[i].status = 'u';
	}
	else
	{
		//��i�����Ϣ��Ԫ�غ���
		for (j = MEMSIZE - 2; j>i; j--)
		{
			MemList[j + 1] = MemList[j];
		}

		//��i�ֳ������֣�ʹ�õ͵�ַ����
		MemList[i + 1].start = MemList[i].start + request;
		MemList[i + 1].Size = MemList[i].Size - request;
		MemList[i + 1].status = 'f';
		MemList[i].Size = request;
		MemList[i].status = 'u';
	}
	Display();
}
void meun()
{
	printf("=================================================\n");
	printf("         1.�״���Ӧ�㷨\t     2.�����Ӧ�㷨\n");
	printf("         3.���Ӧ�㷨\t     4.ɾ���ѷ���ռ�\n");
	printf("         5.��ʾ�ڴ���Ϣ\t     6. �˳�����\n");
	printf("=================================================\n");
}
int main()
{
	int x;
	InitMemList();//������ʼ��
	while (1)
	{
		meun();
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			FirstFit_new();//�״���Ӧ�㷨
			break;
		case 2:
			BestFit_new();//�����Ӧ�㷨
			break;
		case 3:
			BadFit_new();//���Ӧ�㷨
			break;
		case 4:
			del_t();//ɾ���Ѿ�ʹ����ϵĿռ�
			break;
		case 5:
			Display();//��ʾ�ڴ�������
			break;
		case 6:
			exit(0);
		}
	}
	return 0;
}
