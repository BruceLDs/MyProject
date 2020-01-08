#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
/*定义内存的大小为512*/
#define MEMSIZE 512
/*最小剩余内存*/
#define MINSIZE 2

/*内存分区空间表结构*/
typedef struct _MemoryInfomation
{
	/*起始地址*/
	int start;
	/*大小*/
	int Size;
	/*状态 F:空闲(Free) U:占用(Used) E 结束(End)*/
	char status;
} MEMINFO;

/*内存空间信息表*/
MEMINFO MemList[MEMSIZE];

/*显示内存状态*/
void Display()
{
	int i, used = 0;//记录可以使用的总空间量
	printf("\n---------------------------------------------------\n");
	printf("%5s%15s%15s%15s", "数字", "起始地址", "大小", "状态");
	printf("\n---------------------------------------------------\n");
	for (i = 0; i<MEMSIZE&&MemList[i].status != 'e'; i++)
	{
		if (MemList[i].status == 'u')
		{
			used += MemList[i].Size;
		}
		printf("%5d%15d%15d%15s\n", i, MemList[i].start, MemList[i].Size, MemList[i].status == 'u' ? "占用" : "空闲");
	}
	printf("\n----------------------------------------------\n");
	printf("内存信息:%-10d 已占用大小:%-10d 空闲大小:%-10d\n", MEMSIZE, used, MEMSIZE - used);
}

/*初始化所有变量*/
void InitMemList()
{
	int i;
	MEMINFO temp = { 0, 0, 'e' };
	//初始化空间信息表
	for (i = 0; i<MEMSIZE; i++)
	{
		MemList[i] = temp;
	}
	//起始地址为0
	MemList[0].start = 0;
	//空间初始为最大
	MemList[0].Size = MEMSIZE;
	//状态为空闲
	MemList[0].status = 'f';
}
void FirstFit_new()
{
	int i, j, flag = 0;
	int request;
	printf("首次适应算法:请输入需要请求的空间大小\n");
	scanf("%d", &request);
	//遍历数组
	for (i = 0; i<MEMSIZE&&MemList[i].status != 'e'; i++)
	{
		//满足所需要的大小,且是空闲空间
		if (MemList[i].Size >= request&&MemList[i].status == 'f')
		{
			//如果小于规定的最小差则将整个空间分配出去
			if (MemList[i].Size - request <= MINSIZE)
			{
				MemList[i].status = 'u';
			}
			else
			{
				//将i后的信息表元素后移
				for (j = MEMSIZE - 2; j>i; j--)
				{
					MemList[j + 1] = MemList[j];
				}

				//将i分成两部分，使用低地址部分
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
	//没有找到符合分配的空间
	if (flag != 1 || i == MEMSIZE || MemList[i].status == 'e')
	{
		printf("内存不足!!\n");
	}
	Display();
}
void BadFit_new()
{
	int i, j, k, flag, request;
	printf("最坏适应算法:请输入需要请求的空间大小\n");
	scanf("%d", &request);
	j = 0;
	flag = 0;
	k = 0;
	//保存满足要求的最大空间
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
		printf("内存不足!!\n");
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


//释放一块内存
void del_t()
{
	int i, number;
	printf("\n请输入想释放的空间的数字:\n");
	scanf("%d", &number);
	//输入的空间是使用的
	if (MemList[number].status == 'u')
	{
		MemList[number].status = 'f';//标志为空闲
		if (MemList[number + 1].status == 'f')//右侧空间为空则合并
		{
			MemList[number].Size += MemList[number].Size;//大小合并
			for (i = number + 1; i<MEMSIZE - 1 && MemList[i].status != 'e'; i++) //i后面的空间信息表元素后移
			{
				if (i>0)
				{
					MemList[i] = MemList[i + 1];
				}
			}
		}
		//左测空间空闲则合并
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
		printf("输入的数字不对!\n");
	}
	Display();
}

void BestFit_new()
{
	int i, j, t, flag, request;
	printf("最好适应算法:请输入需要请求的空间大小\n");
	scanf("%d", &request);
	j = 0;
	flag = 0;
	t = MEMSIZE;
	//保存满足要求的最大空间
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
		printf("内存不足\n");
		j = i;
	}
	else if (MemList[i].Size - request <= MINSIZE)  //如果小于规定的最小差则将整个空间分配出去
	{
		MemList[i].status = 'u';
	}
	else
	{
		//将i后的信息表元素后移
		for (j = MEMSIZE - 2; j>i; j--)
		{
			MemList[j + 1] = MemList[j];
		}

		//将i分成两部分，使用低地址部分
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
	printf("         1.首次适应算法\t     2.最佳适应算法\n");
	printf("         3.最坏适应算法\t     4.删除已分配空间\n");
	printf("         5.显示内存信息\t     6. 退出程序\n");
	printf("=================================================\n");
}
int main()
{
	int x;
	InitMemList();//变量初始化
	while (1)
	{
		meun();
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			FirstFit_new();//首次适应算法
			break;
		case 2:
			BestFit_new();//最佳适应算法
			break;
		case 3:
			BadFit_new();//最坏适应算法
			break;
		case 4:
			del_t();//删除已经使用完毕的空间
			break;
		case 5:
			Display();//显示内存分配情况
			break;
		case 6:
			exit(0);
		}
	}
	return 0;
}
