#define  _CRT_SECURE_NO_WARNINGS
#if 0
//调整数组使奇数全部都位于偶数前面。 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void fun(int*p, int sz)
{
	int i = 0;
	int j = 0;
	int *p0 = p + 1;
	assert(p != NULL);
	while (j < sz - 2)
	{
		if (*(p + i) % 2 == 1)
		{
			i++;
			j++;
			p0++;
		}
		else if ((*(p + i) % 2 == 0) && (*p0 % 2 != 0))
		{
			int temp = *(p + i);
			*(p + i) = *p0;
			*p0 = temp;
			i++;
			j++;
			p0++;
		}
		else
		{
			p0++;
			j++;
		}
	}

}
void fun1(int *arr, int len){
	int left = 0;
	int right = len - 1;
	while (left < right){
		if (arr[right] % 2 != 0 && arr[left] % 2 == 0){
			int tmp = arr[right];
			arr[right] = arr[left];
			arr[left] = tmp;
			left++;
			right--;
		}
		if (arr[left] % 2 != 0){
			left++;
		}
		if (arr[right] % 2 == 0){
			right--;
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	fun1(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int fun(int(*arr)[3], int row, int col, int k)
{
	assert(arr != NULL);
	int i = row - 1;
	int j = 0;
	while (i < 0 || j < row)
	{
		if (arr[i][j] == k)
		{
			return 1;
		}
		else if (arr[i][j]>k)
		{
			i--;
		}
		else
		{
			j++;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = { { 1, 2, 3 },
	{ 2, 3, 4 },
	{ 3, 4, 5 }, };
	int row = sizeof(arr) / sizeof(arr[0]);
	int col = sizeof(arr) / (sizeof(arr[0][0])*row);
	int k = 0;
	scanf("%d", &k);
	int i = fun(arr, row, col, k);
	if (i == 1)
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}
	system("pause");
	return 0;
}

#endif
