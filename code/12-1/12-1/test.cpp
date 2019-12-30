#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <map>
using namespace std;


const int N = 1000;
struct Task
{
	char name[10]; // ��������
	int come_time; // ����ʱ��
	int turn_time; // ����ʱ��
	int start_time; // ��ʼ����ʱ��
	int end_time;// ��������ʱ��
	int wait_time; // �ȴ�ʱ��
}task[N], tp_task[N];

int num;//������Ŀ

void sleep(int n)
{
	int st = clock();
	while ((clock() - st) <= n);
}

void GetData()
{
	printf("������ÿ�����̵����ƣ�����ʱ�䣬����ʱ��\n");
	for (int i = 0; i < num; i++)
	{
		printf("��%d��������Ϣ���룺\n", i + 1);
		scanf("%s%d%d", task[i].name, &task[i].come_time, &task[i].turn_time);
		strcpy(tp_task[i].name, task[i].name);
		tp_task[i].come_time = task[i].come_time;
		tp_task[i].turn_time = task[i].turn_time;
	}
	printf("������Ϣ������ϣ�����\n");
}

void BackData()
{
	for (int i = 0; i < num; i++)
	{
		strcpy(task[i].name, tp_task[i].name);
		task[i].come_time = tp_task[i].come_time;
		task[i].turn_time = tp_task[i].turn_time;
	}
	printf("������Ϣ��ԭ�ɹ�������\n");
}

void Print()
{
	printf("����������Ϣ��\n");
	printf("task_name  come_time   start_time   turn_time   end_time\n");
	for (int i = 0; i < num; i++)
	{
		printf("     %-9s%-13d", task[i].name, task[i].come_time);
		printf("%-10d%-12d", task[i].start_time, task[i].turn_time);
		printf("%-4d\n", task[i].end_time);
	}
}

bool cmp1(const struct Task &a, const struct Task &b)
{
	return a.turn_time < b.turn_time;
}

//����ҵ�����㷨
void SJF()
{
	/**
	���ܣ�ʵ�ֶ���ҵ�����㷨�������̵����н�����Ϣ
	���ս�������˳�������
	*/

	sort(task, task + num, cmp1);
	int countt = 0;
	for (int i = 0; i < num; i++)
	{
		printf("%s��������ִ��", task[i].name);
		for (int j = 0; j < 10; j++)
		{
			sleep(100 * task[i].turn_time); printf(".");
		}
		putchar('\n');

		//sleep(1000 * task[i].turn_time);  // ������ͣʱ�䣨��λ��ms)
		task[i].start_time = countt;
		countt += task[i].turn_time;
		task[i].end_time = countt;
	}
	printf("\n���н���ȫ��ִ����ϣ�����\n\n");

	Print();
}

bool cmp2(const struct Task &a, const struct Task &b)
{
	return a.come_time < b.come_time;
}

//�����ȷ����㷨
void FCFS()
{
	/**
	���ܣ�ʵ�������ȷ����㷨�������̵����н�����Ϣ
	���ս�������˳�������
	*/

	int countt = 0;
	sort(task, task + num, cmp2);

	for (int i = 0; i < num; i++)
	{
		printf("%s��������ִ��", task[i].name);
		for (int j = 0; j < 10; j++)
		{
			sleep(100 * task[i].turn_time); printf(".");
		}
		putchar('\n');

		//sleep(1000 * task[i].turn_time);  // ������ͣʱ�䣨��λ��ms)
		task[i].start_time = countt;
		countt += task[i].turn_time;
		task[i].end_time = countt;
	}
	printf("\n���н���ȫ��ִ����ϣ�����\n\n");

	Print();
}


bool cmp3(const struct Task &a, const struct Task &b)
{
	if (a.end_time < 0 && b.end_time < 0)
	{
		double ra = (a.wait_time + a.turn_time)*1.0 / a.turn_time;
		double rb = (b.wait_time + b.turn_time)*1.0 / b.turn_time;
		return ra > rb;
	}
	else
		return a.end_time < b.end_time;
}

bool cmp4(const struct Task &a, const struct Task &b)
{
	return a.come_time < b.come_time;
}

// ����ռ ����Ӧ�� ���ȵ����㷨
void HRRN()
{
	/**
	���ܣ����з���ռʽ ����Ӧ�� ���ȵ����㷨ִ�н��̣������̵����н�����Ϣ
	�����ʾ��
	*/
	//��ʼ�����̵Ľ���ʱ�� -1
	for (int i = 0; i < num; i++)
		task[i].end_time = -1;

	int countt = 0;  //��ʱ��
	while (true)
	{
		for (int i = 0; i < num; i++)
			task[i].wait_time = countt - task[i].come_time;
		sort(task, task + num, cmp3);

		if (task[0].end_time >= 0) break;

		printf("%s��������ִ��", task[0].name);
		for (int j = 0; j < 10; j++)
		{
			sleep(100 * task[0].turn_time); printf(".");
		}
		putchar('\n');

		//sleep(1000 * task[0].turn_time);  // ������ͣʱ�䣨��λ��ms)
		task[0].start_time = countt;
		countt += task[0].turn_time;
		task[0].end_time = countt;
	}
	printf("\n���н���ȫ��ִ����ϣ�����\n\n");

	sort(task, task + num, cmp4); // ���տ�ʼ���е�ʱ���С��������
	Print();
}

bool cmp5(const struct Task a, const struct Task b)
{
	return a.end_time < b.end_time;
}

// ��ռʽ ����Ӧ�� ���ȵ����㷨
void RR()
{
	/**
	���ܣ�������ռʽ ����Ӧ�� ���ȵ����㷨ִ�н��̣������̵����н�����Ϣ
	�����ʾ��
	*/

	//����ÿ�����̵ķ���ʱ��
	map<string, int> shift;
	shift.clear();

	for (int i = 0; i < num; i++)
		shift[task[i].name] = task[i].turn_time;


	//��ʼ�����̵Ľ���ʱ�� and ���̵Ŀ�ʼ����ʱ��  -�� -1
	for (int i = 0; i < num; i++)
		task[i].end_time = task[i].start_time = -1;

	int countt = 0;  //��ʱ��
	while (true)
	{
		for (int i = 0; i < num; i++)
			task[i].wait_time = countt - task[i].come_time;
		sort(task, task + num, cmp3);

		if (task[0].end_time >= 0) break;


		if (task[0].start_time < 0)
			task[0].start_time = countt;

		printf("%s��������ִ��", task[0].name);
		for (int j = 0; j < 10; j++)
		{
			sleep(100); printf(".");
		}
		putchar('\n');

		//sleep(1000);  // ������ͣʱ�䣨��λ��ms)
		countt++;     //����һ��ʱ��Ƭ  ��1 s)
		task[0].turn_time--;

		if (task[0].turn_time <= 0 && task[0].end_time < 0)
			task[0].end_time = countt;
	}
	printf("���н���ȫ��ִ����ϣ�����\n\n");

	//�ָ�ÿ�����̵ķ���ʱ��
	for (int i = 0; i < num; i++)
		task[i].turn_time = shift[task[i].name];

	sort(task, task + num, cmp5); // ���տ�ʼ���е�ʱ���С��������
	Print();
}

void Menu()
{
	printf("             ����\n");
	printf("\n\n       **** 0.�������������Ϣ\n");
	printf("       **** 1.FCFS�㷨\n");
	printf("       **** 2.SJF�㷨\n");
	printf("       **** 3.HRRN�㷨\n");
	printf("       **** 4.RR�㷨\n");
	printf("       **** 5.End Up Code!!!\n\n");
}

int main()
{
	int menu;
	int flag = 1;
	printf("             �����̵���ʵ�����\n\n");
	while (flag)
	{
		Menu();
		printf("����������: ");
		cin >> menu;
		switch (menu)
		{
		case 0:
			printf("��������̵ĸ���:  ");
			scanf("%d", &num);
			GetData();
			break;
		case 1:
			printf("     <���� FCFS �����㷨>\n");
			FCFS();
			break;
		case 2:
			printf("     <���� SJF �����㷨>\n");
			SJF();
			break;
		case 3:
			printf("     <��������ռʽ HRRN �����㷨>\n");
			HRRN();
			break;
		case 4:
			printf("     <����  RR �����㷨>\n");
			RR();
			break;
		case 5:
			flag = 0;
			break;

		}
		BackData();
	}
	return 0;
}