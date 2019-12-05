#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define INT_PTR int*
typedef int* int_ptr;
#define ROW 5
void Func2(int arr[][ROW])
{
	int tmpRow = 0;
	int tmpCol = ROW / 2;
	int i = 2;
	arr[tmpRow][tmpCol] = 1;
	//2-n^2
	for (i = 2; i <= ROW*ROW; i++)
	{
		//说明上一行 下一列是有数据的
		if (arr[(tmpRow - 1 + ROW) % ROW][(tmpCol + 1) % ROW] != 0)
		{
			//改变行坐标    列不发生改变
			tmpRow = (tmpRow + 1) % ROW;
		}
		else
		{
			tmpRow = (tmpRow - 1 + ROW) % ROW;
			tmpCol = (tmpCol + 1) % ROW;
		}
		//上面的if else 语句执行完后  确定了下一个数据的坐标
		arr[tmpRow][tmpCol] = i;
	}

}
void Show(int arr[][ROW])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < ROW; j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}
//void    int
//Function(int a)
//{
//	printf("%d\n",a);
//	return a;
//}

int main()
{
	char str[10];
	//str = "string";
	strcpy(str, "string");


	/*int ret = Function(10);
	printf("ret = %d\n",ret);
	int arr[ROW][ROW] = {0};
	Func2(arr);
	Show(arr);*/
	return 0;
}

#if 0
/*
[i][j] ---> i*col+j

*/
void Fnid_val(int *arr, int row, int col, int key, int *px, int *py)
{
	int tmpRow = 0;
	int tmpCol = col - 1;

	while (tmpRow < row && tmpCol >= 0)
	{
		if (arr[tmpRow*col + tmpCol] == key)
		{
			*px = tmpRow;
			*py = tmpCol;
			break;
		}
		else if (arr[tmpRow*col + tmpCol] > key)
		{
			tmpCol--;
		}
		else
		{
			tmpRow++;
		}
	}
}
//
int main()
{
	//0,3
	int arr[4][4] = { 1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15 };
	int x = -1;
	int y = -1;
	Fnid_val((int*)arr, 4, 4, 7, &x, &y);
	printf("%d,%d\n", x, y);
	return 0;
}


int main()
{

	/*int i1 = 10;
	int i2 = 20;

	const INT_PTR  a;*/
	/*a = &i1;
	a = &i2;

	*a = 10;*/

	//a = &i1;
	//b = &i1;

	//typedef int* int_ptr;
	//const int_ptr c = &i1;
	//c= &i2; error
	//*c = 99;

	return 0;
}
#endif