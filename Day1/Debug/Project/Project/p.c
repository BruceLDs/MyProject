#define  _CRT_SECURE_NO_WARNINGS
#if 0
#include<stdio.h>
#include<stdlib.h>
int count_one_bits(unsigned int value)
{
	int num = 0;
	while (value)//value为0时跳出循环
	{
		if (value % 2)//如果余数为1，则num自加1
			num++;
		value = value / 2;//将得到的商再付给value
	}
	return num;
	// 返回 1的位数 
}
int main(){
	int tmp = 0;
	scanf("%d", &tmp);
	int count = count_one_bits(tmp);
	printf("%d", count);
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main(){
	char *p = "GaoBo@168.com";    
	const char* sep = ".@";    
	char arr[30];   
	char *str = NULL; 
	strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容    
	for(str=strtok(arr, sep); str != NULL; str=strtok(NULL, sep))   
	{        
		printf("%s\n", str);   
	} 
	system("pause");
	return 0;
}
#endif


#if 0
#include<stdio.h>
#include<stdlib.h>
void show(int *arr,int len){
	int i = 0;
	for(i = 0; i < len; i++){
		printf("%d\t", arr[i]);
	}
	putchar('\n');
}
void fun(int *left,int *right){
	while (left <= right){
		if (*left % 2 == 1){

			left++;
		}
		if ( *right % 2 == 0){

			right--;
		}
		else{
			int tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
}
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	fun(arr, arr + len - 1);
	show(arr,len);
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
void find(int arr[3][3], int *px, int *py, int key){
	int x = 0;
	int y = *py - 1;
	while (x < *px&&y >= 0){
		if (arr[x][y] == key){
			*px = x;
			*py = y;
			return;
		}
		if (arr[x][y] > key){
			y--;
		}
		if (arr[x][y] < key){
			x++;
		}
	}
	*px = -1;
	*py = -1;
}
int main(){
	int arr[3][3] = { 1, 2, 3, 
							2, 3, 4,
							3, 4, 5 };
	int key = 5;
	int x = 3;
	int y = 3;
	find(arr,&x,&y,key);
	printf("%d %d\n", x,y);
system("pause");
return 0;
}
#endif