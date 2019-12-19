#define  _CRT_SECURE_NO_WARNINGS

#if 0
#include<stdio.h>
int Partion(int arr[], int left, int right){
	int tmp = arr[left];
	while (left < right)
	{
		//右边 找比tmp小的数据
		while (left < right && arr[right] >= tmp)
		{
			right--;
		}
		if (left >= right)
		{
			//arr[left] = tmp;
			break;
		}
		else
		{
			arr[left] = arr[right];
		}
		//左边的   比tmp大的数据
		while (left < right && arr[left] <= tmp)
		{
			left++;
		}
		if (left >= right)
		{
			//arr[left] = tmp;
			break;
		}
		else
		{
			arr[right] = arr[left];
		}
	}
	arr[left] = tmp;
	return left;
}
void PreKNum(int *arr, int len, int k)
{
	int left = 0;
	int right = len - 1;
	int par = Partion(arr, left, right);//5
	int i = 0;
	while (par != k - 1)
	{
		if (par > k - 1)//5 > 2
		{
			right = par - 1;
			par = Partion(arr, left, right);
		}
		else // 5    7
		{
			left = par + 1;
			par = Partion(arr, left, right);
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 12, 3, 5, 17, 0, 7, 14, 8, 4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	PreKNum(arr, len, 3);
}
//逻辑很缜密 解题的思路简单
#endif
#if 0
#include<stdio.h>
#include<limits.h>
int MaxArray(int *arr, int len){//时间复杂度O(n^2)
	if (arr == NULL || len < 0){
		return -1;
	}
	int i = 0;
	int j = 0;
	int maxNum = INT_MIN;
	while (i < len){
		int count = 0;
		j = i;
		while (j < len){
			count += arr[j];
			if (count>maxNum){
				maxNum = count;
			}
			j++;
		}
		i++;
	}
	return maxNum;
}
int MaxArray1(int *arr, int len){//时间复杂度O(n)
	int sum = arr[0];
	int max = arr[0];
	int i = 1;
	for (i = 1; i < len; i++)
	{
		if (sum < 0)
		{
			sum = arr[i];
		}
		else
		{
			sum += arr[i];//4 8 9 5 -1 10 -2
		}
		if (sum>max)
		{
			max = sum;
		}
	}
	return max;
}
int main(){
	int arr[] = { 1, -2, 3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int k = MaxArray(arr, len);
	printf("%d\n", k);
	int m = MaxArray1(arr, len);
	printf("%d\n", m);
	return 0;
}
#endif


#if 0
#include<stdio.h>
char FindOnceChar(char *str){
	int arr[256] = { 0 };
	//遍历字符串，统计每个字符出现的次数
	char *p = str;
	while (*p != '\0'){
		arr[*p]++;
		p++;
	}
	//查找第一个出现一次的字符
	p = str;
	while (*p != '\0'){
		if (arr[*p] == 1){
			return *p;
		}
		p++;
	}
	return '\0';
}
int main(){
	char str[] = "ggabacbdc";
	char p = FindOnceChar(str);
	printf("%c\n", p);
	return 0;
}
#endif

#if 1
#include<stdio.h>
#include<limits.h>
int main(){
	unsigned char a = 0xA5;
	unsigned char b = ~a >> 5;
	printf("%d\n", b);
	printf("%d\n", 0xFA);
	return 0;
}



#endif