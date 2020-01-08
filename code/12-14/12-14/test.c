#include<Windows.h>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<iostream>
using namespace std;
#define sleep(n) Sleep(n*1000)
const int MAX_NUM = 10; //定义产品数
struct ThreadInfo
{
	int tid;    //线程ID
	char role;  //扮演角色
	double delay; //线程延迟
	double persist; //线程读写操作持续时间
};
HANDLE Empty;  //局部临界资源
HANDLE Full;
CRITICAL_SECTION P_mutex;  //全局临界资源

int in = 0; //第一个资源
int out = 0;  //最后一个资源
int buffer[MAX_NUM] = {}; //缓冲区
int current = 0;

//生产者进程
void ProducerThread(void *p)
{
	DWORD m_delay;	//延迟时间 
	DWORD m_persist;	//持续时间 
	DWORD wait_for_empty;
	int m_id;	//id 
	//从参数中获得信息 
	m_delay = ((ThreadInfo*)(p))->delay;
	m_persist = ((ThreadInfo*)(p))->persist;
	m_id = ((ThreadInfo*)(p))->tid;
	sleep(m_delay);	//让线程休眠时间==延迟时间 
	printf("Producer %d sents the producing require !\n", m_id);	//生产者发送生产请求 
	wait_for_empty = WaitForSingleObject(Empty, -1);
	EnterCriticalSection(&P_mutex);	//进入临界区
	printf("Producer %d begins to produce product !\n", m_id);
	buffer[in] = current++;	//生产产品 
	in = (in + 1) % MAX_NUM;
	sleep(m_persist);
	printf("Producer %d finished producing !\n", m_id);	//生产者完成操作
	ReleaseSemaphore(Full, 1, NULL);	//V（full） 
	printf("缓冲区+1\n");
	LeaveCriticalSection(&P_mutex);	//V（mutex） 
	printf("Producer %d releases the power !\n", m_id);
}
//消费者进程
void ConsumerThread(void *p)
{
	DWORD m_delay;	//延迟时间 
	DWORD m_persist;	//持续时间 
	DWORD wait_for_full_mutex;
	int m_id;	//id 
	//从参数中获得信息 
	m_delay = ((ThreadInfo*)(p))->delay;
	m_persist = ((ThreadInfo*)(p))->persist;
	m_id = ((ThreadInfo*)(p))->tid;
	sleep(m_delay);	//让线程休眠时间==延迟时间 
	printf("Comsumer %d sents the consuming require !\n", m_id);	//消费者发送消费请求 
	WaitForSingleObject(Full, -1);	//P(full);
	EnterCriticalSection(&P_mutex);	//P（mutex） 
	printf("Consumer %d begins to consume product !\n", m_id);
	buffer[out] = -1;	//进行消费 
	out = (out + 1) % MAX_NUM;
	current--;
	sleep(m_persist);
	printf("Consumer %d finished consuming !\n", m_id);	//消费者完成消费操作 
	ReleaseSemaphore(Empty, 1, NULL);	//V（empty） 
	printf("缓冲区-1\n");
	LeaveCriticalSection(&P_mutex);	//（mutex） 
	printf("Comsumer %d releases the power\n", m_id);
}
int main()
{
	system("color 3f"); //改变颜色
	DWORD n_thread = 0;  //线程数目
	DWORD thread_ID;     //线程ID
	HANDLE h_thread[20];  //线程对象数组
	ThreadInfo thread_info[20];
	//初始化同步对象
	Full = CreateSemaphore(NULL, 0, MAX_NUM, "mutex_for_full");
	Empty = CreateSemaphore(NULL, MAX_NUM, MAX_NUM, "mutex_for_empty");
	InitializeCriticalSection(&P_mutex);
	//读取输入文件
	ifstream inFile;
	inFile.open("test2.txt");
	if (!inFile) {
		printf("error in open file !\n");
		return -1;
	}
	cout << "Producer and Consumer:" << endl;
	while (inFile)
	{
		inFile >> thread_info[n_thread].tid;
		inFile >> thread_info[n_thread].role;
		inFile >> thread_info[n_thread].delay;
		inFile >> thread_info[n_thread++].persist;
		inFile.get();
	}
	for (int i = 0; i < (int)(n_thread); i++)
	{
		if (thread_info[i].role == 'P')
		{
			//创建读者进程
			h_thread[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)(ProducerThread), &thread_info[i], 0, &thread_ID);
		}
		else if (thread_info[i].role == 'C')
		{
			//创建写线程 
			h_thread[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)(ConsumerThread), &thread_info[i], 0, &thread_ID);
		}
	}
	//等待所有的线程结束 
	DWORD wait_for_all = WaitForMultipleObjects(n_thread, h_thread, TRUE, -1);
	CloseHandle(Full);
	CloseHandle(Empty);
	cout << "All producer and consumer have finished operating !" << endl;
	_getch();
	return 0;
}