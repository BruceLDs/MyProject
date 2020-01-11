#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(){
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = strlen(arr) - 1;
	int input = 3;
	int mid = 0;
	/*printf("请输入你要查询的数字 :>");
	scanf("%d", &input);*/
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] > input)
		{
			right = mid - 1;
		}
		else if (arr[mid] < input){
			left = mid + 1;
		}
		else
			break;
		
	}
	if (left <= right)
		printf("找到了，下标是:%d", mid);

	else
		printf("找不到\n");
	
	return 0;
	}
    
