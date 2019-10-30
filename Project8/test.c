#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
/*
a   b
4   0000 0100
6   0000 0110

4+6
(a&b)*2 + (a^b) = a+b;


*/

int Func(int a, int b)
{
	//位运算
	int ret = (a&b) + ((a^b) >> 1);
	//(a+b)/2 ==> a/2+b/2;
	return ret;
}

int main()
{
	int a = 7;
	int b = 4;
	/*int ret = ((a&b)<<1) + (a^b);
	printf("%d\n",ret);*/
	int ret = Func(a, b);
	printf("%d\n", ret);
	return 0;
}

#if 0
int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}
int main()
{
	int j = 4;
	int m = 1;
	int k;
	k = fun(j, m);
	printf("%d,", k);
	k = fun(j, m);
	printf("%d\n", k);
	return 0;
}



#pragma pack(4)/*编译选项，表示4字节对齐 平台：VS2013。语言：C语言*/
// xxxx   c  xxxxx
int main(int argc, char* argv[])
{
	int i = 0;
	for (i = 0; i < argc; i++)
	{
		printf("%s ", argv[i]);
	}
	//struct tagTest1
	//{
	//short a;
	//char d;
	//long b;
	//long c;
	//};
	//struct tagTest2
	//{
	//long b;
	//short c;
	//char d;
	//long a;
	//};
	//struct tagTest3
	//{
	//short c;
	//long b;
	//char d;
	//long a;
	//};
	//struct tagTest1 stT1;
	//struct tagTest2 stT2;
	//struct tagTest3 stT3;
	//printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
	return 0;
}


/*
1 :  A-->C      2^1-1
2:   A->B  A->C  B->C   3     2^2-1
3:  A->C	A->B C->B  A->C  B->A   B->C  A->C   7  2^3-1
4: 15
64:   2^64-1
*/
void Move(char pos1, char pos2)
{
	printf("%c->%c ", pos1, pos2);
}
/*
n:代表盘子个数
pos1：  开始位置
pos2:    中间位置
pos3:    结束为止
*/
void Hanota(int n, char pos1, char pos2, char pos3)
{
	//终止条件
	if (n == 1)
	{
		Move(pos1, pos3);
	}
	//递归调用
	else
	{
		Hanota(n - 1, pos1, pos3, pos2);
		Move(pos1, pos3);
		Hanota(n - 1, pos2, pos1, pos3);
	}
}
int main()
{
	Hanota(1, 'A', 'B', 'C');
	printf("\n");
	Hanota(2, 'A', 'B', 'C');
	printf("\n");
	Hanota(3, 'A', 'B', 'C');
	printf("\n");
	return 0;
}


int JumpFloor1(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	return JumpFloor(n - 1) + JumpFloor(n - 2);
}

int JumpFloor(int n)
{
	int f1 = 1;
	int f2 = 2;
	int f3 = 0;
	int i = 3;
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	for (i = 3; i <= n; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;


}
int main()
{
	printf("%d\n", JumpFloor(1));//1
	printf("%d\n", JumpFloor(2));//2
	printf("%d\n", JumpFloor(3));//3
	printf("%d\n", JumpFloor(4));//5
	return 0;
}


int Fabionacio(int n)
{
	int f1 = 1;
	int f2 = 1;
	int f3 = 1;
	int i = 3;
	for (i = 3; i <= n; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}

int main()
{
	printf("%d\n", Fabionacio(1));//1
	printf("%d\n", Fabionacio(2));//1
	printf("%d\n", Fabionacio(3));//2
	printf("%d\n", Fabionacio(40));//xxxxxxxxx



}


int main()
{
	double **a[3][4];
	printf("%d\n", sizeof(a));
}


//见名思意   
/*
参数：
返回值
函数名：
*/
void ReplaceBlank(char *str, int len)
{
	//"abc d ef"
	int NumBlank = 0;
	int i = 0;
	int mlen = 0;
	int newLen = 0;
	int indexofMyLen = 0;
	int indexofNewLen = 0;
	assert(str != NULL);
	while (str[i] != '\0')
	{
		++mlen;//strlen();
		if (str[i] == ' ')
		{
			++NumBlank;//空格的个数
		}
		i++;
	}
	//新的数组的长度
	newLen = mlen + NumBlank * 2 + 1;
	if (newLen > len)
	{
		return;
	}
	indexofMyLen = mlen;
	indexofNewLen = newLen;

	while (indexofMyLen >= 0
		&& indexofNewLen > indexofMyLen)
	{
		if (str[indexofMyLen] == ' ')
		{
			str[indexofNewLen--] = '0';
			str[indexofNewLen--] = '2';
			str[indexofNewLen--] = '%';
		}
		else
		{
			str[indexofNewLen] = str[indexofMyLen];

			indexofNewLen--;
		}
		indexofMyLen--;
	}
}

int main()
{
	char str[12] = "abc de f";
	int len = sizeof(str) / sizeof(str[0]);
	ReplaceBlank(str, len);
	printf("%s\n", str);
	return 0;
}
#endif