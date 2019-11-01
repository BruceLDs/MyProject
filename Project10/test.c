#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
1、字符串是否是回文
2、数字
3、单链表是否是回文

*/
int IsPalind(int num)
{
	int newNum = 0;
	int num2 = num;
	while (num != 0)
	{
		newNum = newNum * 10 + num % 10;
		num /= 10;
	}
	if (newNum == num2)
	{
		return 1;
	}
	return 0;
}

int MyPow(int x, int y)
{
	int result = 0;
	int tmp = 0;
	if (y == 1) return x;
	tmp = MyPow(x, y / 2);
	if (y & 1 == 0)
	{
		result = tmp * tmp;
	}
	else
	{
		result = x * tmp * tmp;
	}
	return result;
}

void SumK(int *arr, int len, int *num1, int *num2, int key)
{
	int i = 0;
	int j = len - 1;

	while (i < j)
	{
		if (arr[i] + arr[j] > key)
		{
			j--;
		}
		else if (arr[i] + arr[j] < key)
		{
			i++;
		}
		else
		{
			*num1 = i;
			*num2 = j;
			break;
		}
	}
}

int main()
{
	int arr[] = { 1, 3, 5, 8, 9, 10, 13, 17 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = -1;
	int j = -1;
	SumK(arr, len, &i, &j, 17);
	printf("%d,%d\n", i, j);
	return 0;
}
