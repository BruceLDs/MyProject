#define  _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include<string.h>
#include<stdlib.h>
#define SIZE 10 //标识符
#define PI  3.14159
#define CASE break;case
#define ADD2(x,y)  (x)*(y)
#define ADD(x,y)  ((x)+(y))
//#define MAX(X,Y)  (((MAX(X,Y) > (Y)) ? ((X) : (Y)))
//续行符
#define PRINTF1(val) printf("the val of "#val" is %d\n",val);
#define PRINTF(val,format) \
	printf("the val of "#val" is "format"\n", val);
#define CAT(X,Y)  X##Y

#define Bit(x)  bit##x

//调用函数的时候：当前函数开辟内存
#define MALLOC(num, type)\
	(type *)malloc(num * sizeof(type))


//inline 
int MAX2(int a, int b)
{
	return a>b ? a : b;
}
#define MAX(X,Y)  ( (X) > (Y) ? (X) : (Y)  )

#define M
int main()
{
	printf("%d\n", 1);
	//#ifdef M
#if defined(M)
	printf("%d\n", 2);
#endif
	return 0;
}

#if 0
#define DEBUG

int main()
{
	printf("hello bit\n");
#ifdef DEBUG 
	printf("hello\n");
#endif
	return 0;
}


int main()
{
	//MALLOC(10,int);

	int a = 40;
	int b = 20;
	printf("%d\n", MAX(a++, b++));//  41 
	//#undef MAX
	printf("%d\n", MAX(a++, b++));//  41 
	//    ( (a++) > (b++) ? (a++) : (b++)  )
	//a41    b21      41 
	//printf("%d,%d\n",a,b);//42  21
	/*
	int MAX2(int a,int b)
	{
	return a>b?a:b;
	}
	*/
	printf("%d\n", MAX2(a++, b++));//40
	printf("%d,%d\n", a, b);//41  21
	return 0;
}


int main()
{
	int a = 10;
	int b = 20;

	/*int Bit(1)=1,Bit(2)=2,Bit(3)=3;
	printf("bit1=%d\n",bit1);
	printf("bit2=%d\n",bit2);
	printf("bit3=%d\n",bit3);*/
	/*int bit1 = 10;
	printf("%d\n",CAT(bit,1));*/

	//int a = 10;
	//int b = 20;
	//double d = 12.25;
	////printf("%d\n",a);
	//PRINTF(a,"%d");
	//PRINTF(b,"%d");
	//PRINTF(d,"%lf");
	return 0;
}

int main()
{
	//int a = 10;
	//int b = 20;
	//printf("SIZE = %d\n",SIZE);
	char* p = "hello "  "bit\n";
	printf("%s\n", p);
	//printf("%d\n",9*MAX(a,b));//270
	//9*((10)+(20))=110
	//(10+10)*20=210

	return 0;
}


int main()
{

	int a = 10;
	/*if(a)
	a = 10;    ;
	else
	{}*/

	switch (a)
	{
	case 1:
		printf("hello\n");
		CASE 2 :
		CASE 4 :

	}
	/*FILE *pf = fopen("test.txt","w");
	if(pf == NULL)
	{
	printf("%s\n",strerror(errno));
	}
	printf("%s,%d,%s,%s\n",__FILE__,__LINE__,__DATE__,
	__TIME__);*/
	return 0;
}
#endif