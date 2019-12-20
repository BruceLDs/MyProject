#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>


#if 0
//利用回调函数实现冒泡过程(qsort)
int int_cmp(const void *p1, const void *p2)
{
	return (*(int *)p1 - *(int *)p2);
}

void _swap(void *p1, void *p2, int size)
{
	int i = 0;
	for (i = 0; i < size; ++i)
	{
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) =  *((char *)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}

void bubble(void *base, int count, int size, int(*cmp)(void *, void *))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; ++i)
	{
		for (j = 0; j < count - i - 1; ++j)
		{
			if (cmp((char *)base + j*size, (char *)base + (j + 1)*size) > 0)
			{
				_swap((char *)base + j*size, (char *)base + (j + 1)*size, size);
			}
		}
	}
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	/*char *arr[] = { "aaaa", "bbbb", "cccc", "dddd" };*/
	int i = 0;
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

#endif
#if 0
int  my_strstr(const char* str1, const char* str2)
{
	const char* str_1 = str1;
	const char* str_2 = str2;
	if (*str_1 == '\0' && *str_2 == '\0')
	{
		return 1;
	}
		while (*str1)
		{
			while (*str_2 == *str_1 && *str_2 != '\0')
			{
				++str_2, ++str_1;
			}
			if (*str_2 == '\0')
			{
				return 1;
			}
			else
			{
				str_2 = str2;
				++str1;
				str_1 = str1;
			}
		}
	return -1;
}

int main()
{
	char a[] = "fffbfg";
	char b[] = "effjfggbffjdgbjjhhdegh";
	int ret = my_strstr(a, b);
	printf("%d\n", ret);
	return 0;
}
#endif
//int my_strlen(const char * str)
//{
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = """";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}
//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
//例如：s = "leetcode"
//     返回 0.
//     s = "loveleetcode",
//     返回 2.
int firstUniqChar(char * s)
{
	int len = strlen(s);
	if (len ==  1)
	{
		return 0;
	}                                 
		for (int i = 0; i < len ; ++i)   
		{
			int count = 0;
			for (int j = 0; j < len; ++j)
			{

				if (*(s + i) == *(s + j) && i != j)
				{
					++count;
					break;
				}
			}
			if (count == 0)
			{
				return i;
			}
		}
	return -1;
}
int main()
{
	char s[] = "bbcc";
	int ret = firstUniqChar(s);
	printf("%d\n", ret);
	return 0;
}




