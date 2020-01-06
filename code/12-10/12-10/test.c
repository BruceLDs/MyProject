//1.给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
//
//例如，给定数组 nums = [-1，2，1， - 4], 和 target = 1.
//
//与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
//int cmp(const void * a, const void * b)
//{
//	return *(int *)a - *(int *)b;
//}
//
//int abs(int x)
//{
//	if (x > 0) {
//		return x;
//	}
//	else {
//		return -x;
//	}
//}
//
//int threeSumClosest(int* nums, int numsSize, int target)
//{
//	qsort(nums, numsSize, sizeof(int), cmp);
//	int result = nums[0] + nums[1] + nums[2];
//	for (int i = 0; i < numsSize - 2; i++) {
//		int l = i + 1;
//		int r = numsSize - 1;
//		while (l < r) {
//			int sum = nums[i] + nums[l] + nums[r];
//			if (abs(sum - target) < abs(result - target)) {
//				result = sum;
//			}
//			if (sum < target) {
//				l++;
//			}
//			else if (sum > target) {
//				r--;
//			}
//			else {
//				return result;
//			}
//		}
//	}
//
//	return result;
////}
//2.给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
//
//注意：
//
//答案中不可以包含重复的四元组。
//
//示例：
//
//给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
//
//满足要求的四元组集合为：
//[
//	[-1, 0, 0, 1],
//	[-2, -1, 1, 2],
//	[-2, 0, 0, 2]
//]

//冒泡排序(从小到大)
//int *sort(int *nums, int numsSize)
//{
//	int i, j, temp;
//	for (i = 0; i < numsSize - 1; i++)
//	{
//		for (j = 0; j < numsSize - 1 - i; j++)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				temp = nums[j + 1];
//				nums[j + 1] = nums[j];
//				nums[j] = temp;
//			}
//		}
//	}
//	return nums;
//}
//
//int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
//
//	int **returnArray = (int **)malloc(sizeof(int *)* 250);
//	int ptr_ra = -1;    //返回数组元素指针
//	*returnColumnSizes = (int *)malloc(sizeof(int)* 250);
//	int i, j, k, t;
//	int newTarget1, newTarget2;
//
//	nums = sort(nums, numsSize);
//
//	for (i = 0; i < numsSize - 3; i++)
//	{
//		if (i == 0 || ((i > 0) && (nums[i] != nums[i - 1])))
//		{
//			newTarget1 = target - nums[i];
//			for (j = i + 1; j < numsSize - 2; j++)
//			{
//				if (j == i + 1 || ((j > i + 1) && (nums[j] != nums[j - 1])))
//				{
//					//两数之和双指针
//					k = j + 1;
//					newTarget2 = newTarget1 - nums[j];
//					t = numsSize - 1;
//					while (k < t)
//					{
//						if (nums[k] + nums[t] == newTarget2)
//						{
//							returnArray[++ptr_ra] = (int *)malloc(sizeof(int)* 4);
//							returnArray[ptr_ra][0] = nums[i];
//							returnArray[ptr_ra][1] = nums[j];
//							returnArray[ptr_ra][2] = nums[k];
//							returnArray[ptr_ra][3] = nums[t];
//							(*returnColumnSizes)[ptr_ra] = 4;
//							while (k < t && nums[k] == nums[k + 1]) k++;
//							while (k < t && nums[t] == nums[t - 1]) t--;
//							k++;
//							t--;
//						}
//						else if (nums[k] + nums[t] > newTarget2)
//						{
//							while (k < t && nums[t] == nums[t - 1]) t--;
//							t--;
//						}
//						else
//						{
//							while (k < t && nums[k] == nums[k + 1]) k++;
//							k++;
//						}
//					}
//
//				}
//			}
//		}
//	}
//
//	*returnSize = ptr_ra + 1;
//	return returnArray;
//}

