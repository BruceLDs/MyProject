#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//1.给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
//
//在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
//
//注意 :
//假设字符串的长度不会超过 1010。
//
//示例 1 :
//
//输入 :
//   "abccccdd"
//
//输出 :
//   7
//int Contrast(const char * arr, const char * s, int n)
//{
//	int len = strlen(arr);
//	for (int i = 0; i < len; ++i)
//	{
//		if (*(arr + i) == *(s + n))
//		{
//			return 1;
//		}
//	}
//	return -1;
//}
//
//int longestPalindrome(char * s)
//{
//	int len = strlen(s);
//	int sum = 0;
//	if (len == 1)
//		return 1;
//	char arr[1024] = { 0 };
//	char *p = s;
//	int f = 0;
//	for (int i = 0; i < len; ++i)
//	{
//		int count = 0;
//		int ret = Contrast(arr, p, i);
//		if (ret == 1)
//			continue;
//		for (int j = 0; j < len; ++j)
//		{
//			if (*(s + i) == *(s + j))
//			{
//				++count;
//				arr[f] = *(s + i);
//				++f;
//			}
//		}
//		if (count != 1)
//		{
//			if (count % 2 != 0)
//			{
//				count = count - 1;
//			}
//			sum += count;
//		}
//	}
//	if (sum < len)
//		return sum + 1;
//	else
//		return sum;
//}
//
//int main()
//{
//	char s[] = "bbcccbccdd";
//	printf("%d\n", longestPalindrome(s));
//	return 0;
//}

//  2.10进制转换成16进制
//例如：26  -> 1a
//      -1  -> ffffffff
//int positive(char *str, unsigned int num)
//{
//	int i = 0;
//
//	while (num > 0)
//	{
//		if (num % 16 > 9) str[i++] = (num % 16) + 87;
//		else              str[i++] = (num % 16) + '0';
//		num /= 16;
//	}
//	str[i] = '\0';
//	int j = i - 1;
//	i = 0;
//	while (i < j)
//	{
//		str[i] ^= str[j];
//		str[j] ^= str[i];
//		str[i++] ^= str[j--];
//	}
//
//	return 0;
//}
//char * toHex(int num)
//{
//	char *ret_str = (char*)malloc(33);
//	if (num == 0) 
//	{
//		ret_str[0] = '0';
//		ret_str[1] = '\0';
//	}
//	else if (num > 0) positive(ret_str, num);//正数
//	else               positive(ret_str, (unsigned int)num);//负数
//	return ret_str;
//}
//
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	char *arr = { 0 };
//	arr = toHex(input);
//	printf("%s\n", arr);
//	return 0;
//}

//3.给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
//
//示例 1 :
//
//输入 : "III"
//输出 : 3
// 示例 2 :
//
//  输入 : "IV"
//   输出 : 4
//int romanToInt(char * s)
//{
//	int len = strlen(s);
//	if (len == 0)
//    return 0;
//    int ret = 0;
//	for (int i = 0; i < len; ++i)
//	{
//		switch (s[i])
//		{
//
//		case 'M':
//			ret += 1000;
//			break;
//		case 'D':
//			ret += 500;
//			break;
//		case 'C':
//			ret += 100;
//			if (i < (len - 1))
//			if (s[i + 1] == 'M' || s[i + 1] == 'D')
//				ret -= 200;
//			break;
//		case 'L':
//			ret += 50;
//			break;
//		case 'X':
//			ret += 10;
//			if (i < (len - 1))
//			if (s[i + 1] == 'L' || s[i + 1] == 'C')
//				ret -= 20;
//			break;
//		case 'V':
//			ret += 5;
//			break;
//		case 'I':
//			ret += 1;
//			if (i < (len - 1))
//			if (s[i + 1] == 'X' || s[i + 1] == 'V')
//				ret -= 2;
//			break;
//		default:
//			break;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	char s[20] = { 0 };
//	scanf("%s", s);
//	printf("%d\n", romanToInt(s));
//	return 0;
//}
//union Un
//{
//	int i; 
//	char c;
//}un;
//int ret()
//{
//	un.i = 1;
//	return un.c;
//}
//int main()
//{
//	int tmp = ret();
//	if ( tmp == 1)
//		printf("是小端\n");
//	else
//		printf("是大端\n");
//	return 0;
//}
//union Un1
//{
//	char c[5];
//	int i;
//};
//union Un2
//{
//	short c[7];
//	int i;
//};
//int main()
//{
//	printf("%d\n", sizeof(union Un1)); 
//	printf("%d\n", sizeof(union Un2));
//	return 0;
//}
