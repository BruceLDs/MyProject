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
	char name[10]; // 进程名称
	int come_time; // 到达时间
	int turn_time; // 运行时间
	int start_time; // 开始运行时间
	int end_time;// 结束运行时间
	int wait_time; // 等待时间
}task[N], tp_task[N];

int num;//进程数目

void sleep(int n)
{
	int st = clock();
	while ((clock() - st) <= n);
}

void GetData()
{
	printf("请输入每个进程的名称，到达时间，服务时间\n");
	for (int i = 0; i < num; i++)
	{
		printf("第%d个进程信息输入：\n", i + 1);
		scanf("%s%d%d", task[i].name, &task[i].come_time, &task[i].turn_time);
		strcpy(tp_task[i].name, task[i].name);
		tp_task[i].come_time = task[i].come_time;
		tp_task[i].turn_time = task[i].turn_time;
	}
	printf("进程信息输入完毕！！！\n");
}

void BackData()
{
	for (int i = 0; i < num; i++)
	{
		strcpy(task[i].name, tp_task[i].name);
		task[i].come_time = tp_task[i].come_time;
		task[i].turn_time = tp_task[i].turn_time;
	}
	printf("进程信息还原成功！！！\n");
}

void Print()
{
	printf("进程运行信息：\n");
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

//短作业优先算法
void SJF()
{
	/**
	功能：实现短作业优先算法，将进程的运行结束信息
	按照进程运行顺序输出。
	*/

	sort(task, task + num, cmp1);
	int countt = 0;
	for (int i = 0; i < num; i++)
	{
		printf("%s进程正在执行", task[i].name);
		for (int j = 0; j < 10; j++)
		{
			sleep(100 * task[i].turn_time); printf(".");
		}
		putchar('\n');

		//sleep(1000 * task[i].turn_time);  // 程序暂停时间（单位：ms)
		task[i].start_time = countt;
		countt += task[i].turn_time;
		task[i].end_time = countt;
	}
	printf("\n所有进程全部执行完毕！！！\n\n");

	Print();
}

bool cmp2(const struct Task &a, const struct Task &b)
{
	return a.come_time < b.come_time;
}

//先来先服务算法
void FCFS()
{
	/**
	功能：实现先来先服务算法，将进程的运行结束信息
	按照进程运行顺序输出。
	*/

	int countt = 0;
	sort(task, task + num, cmp2);

	for (int i = 0; i < num; i++)
	{
		printf("%s进程正在执行", task[i].name);
		for (int j = 0; j < 10; j++)
		{
			sleep(100 * task[i].turn_time); printf(".");
		}
		putchar('\n');

		//sleep(1000 * task[i].turn_time);  // 程序暂停时间（单位：ms)
		task[i].start_time = countt;
		countt += task[i].turn_time;
		task[i].end_time = countt;
	}
	printf("\n所有进程全部执行完毕！！！\n\n");

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

// 非抢占 高响应比 优先调度算法
void HRRN()
{
	/**
	功能；运行非抢占式 高响应比 优先调度算法执行进程，将进程的运行结束信息
	输出显示。
	*/
	//初始化进程的结束时间 -1
	for (int i = 0; i < num; i++)
		task[i].end_time = -1;

	int countt = 0;  //计时器
	while (true)
	{
		for (int i = 0; i < num; i++)
			task[i].wait_time = countt - task[i].come_time;
		sort(task, task + num, cmp3);

		if (task[0].end_time >= 0) break;

		printf("%s进程正在执行", task[0].name);
		for (int j = 0; j < 10; j++)
		{
			sleep(100 * task[0].turn_time); printf(".");
		}
		putchar('\n');

		//sleep(1000 * task[0].turn_time);  // 程序暂停时间（单位：ms)
		task[0].start_time = countt;
		countt += task[0].turn_time;
		task[0].end_time = countt;
	}
	printf("\n所有进程全部执行完毕！！！\n\n");

	sort(task, task + num, cmp4); // 按照开始运行的时间从小到大排序
	Print();
}

bool cmp5(const struct Task a, const struct Task b)
{
	return a.end_time < b.end_time;
}

// 抢占式 高响应比 优先调度算法
void RR()
{
	/**
	功能；运行抢占式 高响应比 优先调度算法执行进程，将进程的运行结束信息
	输出显示。
	*/

	//备份每个进程的服务时间
	map<string, int> shift;
	shift.clear();

	for (int i = 0; i < num; i++)
		shift[task[i].name] = task[i].turn_time;


	//初始化进程的结束时间 and 进程的开始运行时间  -》 -1
	for (int i = 0; i < num; i++)
		task[i].end_time = task[i].start_time = -1;

	int countt = 0;  //计时器
	while (true)
	{
		for (int i = 0; i < num; i++)
			task[i].wait_time = countt - task[i].come_time;
		sort(task, task + num, cmp3);

		if (task[0].end_time >= 0) break;


		if (task[0].start_time < 0)
			task[0].start_time = countt;

		printf("%s进程正在执行", task[0].name);
		for (int j = 0; j < 10; j++)
		{
			sleep(100); printf(".");
		}
		putchar('\n');

		//sleep(1000);  // 程序暂停时间（单位：ms)
		countt++;     //运行一个时间片  （1 s)
		task[0].turn_time--;

		if (task[0].turn_time <= 0 && task[0].end_time < 0)
			task[0].end_time = countt;
	}
	printf("所有进程全部执行完毕！！！\n\n");

	//恢复每个进程的服务时间
	for (int i = 0; i < num; i++)
		task[i].turn_time = shift[task[i].name];

	sort(task, task + num, cmp5); // 按照开始运行的时间从小到大排序
	Print();
}

void Menu()
{
	printf("             命令\n");
	printf("\n\n       **** 0.输入进程数据信息\n");
	printf("       **** 1.FCFS算法\n");
	printf("       **** 2.SJF算法\n");
	printf("       **** 3.HRRN算法\n");
	printf("       **** 4.RR算法\n");
	printf("       **** 5.End Up Code!!!\n\n");
}

int main()
{
	int menu;
	int flag = 1;
	printf("             《进程调度实验程序》\n\n");
	while (flag)
	{
		Menu();
		printf("请输入命令: ");
		cin >> menu;
		switch (menu)
		{
		case 0:
			printf("请输入进程的个数:  ");
			scanf("%d", &num);
			GetData();
			break;
		case 1:
			printf("     <启动 FCFS 调度算法>\n");
			FCFS();
			break;
		case 2:
			printf("     <启动 SJF 调度算法>\n");
			SJF();
			break;
		case 3:
			printf("     <启动非抢占式 HRRN 调度算法>\n");
			HRRN();
			break;
		case 4:
			printf("     <启动  RR 调度算法>\n");
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