#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//char *DeleteRepeateChar(char *str1, char *str2){
//	int arr[256] = { 0 };
//	char *p = str1;
//	char *q = str1;
//	while (*str2 != '\0'){
//		arr[*str2] =1;
//		str2++;
//	}
//	while (*q != '\0'){
//		if (arr[*p] != 1){//没出现过
//			*q++ = *p;
//		}
//		p++;
//	}
//	*q = '\0';
//	return str1;
//}
//int main(){
//	//108 30 6 - 4 / 5 8* + -
//	char str1[] = "Welcome to cvte";
//	char str2[] = "come";
//	char *p=DeleteRepeateChar(str1, str2);
//	printf("%s\n", p);
//	return 0;
//} 
//
////每个桩子上都有一个弹簧，袋鼠跳到弹簧上就可以跳的更远。
////每个弹簧力量不同，用一个数字代表它的力量，如果弹簧力量为5，
////就代表袋鼠下一跳最多能够跳5米，如果为0，就会陷进去无法继续跳跃。
////河流一共N米宽，袋鼠初始位置就在第一个弹簧上面，要跳到最后一个弹簧之后就算过河了，
////给定每个弹簧的力量，求袋鼠最少需要多少跳能够到达对岸。如果无法到达输出 - 1
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define MN 20
//void Init(int *arr){
//	int i = 0;
//	for (i = 0; i < MN; i++){
//		int k = rand() % 4;
//		arr[i] = k;
//		printf("%d\t", k);
//	}
//	printf("\n");
//}
//int jump(int *arr){
//	int i = 0;
//	int count = 0;
//	while(i < MN){
//		if (arr[i] == 0){
//			return -1;
//		}
//		i += arr[i];
//		count++;
//	}
//	return count;
//}
//int main(){
//	srand((unsigned)time(NULL));
//	int arr[MN] = { 0 };//弹簧的力
//	printf("第1个弹簧到第%d个弹簧的弹力分别是：\n",MN);
//	Init(arr);
//	int m = jump(arr);
//	printf("\n");
//	printf("%d\n", m);
//	return 0;
//}
//
//#include<stdio.h>
//void q_sort(int *arr,int len){//冒泡排序
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < len; i++){
//		for (j = 1; j < len-i; j++){
//			if (arr[j-1]>arr[j]){
//				int tmp = arr[j-1];
//				arr[j-1] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//}
//void print(int *arr, int len){
//	int i = 0;
//	for (i = 0; i < len; i++){
//		printf("%d\t", arr[i]);
//	}
//	printf("\n");
//}
//int main(){
//	int arr[] = { 9, 4, 5, 6, 8, 2, 3 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	q_sort(arr,len);
//	print(arr,len);
//	return 0;
//}
//#endif
//
//
//#include<stdio.h>
////单链表是否回文
//
//int Mypow(int x, int y){
//	int result = 0;
//	int tmp = 0;
//	if (y == 0)
//		return 1;
//	tmp = Mypow(x, y / 2);
//	if ((y & 1) == 0){
//		result = tmp*tmp;
//	}
//	else{
//		result = x*tmp*tmp;
//	}
//	return result;
//}
//int main(){
//	printf("%d\n", Mypow(9, 9));
//
//
//
//	return 0;
//}
//
//
//#include<stdio.h>
//void Sump(int *arr,int k,int len,int *num1,int *num2){
//	int i = 0;
//	int j = len - 1;
//	while (i < j){
//		int tmp = arr[i] + arr[j];
//		if (tmp == k){
//			*num1 = i;
//			*num2 = j;
//			break;
//		}
//		else if (tmp > k)j--;
//		else if (tmp < k)i++;
//	}
//}
//int main(){
//	int arr[] = { 1, 3, 5, 7, 9, 13, 15, 19 };
//	int num1 = -1;
//	int num2 = -1;
//	int len = sizeof(arr) / sizeof(arr[0]);
//	Sump(arr, 18, len,&num1, &num2);
//	printf("%d,%d\n", num1, num2);
//return 0;
//}
//
//#include<stdio.h>
//
////给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数
////并返回他们的数组下标
////你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
////示例 :
////给定 nums = [2, 7, 11, 15], target = 9
////因为 nums[0] + nums[1] = 2 + 7 = 9
////所以返回[0, 1]
//int* twoSum(int* nums, int numsSize, int target, int* returnSize){
//	int i = 0;
//	int j = numsSize - 1;
//	while (i < j){
//		int tmp = nums[i] + nums[j];
//		if (tmp == target){
//			*returnSize= i;
//			*(returnSize+1) = j;
//			return returnSize;
//		}
//		else if (tmp > target)j--;
//		else if (tmp < target)i++;
//	}
//	*returnSize = -1;
//	*(returnSize + 1) = -1;
//	return returnSize;
//}
//int main(){
//	int arr[] = { 2, 7, 11, 15 };
//	int num[2] = { 0 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	twoSum(arr, len, 8,num);
//	printf("%d,%d\n",num[0],num[1] );
//	return 0;
//}




int lengthOfLongestSubstring(char * s){
	char *p = s;
	int arr[256] = { 0 };
	int count = 0;
	arr[*p] = 0;
	int k = 0;
	while (*p != '\0'){
		arr[*p]++;
		if (arr[*p] == 1){
			count++;
		}
		else{
			count = 1;
			arr[*p] = 0;
		}
		if (count > k){
			k = count;
		}
		p++;
	}
	return k;
}
int main(){
	char str[] = "efghjkl";
	int p = lengthOfLongestSubstring(str);
	printf("%d\n", p);
	return 0;
}

