#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
int i, j, k, l;
int flag;
char c;
typedef struct Banker{
	int *Available;		//��������Դ����
	int **Max;			//����������
	int **Allocation;	//�������
	int **Need;			//�������
	int **Requst;		//���������Դ����
	int *Work;			//��������
	int *Finish;		//��������
}Process;
int Bank(Process *process, int m, int n);
int Safe(Process *process, int m, int n);
void Max(Process *process, int m, int n);
void Need(Process *process, int m, int n);
void Allocation(Process *process, int m, int n);
void Available(Process *process, int n);
int Requst(Process *process, int m, int n);

int Bank(Process *process, int m, int n)
{
	do	//��Դ����ʧ�ܻ���ϵͳ����ȫʱflag=0,���������롣
	{
		if ((flag = Requst(process, m, n)) == 1)
		{
			printf("�����Է���ɹ���\n");
			for (j = 0; j<n; j++)
			{
				(process->Available)[j] -= (process->Requst)[l][j];
				(process->Allocation)[l][j] += (process->Requst)[l][j];
				(process->Need)[l][j] -= (process->Requst)[l][j];
			}
		}
		if (flag == 1 && (flag = Safe(process, m, n)) == 0)//ϵͳ����ȫ��������Դ�Է���
		{
			printf("������Դ�Է��䡣\n");
			for (j = 0; j<n; j++)
			{
				(process->Available)[j] += (process->Requst)[l][j];
				(process->Allocation)[l][j] -= (process->Requst)[l][j];
				(process->Need)[l][j] += (process->Requst)[l][j];
			}
		}
	} while (flag == 0);
	if (flag == 1)
	{
		printf("����ɹ���\n");
		printf("�Ƿ����������Դ���䣿����Y����������y������\n");
		getchar();
		c = getchar();
		if (c == 'Y')return 1;
		if (c == 'y')return 0;
	}
}
int Safe(Process *process, int m, int n)
{
	(process->Work) = (int *)malloc(sizeof(int)*n);
	for (j = 0; j<n; j++)
		(process->Work)[j] = (process->Available)[j];//ϵͳ���ṩ�����̼�����������ĸ�����Դ��Ŀ

	(process->Finish) = (int *)malloc(sizeof(int)*m);
	for (i = 0; i<m; i++)
		(process->Finish)[i] = FALSE;
	k = m;
	int flag1;				//���в�������������Դʱ���Ϊ0
	int flag2;				//�����н��̲�������ɹ�ʱ���Ϊ0
	int *s = (int *)malloc(sizeof(int)*m);//��¼��ȫ����
	do
	{
		for (i = 0; i<m; i++)		//һ�ַ���
		if ((process->Finish)[i] == FALSE)
		{
			flag1 = 1;
			for (j = 0; j<n; j++)
			if ((process->Need)[i][j]>(process->Work)[j])
				flag1 = 0;//�в�������������Դ
			if (flag1 == 1)
			{
				for (j = 0; j<n; j++)
					*((process->Work) + j) += *((process->Allocation)[i] + j);
				(process->Finish)[i] = TRUE;
				*s = i;
				s++;
			}
		}
		k--;//ÿ���һ�ν��̷���ʱk��1,�Ա�����ѭ���ͷ�ֹ��ѭ��
	} while (k>0);
	flag2 = 1;
	for (i = 0; i<m; i++)	//�ж��Ƿ����н��̶����
	{
		if ((process->Finish)[i] == FALSE)
		{
			flag2 = 0;
			break;
		}
	}
	if (flag2 == 0)
	{
		printf("��ǰ״̬����ȫ��\n");
		return 0;
	}
	else
	{
		printf("��ǰ״̬��ȫ��\n");
		for (i = 0; i<m; i++)s--;
		printf("��ȫ����Ϊ��");
		for (i = 0; i<m; i++)
			printf("P%d ", s[i]);
		printf("\n");
		free(s);
		return 1;
	}
}
void Max(Process *process, int m, int n)
{
	process->Max = (int **)malloc(sizeof(int *)*m);//����m��ָ�룬����ָ��������׵�ַ
	for (i = 0; i<m; i++)
		(process->Max)[i] = (int *)malloc(sizeof(int)*n);//Ϊÿ���������n��ָ��Ԫ��
	printf("��������̶Ը�����Դ�������������\n");
	for (i = 0; i<m; i++)
	{
		printf("P%d:\n", i);
		for (j = 0; j<n; j++)
		{
			scanf("%d", ((process->Max)[i] + j));
		}
	}
}
void Need(Process *process, int m, int n)
{
	process->Need = (int **)malloc(sizeof(int *)*m);
	for (i = 0; i<m; i++)
		(process->Need)[i] = (int *)malloc(sizeof(int)*n);
	printf("��������̶Ը�����Դ����������\n");
	for (i = 0; i<m; i++)
	{
		printf("P%d:\n", i);
		for (j = 0; j<n; j++)
		{
			scanf("%d", ((process->Need)[i] + j));
		}
	}
}
void Allocation(Process *process, int m, int n)
{
	process->Allocation = (int **)malloc(sizeof(int *)*m);
	for (i = 0; i<m; i++)
		(process->Allocation)[i] = (int *)malloc(sizeof(int)*n);
	for (i = 0; i<m; i++)
	for (j = 0; j<n; j++)
		*((process->Allocation)[i] + j) = (*((process->Max)[i] + j)) - (*((process->Need)[i] + j));
}
void Available(Process *process, int n)
{
	process->Available = (int *)malloc(sizeof(int)*n);
	printf("����ϵͳ������Դ����\n");
	for (i = 0; i<n; i++)
		scanf("%d", &(process->Available)[i]);
}
int Requst(Process *process, int m, int n)
{
	process->Requst = (int **)malloc(sizeof(int *)*m);
	for (i = 0; i<m; i++)
		(process->Requst)[i] = (int *)malloc(sizeof(int)*n);
	printf("���������������Դ��������\n");
	scanf("%d", &i);
	l = i;
	for (j = 0; j<n; j++)
		scanf("%d", (process->Requst)[i] + j);
	int flag1 = 1;//����������������ʱ���Ϊ0
	int flag2 = 1;//���������ڿ�������Դ��ʱ���Ϊ0
	for (j = 0; j<n; j++)//����������Ƿ�С�ڵ���������
	if ((process->Requst)[i][j]>(process->Need)[i][j])
		flag1 = 0;
	if (flag1 == 0)
	{
		printf("����������������������!���������롣\n");
		return 0;
	}
	if (flag1 == 1)
	{
		for (j = 0; j<n; j++)//����������Ƿ�С�ڵ���ϵͳ�еĿ�������Դ��
		if ((process->Requst)[i][j]>(process->Available)[j])
			flag2 = 0;
		if (flag2 == 0)
		{
			printf("���������������ڿ�������Դ��!���������롣\n");
			return 0;
		}
		else return 1;
	}
}
int main()
{
	Process process;
	int m, n;
	printf("�������������");
	scanf("%d", &m);
	printf("��������Դ��������");
	scanf("%d", &n);
	Max(&process, m, n);
	Need(&process, m, n);
	Allocation(&process, m, n);
	Available(&process, n);
	Safe(&process, m, n);
	while (Bank(&process, m, n));
	return 0;
}

