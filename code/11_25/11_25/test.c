#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//编写一个函数来查找字符串数组中的最长公共前缀。
//
//如果不存在公共前缀，返回空字符串 ""。
//
//示例 1 :
//
//输入 : ["flower", "flow", "flight"]
//输出 : "fl"
// 示例 2 :
//
//  输入 : ["dog", "racecar", "car"]
//   输出 : ""
//	解释 : 输入不存在公共前缀。

char * longestCommonPrefix(char **strs, int strsSize)
{
	int len1 = strlen(strs[0]);
	char *p = (char*)malloc(sizeof(char)* 100);
	int ret = 0;
	for (int i = 0; i < strsSize - 1; ++i)
	{
		int k = 0;
		int count = 0;
		for (int j = 0; j < len1; ++j)
		{                                                    
			if (strs[i][j] == strs[i + 1][j])
			{
				p[k] = strs[i][j];
				++k;

			}
			if (strs[i][j] != strs[i + 1][j])
				++count;
			if (count == j && count != 0)
			{
				return " ";
			}

		}
		ret = k;
	}
	*(p + ret) = '\0';
	return p;
}

//char * longestCommonPrefix(char ** strs, int strsSize){
//	if (strsSize == 0)
//		return "";
//	else if (strsSize == 1)
//		return strs[0];
//	int j = 0;
//	while (1)
//	{
//		for (int i = 1; i < strsSize; i++)
//		if (strs[0][j] != strs[i][j] || !strs[0][j] || !strs[i][j])
//		{
//			strs[0][j] = '\0';
//			return strs[0];
//		}
//		j++;
//	}
//	return NULL;
//}

int main()
{
	char *name[] = { "flower", "flo", "fl" };
	/*char *name[] = { "dog", "racecar", "car" };*/
	int len = strlen(name);
	printf("%s\n", longestCommonPrefix(name, len));
	return 0;
}