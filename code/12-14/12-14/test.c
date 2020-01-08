#include<Windows.h>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<iostream>
using namespace std;
#define sleep(n) Sleep(n*1000)
const int MAX_NUM = 10; //�����Ʒ��
struct ThreadInfo
{
	int tid;    //�߳�ID
	char role;  //���ݽ�ɫ
	double delay; //�߳��ӳ�
	double persist; //�̶߳�д��������ʱ��
};
HANDLE Empty;  //�ֲ��ٽ���Դ
HANDLE Full;
CRITICAL_SECTION P_mutex;  //ȫ���ٽ���Դ

int in = 0; //��һ����Դ
int out = 0;  //���һ����Դ
int buffer[MAX_NUM] = {}; //������
int current = 0;

//�����߽���
void ProducerThread(void *p)
{
	DWORD m_delay;	//�ӳ�ʱ�� 
	DWORD m_persist;	//����ʱ�� 
	DWORD wait_for_empty;
	int m_id;	//id 
	//�Ӳ����л����Ϣ 
	m_delay = ((ThreadInfo*)(p))->delay;
	m_persist = ((ThreadInfo*)(p))->persist;
	m_id = ((ThreadInfo*)(p))->tid;
	sleep(m_delay);	//���߳�����ʱ��==�ӳ�ʱ�� 
	printf("Producer %d sents the producing require !\n", m_id);	//�����߷����������� 
	wait_for_empty = WaitForSingleObject(Empty, -1);
	EnterCriticalSection(&P_mutex);	//�����ٽ���
	printf("Producer %d begins to produce product !\n", m_id);
	buffer[in] = current++;	//������Ʒ 
	in = (in + 1) % MAX_NUM;
	sleep(m_persist);
	printf("Producer %d finished producing !\n", m_id);	//��������ɲ���
	ReleaseSemaphore(Full, 1, NULL);	//V��full�� 
	printf("������+1\n");
	LeaveCriticalSection(&P_mutex);	//V��mutex�� 
	printf("Producer %d releases the power !\n", m_id);
}
//�����߽���
void ConsumerThread(void *p)
{
	DWORD m_delay;	//�ӳ�ʱ�� 
	DWORD m_persist;	//����ʱ�� 
	DWORD wait_for_full_mutex;
	int m_id;	//id 
	//�Ӳ����л����Ϣ 
	m_delay = ((ThreadInfo*)(p))->delay;
	m_persist = ((ThreadInfo*)(p))->persist;
	m_id = ((ThreadInfo*)(p))->tid;
	sleep(m_delay);	//���߳�����ʱ��==�ӳ�ʱ�� 
	printf("Comsumer %d sents the consuming require !\n", m_id);	//�����߷����������� 
	WaitForSingleObject(Full, -1);	//P(full);
	EnterCriticalSection(&P_mutex);	//P��mutex�� 
	printf("Consumer %d begins to consume product !\n", m_id);
	buffer[out] = -1;	//�������� 
	out = (out + 1) % MAX_NUM;
	current--;
	sleep(m_persist);
	printf("Consumer %d finished consuming !\n", m_id);	//������������Ѳ��� 
	ReleaseSemaphore(Empty, 1, NULL);	//V��empty�� 
	printf("������-1\n");
	LeaveCriticalSection(&P_mutex);	//��mutex�� 
	printf("Comsumer %d releases the power\n", m_id);
}
int main()
{
	system("color 3f"); //�ı���ɫ
	DWORD n_thread = 0;  //�߳���Ŀ
	DWORD thread_ID;     //�߳�ID
	HANDLE h_thread[20];  //�̶߳�������
	ThreadInfo thread_info[20];
	//��ʼ��ͬ������
	Full = CreateSemaphore(NULL, 0, MAX_NUM, "mutex_for_full");
	Empty = CreateSemaphore(NULL, MAX_NUM, MAX_NUM, "mutex_for_empty");
	InitializeCriticalSection(&P_mutex);
	//��ȡ�����ļ�
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
			//�������߽���
			h_thread[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)(ProducerThread), &thread_info[i], 0, &thread_ID);
		}
		else if (thread_info[i].role == 'C')
		{
			//����д�߳� 
			h_thread[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)(ConsumerThread), &thread_info[i], 0, &thread_ID);
		}
	}
	//�ȴ����е��߳̽��� 
	DWORD wait_for_all = WaitForMultipleObjects(n_thread, h_thread, TRUE, -1);
	CloseHandle(Full);
	CloseHandle(Empty);
	cout << "All producer and consumer have finished operating !" << endl;
	_getch();
	return 0;
}