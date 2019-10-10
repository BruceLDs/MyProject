#define  _CRT_SECURE_NO_WARNINGS
#if 0
#include<stdio.h>
#include<stdlib.h>
int Max_num(int a, int b){
	return(a - b) >> 31 ? -1 : (a - b) ? 1 : 0;
	//判断两数大小 a>b 返回1   a<b  返回-1   a=b  返回0
}
int main(){
	int a = 10;
	int b = 15;
	int num = Max_num(a, b);
	printf("num = %d\n", num);
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 };
	int *q[4];
	int k;
	for (k = 0; k < 4; k++){
		q[k] = &a[k * 3];
	}
	printf("%d\n", q[3][1]);
	system("pause");
	return 0;
}
#endif

#if 1

#include<stdio.h>
#include<stdlib.h>
int main(){
	int i, j, a = 0;
	for (i = 0; i < 2; i++){
		for (j = 0; j < 4; j++){
			if (j % 2)
				break;
			a++;
		}
		a++;
	}
	printf("%d\n", a);
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int x;
	//printf("%0x\t%0x\n", 0x13 & 0x17, 0x13 | 0x17);
	typedef struct{
		int a;
		char b;
		short c;
		short d;
	}arr;
	printf("%d\n", sizeof(arr));
	x = 5 > 1 + 2 && 2 || 2 * 4 < 4 - !0;
	printf("%d\n", x);
	system("pause");
	return 0;
}
#endif


#if 0
#include<stdio.h>
#include<stdlib.h>
void Fnid_val(int *arr, int row, int col, int key, int *px, int *py)
{
	int tmpRow = 0;
	int tmpCol = col - 1;
	while (tmpRow < row && tmpCol >= 0)
	{
		if (key>arr[tmpRow*col + tmpCol])
		{
			tmpRow++;
		}
		else if (key == arr[tmpRow*col + tmpCol])
		{
			*px = tmpRow;
			*py = tmpCol;
			break;
		}
		else if (key<arr[tmpRow*col + tmpCol])
		{
			tmpCol--;
		}
	}
}

int main()
{
	int arr[4][4] = { 1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15 };
	int x = -1;
	int y = -1;
	Fnid_val((int*)arr, 4, 4, 6, &x, &y);
	printf("\t%d,%d\n", x, y);
	system("pause");
	return 0;
}
#endif    


#if 0
#include<stdio.h>
#include<stdlib.h>
#define ROW 10
void Func(int arr[][ROW])//魔方阵
{
	int tmpRow = 0;
	int tmpCol = ROW / 2;
	int i = 2;
	arr[tmpRow][tmpCol] = 1;
	for (i = 2; i <= ROW*ROW; i++)
	{
		if (arr[(tmpRow - 1 + ROW) % ROW][(tmpCol + 1) % ROW] == 0){
			tmpRow = (tmpRow - 1 + ROW) % ROW;
			tmpCol = (tmpCol + 1) % ROW;
			arr[tmpRow][tmpCol] = i;
		}
		else if (arr[(tmpRow - 1 + ROW) % ROW][(tmpCol + 1) % ROW] != 0){
			tmpRow = (tmpRow + 1) % ROW;
			arr[tmpRow][tmpCol] = i;
		}
	}
}
void print(int arr[][ROW]){
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++){
		for (j = 0; j < ROW; j++){
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[ROW][ROW] = { 0 };
	Func(arr);
	print(arr);
	system("pause");
	return 0;
}

#endif 