#include<stdio.h>

//1.给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//示例 1:
//
//输入 : [1, 2, 3, 4, 5, 6, 7] 和 k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
// 解释 :
//	向右旋转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右旋转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右旋转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//示例 2 :
//
// 输入 : [-1, -100, 3, 99] 和 k = 2
//  输出 : [3, 99, -1, -100]
//   解释 :
//	  向右旋转 1 步 : [99, -1, -100, 3]
//	  向右旋转 2 步 : [3, 99, -1, -100]
//void reverse(int* nums, int start, int end)
//{
//	while (start < end) {
//		int temp = nums[start];
//		nums[start] = nums[end];
//		nums[end] = temp;
//		start++;
//		end--;
//	}
//}
//void rotate(int* nums, int numsSize, int k)
//{
//	k %= numsSize;
//	reverse(nums, 0, numsSize - 1);
//	reverse(nums, 0, k - 1);
//	reverse(nums, k, numsSize - 1);
//}
/*2.对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1, 2, 3, 1]。

给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。



示例 1：

输入：A = [1, 2, 0, 0], K = 34
输出：[1, 2, 3, 4]
解释：1200 + 34 = 1234
解释 2：

输入：A = [2, 7, 4], K = 181
输出：[4, 5, 5]
解释：274 + 181 = 455
示例 3：

输入：A = [2, 1, 5], K = 806
输出：[1, 0, 2, 1]
解释：215 + 806 = 1021
示例 4：

输入：A = [9, 9, 9, 9, 9, 9, 9, 9, 9, 9], K = 1
输出：[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
解释*//*：9999999999 + 1 = 10000000000*/
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
//	if (K == 0){
//		*returnSize = ASize;
//		return A;
//	}
//	int* t = calloc(ASize + 5, sizeof(int));
//	int i = ASize - 1, j = ASize + 4, c = 0;
//	while (i >= 0 || K > 0 || c > 0){
//		int m = c;
//		if (i >= 0)
//			m = m + A[i];
//		if (K > 0)
//			m = m + (K % 10);
//		if (m >= 10){
//			t[j] = m - 10;
//			j--;
//			c = 1;
//		}
//		else{
//			t[j] = m;
//			j--;
//			c = 0;
//		}
//		i--;
//		K = K / 10;
//	}
//	*returnSize = ASize - j + 4;
//	j++;
//	int* a = calloc(*returnSize, sizeof(int));
//	for (i = 0; j < ASize + 5; i++, j++)
//		a[i] = t[j];
//	return a;
//}
//3.给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//
//说明 :
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//示例 :
//
//输入 :
//	nums1 = [1, 2, 3, 0, 0, 0], m = 3
//	nums2 = [2, 5, 6], n = 3
//
//输出 : [1, 2, 2, 3, 5, 6]

//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//	int end1 = nums1Size - 1, end2 = nums2Size - 1;
//	for (int i = end1; i >= nums1Size - nums2Size; --i)
//	{
//		nums1[i] = nums2[end2];
//		--end2;
//	}
//
//	for (int i = 0; i < nums1Size - 1; ++i)
//	{
//		for (int j = 0; j < nums1Size - 1 - i; ++j)
//		{
//			if (nums1[j] >nums1[j + 1])
//			{
//				int tmp = nums1[j + 1];
//				nums1[j + 1] = nums1[j];
//				nums1[j] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	/*int nums1[6] = { 1, 2, 3, 0, 0, 0 };
//	int m = 3;
//	int nums2[3] = { 2, 5, 6 };
//	int n = 3;
//	merge(nums1, 6, 3, nums2, 3, 3);*/
//	int nums1[2] = { 2,0};
//	int m = 1;
//	int nums2[1] = {1};
//	int n = 1;
//	merge(nums1, 2, 1, nums2, 1, 1);
//	for (int i = 0; i < 2; ++i)
//	{
//		printf("%d ", nums1[i]);
//	}
//	return 0;
//}
//4.冒泡排序法。
//void sort(int *arr)
//{
//for (int i = 0; i < 16 - 1; ++i)
//{
//	for (int j = 0; j < 16 - i - 1; ++j)
//	{
//		if (arr[j] >arr[j + 1])
//		{
//			int tmp = arr[j + 1];
//			arr[j + 1] = arr[j];
//			arr[j] = tmp;
//		}
//	}
//}
//
//}
//void sort1(int *arrq)
//{
//	for (int i = 0; i < 16 - 1; ++i)
//	{
//		for (int j = 16 - 1; j >i; --j)
//		{
//			if (arrq[j] <arrq[j - 1])
//			{
//				int tmp = arrq[j];
//				arrq[j] = arrq[j - 1];
//				arrq[j - 1] = tmp;
//			}
//		}
//	}
//
//}
//
//int main()
//{
//	int arr[16] = { 33,45,646,76,1234,5465,445,67,6787,10,1,2,5,7,8,11};
//     sort(arr, 16);
//	 for (int i = 0; i < 16; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	sort1(arr, 16);
//	for (int i = 0; i < 16; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int start1 = 0, end1 = m - 1, start2 = 0, end2 = n - 1;
//	for (int i = end1; i >= m - n; --i)
//	{
//		nums1[i] = nums2[i];
//	}
//
//	for (int i = 0; i < m; ++i)
//	{
//		for (int k = 0; k)
//	}
//}