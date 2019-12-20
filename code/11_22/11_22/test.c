#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//给定两个字符串 s 和 t，它们只包含小写字母。
//字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
//请找出在 t 中被添加的字母。
//输入：
//s = "abcd"
//t = "abcde"
//输出：
//e
//char findTheDifference(char * s, char * t)
//{
//	int len1 = strlen(s);
//	int len2 = strlen(t);
//	int ret = 0;
//	int tmp = 0;
//	for (int i = 0; i < len1; ++i)
//	{
//		ret ^= *(s + i);
//	}
//	for (int i = 0; i < len2; ++i)
//	{
//		tmp ^= *(t + i);
//	}
//	char diff = tmp ^ ret;
//
//	return diff;
//}
//
//int main()
//{
//	char s[] = "a";
//	char t[] = "aa";
//	printf("%c\n", findTheDifference(s, t));
//	return 0;
//}

//给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
//
//你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500, 000），而 s 是个短字符串（长度 <= 100）。
//
//字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
//
//示例 1 :
//s = "abc", t = "ahbgdc"
//
//返回 true.
//
//示例 2 :
//	 s = "axc", t = "ahbgdc"
//
//	 返回 false.
// bool isSubsequence(char * s, char * t)
//{
//	int s_len = strlen(s);
//	int t_len = strlen(t);
//	if (s_len == 0)
//		return true;
//	int i = 0;
//	int j = 0;
//	for (int j = 0; j < t_len; ++j)
//	{
//		if (*(s + i) == *(t + j))
//			++i;
//		if (i == s_len)
//			return true;
//	}
//	return false;
//}

