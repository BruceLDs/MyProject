#define  _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stddef.h>


union un
{
	int i;
	char ch;
}uu;

union Un1
{
	char c[5];//5   1  8     1      0-4
	int i;//        4   4   8    4      0-3 
};//8


union Un2
{
	short c[9];//2  8   2   0-17
	int i;//4  8   4            0 - 3      14    ---> 20
};//

int main()
{
	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));
	//uu.i = 0x12345678;
	//printf("0x%x\n",uu.ch);//78
	return 0;
}


#if 0
//#define Mon 1        不能调试的      全局
//#define Mon 1
//#define Mon 1
//#define Mon 1
//#define Mon 1
//#define Mon 1
//#define Mon 1
enum Day
{
	Mon,//局部  
	Tues,
	Wed = 4,
	Thur,//5
	Fri,
	Sat,
	Sun
};
enum ChatType
{
	AllChats,//0
	OneChats//1
};
//聊天类型  --》  枚举的类型     (AllChats)群聊：1      (OneChats) 私聊   ： 2  
// 坦白说:3
int main()
{
	/*enum Day  day = Wed;
	day = 1; //error  类型不匹配
	*/
	printf("%d\n", Thur);
	return 0;
}

struct A
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};

struct S
{
	char a : 3;
	char b : 4;//1
	char c : 5;//1
	char d : 4;//1
};

int main()
{
	struct S s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
	return 0;
}






#pragma pack(8)
struct S3
{
	double d;//8   8   8      0-7
	char c;//1  8         1           8
	int i;//4     8         4            12-15       0-15
};//16
#pragma pack()
#pragma pack(4)
struct S33
{
	double d;//8   4   4        0 - 7 
	int i;//       4    4              4         8-11
	char c;//   1    4    1        12             12
};
#pragma pack()

#pragma pack(4)
struct S333
{
	short sh;//2   4    2   0-1
	char ch;//1    4    1   2
	double  i;//8  4    4  4-11  
};//12
#pragma pack()

#pragma pack(8)
struct S3333
{
	short sh;//2   8    2   0-1
	char ch;//1    8    1   2
	double  i;//8  8    8   8-15
};
#pragma pack()
#pragma pack(1)
struct S33333
{
	short sh;//2   1   1   0-1
	char ch;//1    1    1   2
	double  i;//8  1    1   3-10
};
#pragma pack()

struct Stu
{
	int i;//0-3
	short ch;//4-5    6       8
};
//#define offsetof(s,m)   (size_t)&(((s *)0)->m)
int main()
{
	/*printf("%d\n", offsetof(struct Stu,i));
	printf("%d\n", offsetof(struct Stu,ch));*/

	printf("%d\n", &(((struct Stu *)0)->ch));
	//printf("%d\n", sizeof(struct S33333));
	return 0;
}


//练习1
struct S1
{
	char c1;//1
	int i;//4
	char c2;//1
};

struct S2
{
	char c1;
	char c2;
	int i;
};
struct SS2
{
	int i;
	char ch[6];
};
//练习3
struct S3
{
	double d;//8   8   8      0-7
	char c;//1  8         1           8
	int i;//4     8         4            12-15       0-15
};//16
struct S33
{
	int d;//4   8   4     0-3
	char c;//1  8  1     4
	int i;//4   8  4        8-11         12
};
struct S4
{
	char c1;//1  8   1         0
	struct S33 s3;//12    (结构体当中每个成员的最大对齐数)4   4     4-15   
	double d;//8  8   8          16-23
};
int main()
{
	//printf("%d\n", offsetof(struct S1,c1));//0
	//printf("%d\n", offsetof(struct S1,i));//4
	//printf("%d\n", offsetof(struct S1,c2));//8

	printf("%d\n", sizeof(struct S4));
	return 0;
}


//
//typedef struct Student
//{
//	char name[20];
//	int age;
//}STU;
////匿名结构体
//struct 
//{
//	int x;
//	int y;
//}s;
//
//struct 
//{
//	char name[20];
//}*p;

typedef struct Node
{
	int data;
	struct Node *next;
	//struct Node node;
}Node;

int main()
{
	/*struct Student stu1 = {"zhansan",18};
	STU stu2 = {};*/
	//p = &s;
	return 0;
}



void *Mymemcpy(void *dest, const void *src, int count)
{
	void *ret = dest;
	while (count--)
	{
		*(char *)dest = *(char *)src;
		((char *)dest)++;
		((char *)src)++;
	}
	return ret;
}


void *Mymemmove(void *dest, const void *src, int count)
{
	void *ret = dest;
	if (dest < src)
	{
		while (count--)
		{
			*(char *)dest = *(char *)src;
			((char *)dest)++;
			((char *)src)++;
		}
	}
	else
	{
		while (count--)
		{
			*((char *)dest + count) = *((char *)src + count);
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//Mymemcpy(arr+2,arr,16);
	Mymemmove(arr + 2, arr, 16);
	//Mymemmove(arr,arr+2,16);
	return 0;
}
#endif