#define  _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include<iomanip>
using namespace std;
struct fcfs{ //先来先服务算法从这里开始
	char name[10];
	float arrivetime;
	float servicetime;
	float starttime;
	float finishtime;
	float zztime;
	float dqzztime;
}; //定义一个结构体，里面包含的有一个进程相关的信息
fcfs a[100];
void input(fcfs *p, int N)
{
	int i;
	cout << endl;
	printf(" 请您输入进程的 名字 到达时间 服务时间: (例如: a 0 100)\n\n");
	for (i = 0; i <= N - 1; i++)
	{
		printf(" 请您输入进程 %d 的信息:\t", i + 1);
		scanf("\t\t\t%s%f%f", &p[i].name, &p[i].arrivetime, &p[i].servicetime);
	}
}
void Print(fcfs *p, float arrivetime, float servicetime, float starttime, float
	finishtime, float zztime, float dqzztime, int N)
{
	int k;
	printf("\n\n 调用先来先服务算法以后进程运行的顺序是 : ");
	printf("%s", p[0].name);
	for (k = 1; k<N; k++)
	{
		printf("-->%s", p[k].name);
	}
	cout << endl;
	printf("\n 具体进程调度信息 :\n");
	printf("\t 进程名 到达时间 服务时间 开始时间 结束时间 周转时间 带权周转时间 \n");
	for (k = 0; k <= N - 1; k++)
	{
		printf("\t%s\t%-.2f\t %-.2f\t %-.2f\t %-.2f\t %-.2f\t %-.2f\n", p[k].name, p[k].arrivetime,
			p[k].servicetime, p[k].starttime, p[k].finishtime, p[k].zztime, p[k].dqzztime);
	}
	getchar(); //此处必须要有这个函数，否则就看不到显示器上面的输出，可以看到的结果只是一闪而过的一个框剪
}
void sort(fcfs *p, int N) //排序
{
	for (int i = 0; i <= N - 1; i++)
	for (int j = 0; j <= i; j++)
	if (p[i].arrivetime<p[j].arrivetime)
	{
		fcfs temp;
		temp = p[i];
		p[i] = p[j];
		p[j] = temp;
	}
}
void deal(fcfs *p, float arrivetime, float servicetime, float starttime, float
	finishtime, float &zztime, float &dqzztime, int N) //运行阶段
{
	int k;
	for (k = 0; k <= N - 1; k++)
	{
		if (k == 0)
		{
			p[k].starttime = p[k].arrivetime;
			p[k].finishtime = p[k].arrivetime + p[k].servicetime;
		}
		else
		{
			p[k].starttime = p[k - 1].finishtime;
			p[k].finishtime = p[k - 1].finishtime + p[k].servicetime;
		}
	}
	for (k = 0; k <= N - 1; k++)
	{
		p[k].zztime = p[k].finishtime - p[k].arrivetime;
		p[k].dqzztime = p[k].zztime / p[k].servicetime;
	}
}
void FCFS(fcfs *p, int N)
{
	float
		arrivetime = 0, servicetime = 0, starttime = 0, finishtime = 0, zztime = 0, dqzztime = 0;
	sort(p, N);
	deal(p, arrivetime, servicetime, starttime, finishtime, zztime, dqzztime, N);
	Print(p, arrivetime, servicetime, starttime, finishtime, zztime, dqzztime, N);
	getchar();
} //先来先服务算法到此结束

struct sjf{// 最短进程优先调度算法从这里开始
	char name[10];
	float arrivetime; //到达时间
	float servicetime; //运行时间
	float starttime; //开始时间
	float finishtime; //完成时间
};
sjf a1[100];
void input(sjf *p, int N1)// 进程信息输入
{
	int i;
	cout << endl;
	printf(" 请您输入进程的 名字 到达时间 服务时间: (例如: a 0 100)\n");
	for (i = 0; i <= N1 - 1; i++)
	{
		printf(" 请您输入进程 %d 的信息:\t", i + 1);
		scanf("\t\t\t%s%f%f", &p[i].name, &p[i].arrivetime, &p[i].servicetime);
	}
}
void Print(sjf *p, float arrivetime, float servicetime, float starttime, float
	finishtime, int N1)// 最终结果输出
{
	int k;
	printf("\n\t 调用最短进程优先调度算法以后进程的调度顺序为 :");
	printf("%s", p[0].name);
	for (k = 1; k<N1; k++)
	{
		printf("-->%s", p[k].name);
	}
	cout << endl;
	printf("\n 给个进程具体调度信息如下 :\n");
	printf("\n\t 进程名 \t 到达时间 \t 运行时间 \t 开始时间 \t 完成时间 \n");
	for (k = 0; k <= N1 - 1; k++)
	{
		printf("\t%s\t %-.2f\t\t %-.2f\t\t %-.2f\t\t %-.2f\t\n",p[k].name,p[k].arrivetime,
			p[k].servicetime, p[k].starttime, p[k].finishtime);
	}
	getchar();
}
void sort(sjf *p, int N1)// 排序
{
	for (int i = 0; i <= N1 - 1; i++)
	for (int j = 0; j <= i; j++)
	if (p[i].arrivetime<p[j].arrivetime)
	{
		sjf temp;
		temp = p[i];
		p[i] = p[j];
		p[j] = temp;
	}
}
void deal(sjf *p, float arrivetime, float servicetime, float starttime, float
	finishtime, int N1)// 运行阶段
{
	int k;
	for (k = 0; k <= N1 - 1; k++)
	{
		if (k == 0)
		{
			p[k].starttime = p[k].arrivetime;
			p[k].finishtime = p[k].arrivetime + float(p[k].servicetime) / 60;
		}
		else
		{
			p[k].starttime = p[k - 1].finishtime;
			p[k].finishtime = p[k - 1].finishtime + float(p[k].servicetime) / 60;
		}
	}
}
void sjff(sjf *p, int N1)
{
	float arrivetime = 0, servicetime = 0, starttime = 0, finishtime = 0;
	sort(p, N1);
	for (int m = 0; m<N1 - 1; m++)
	{
		if (m == 0)
			p[m].finishtime = p[m].arrivetime + float(p[m].servicetime) / 60;
		else
			p[m].finishtime = p[m - 1].finishtime + float(p[m].servicetime) / 60;
		int i = 0;
		for (int n = m + 1; n <= N1 - 1; n++)
		{
			if (p[n].arrivetime <= p[m].finishtime)
				i++;
		}
		float min = p[m + 1].servicetime;
		int next = m + 1;
		for (int k = m + 1; k<m + i; k++)
		{
			if (p[k + 1].servicetime<min)
			{
				min = p[k + 1].servicetime;
				next = k + 1;
			}
		}
		sjf temp;
		temp = p[m + 1];
		p[m + 1] = p[next];
		p[next] = temp;
	}
	deal(p, arrivetime, servicetime, starttime, finishtime, N1);
	Print(p, arrivetime, servicetime, starttime, finishtime, N1);
	getchar();
}//最短进程优先调度算法到这里结束
char menu()//用来输出相关信息的函数
{
	char cse1;
	while (1)
	{
		system("cls");
		fflush(stdin);
		cout << endl;
		cout << endl;
		cout << "\t" << "||" << "\t         实 验 一 进 程 调 度 算法 实 验       "<<"\t\t"<<" || "<<endl;
		cout << "\t" << "|| "<<endl ;
		cout << "\t" << "||" << "\t\t 1. 先 来 先 服 务 调 度 算 法    "<<"\t\t"<<" || "<<endl;
		cout << "\t" << "|| "<<endl ;
		cout << "\t" << "||" << "\t\t 2. 最 短 进 程 优 先 调 度 算 法"<<"\t\t"<<" || "<<endl;
		cout << "\t" << "|| " << endl;
		cout << "\t" << "||" << "\t\t 3. 优先级调 度 算 法              "   << "\t\t" << " || " << endl;
		cout << "\t" << "|| " << endl;
		cout << "\t" << "||" << "\t\t 4. 时间片轮转调 度 算 法        " << "\t\t" << " || " << endl;
		cout << endl;
		cout << endl;
		cout << "\t\t 请输入您的选择（ 1/2）：";
		cse1 = getchar();
		if (cse1<'1' || cse1>'2')
			cout << "你的输入有错！ " << endl;
		else
			break;
	}
	return cse1;
}
int main(int argc, char *argv[])
{
	while (1)
	{
		switch (menu())
		{
		case '1':
			int N;
			cout << endl;
			cout << endl;
			printf("\t\t<<---!!!@@@ 先来先服务调度算法@@@!!!--->>\n");
				cout << endl;
			printf(" 输入进程数目 :");
			scanf("%d", &N);
			input(a, N);
			FCFS(a, N);
		case '2':
			int N1;
			cout << endl;
			cout << endl;
			printf("\t\t<<---!!!@@@ 最短进程优先调度算法 @@@!!!--->>\n");
				cout << endl;
			printf(" 输入进程数目 : ");
			scanf("%d", &N1);
			input(a1, N1);
			sjf *b = a1;
			sjf *c = a1;
			sjff(b, N1);
			getchar();
		}
	}
	system("pause");
	return 0;
}
