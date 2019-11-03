#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//#include<vld.h>
//0-100
void IsPrime(int n)
{
	int *p = (int *)malloc(sizeof(int)*n);
	int i = 0;
	int j = 0;
	assert(p != NULL);

	//下标代表判断的数字
	//元素值：0代不是素数   1代表是素数
	for (i = 0; i < n; i++)
	{
		p[i] = 1;//24 灯亮了
	}

	//
	for (i = 2; i < n; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				p[i] = 0;
			}
		}
	}

	for (i = 2; i < n; i++)
	{
		if (p[i] == 1)
			printf("%d ", i);
	}

	free(p);
	p = NULL;
}

int main()
{
	IsPrime(11);
	return 0;
}

#if 0
typedef struct MyStruct
{
	int a;//4
	int *arr;//4
}MyStruct;

int main()
{

	int i = 0;
	int *ptr = NULL;

	MyStruct *ps = (MyStruct *)malloc(sizeof(MyStruct));
	ps->arr = (int *)malloc(sizeof(int)* 100);
	assert(ps->arr != NULL);
	assert(ps != NULL);

	ps->a = 99;
	printf("%d\n", ps->a);

	for (i = 0; i < 100; i++)
	{
		ps->arr[i] = i;
	}

	for (i = 0; i < 100; i++)
	{
		printf("%d ", ps->arr[i]);
	}

	ptr = (int *)realloc(ps->arr, sizeof(int)* 100 * 2);
	if (ptr != NULL)
	{
		ps->arr = ptr;
	}

	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;


	return 0;
}


typedef struct MyStruct
{
	int a;
	int arr[0];
}MyStruct;

int main()
{
	/*
	MyStruct s;
	printf("%d\n",sizeof(s));*/
	int i = 0;
	MyStruct *ptr = NULL;
	MyStruct *ps = (MyStruct *)malloc(sizeof(MyStruct)+sizeof(int)* 100);
	assert(ps != NULL);
	ps->a = 99;
	printf("%d\n", ps->a);
	for (i = 0; i < 100; i++)
	{
		ps->arr[i] = i;
	}

	for (i = 0; i < 100; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	//体现柔性   
	ptr = (MyStruct *)realloc(ps, sizeof(MyStruct)+sizeof(int)* 100 * 2);
	if (ptr != NULL)
	{
		ps = ptr;
	}
	//.......................
	free(ps);
	ps = NULL;
	return 0;
}
#endif 
#if 0
void GetMemory(char **p)
{
	*p = (char *)malloc(100);
}
void Test()
{
	char *str = NULL;
	GetMemory(&str);
	//str永远为空
	strcpy(str, "hello world");
	printf("%s\n", str);
	free(str);
	str = NULL;
}
char *GetMemory2()
{
	char p[] = "hello world";
	return p;
}
void Test2()
{
	char *str = NULL;
	str = GetMemory2();
	printf(str);
}
void Test3(void)
{
	char *str = (char *)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}
int main()
{
	Test3();
	return 0;
}

int main()
{
	int *p = (int *)malloc(sizeof(int)* 10);
	int i = 0;
	assert(p != NULL);
	/*for(i = 0; i < 5;i++)
	{
	p++;
	}*/
	free(p);
	p = NULL;
	free(p);
	p = NULL;
	return 0;
}

int main()
{
	int arr[10] = { 0 };
	free(arr);//delete     new  
	return 0;
}

int main()
{
	int *p = (int *)malloc(sizeof(int)* 10);
	int i = 0;
	assert(p != NULL);
	for (i = 0; i <= 10; i++)
	{
		*(p + i) = 0;
	}
	free(p);
	p = NULL;
	return 0;
}

int main()
{
	int *p = (int *)malloc(INT_MAX);
	*p = 20;//空指针解引用错误  一定要先进行断言  空的判断
	//assert(p != NULL);  

	return 0;
}
#endif
#if 0
//void *calloc( size_t num, size_t size );
int main()
{
	//int *p = (int *)calloc(10,sizeof(int));// 0 
	//assert(p != NULL);

	//free(p);
	//p = NULL;
	int *p = (int *)malloc(sizeof(int)* 10);
	int *ptr = NULL;
	int i = 0;
	assert(p != NULL);

	//使用
	for (i = 0; i < 10; i++)
	{
		*(p + i) = 0;
		//p[i] = 0;
	}

	ptr = (int *)realloc(p, sizeof(int)* 10 * 2);
	//防止扩容失败 返回空 将原来内存丢失
	if (ptr != NULL)
	{
		p = ptr;
	}

	//使用
	for (i = 10; i < 20; i++)
	{
		*(p + i) = 0;
		//p[i] = 0;
	}

	for (i = 0; i < 20; i++)
	{
		printf("%d ", *(p + i));
	}

	free(p);
	p = NULL;

	return 0;
}


//void *malloc( size_t size );
int main()
{
	//局部数组：编译  确定    数组大小     运行的时候分配内存     栈 1M-2M
	int arr[10] = { 0 };  //连续的    栈  OXCCCCCC  烫烫
	int i = 0;
	int *p = (int *)malloc(sizeof(int)* 10);//连续的  参数:   字节   堆  默认值随机值
	//0xcdcdcdcd    囤
	//int *p = (int *)malloc(1024*1024*1024*2);
	assert(p != NULL);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}

	for (i = 0; i < 10; i++)
	{
		*(p + i) = 0;
		//p[i] = 0;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}


	//所有malloc  动态内存开辟  一定要由程序员手动进行内存释放
	free(p);//将这块内存释放  还给操作系统   如果不free 内存泄漏
	p = NULL;//   野指针
	//double *p2 = (double *)malloc(sizeof(double) * 10); //80



	return 0;
}
#endif