#define  _CRT_SECURE_NO_WARNINGS
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char *MyStrcat(char *dest, const char *src)
{
	char *p = dest;
	assert(dest != NULL && src != NULL);
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++);
	return p;
}
int main(){
	char dest[20] = "hollo";
	char src[] = "bite";
	MyStrcat(dest, src);
	printf("%s\n", dest);
	system("pause");
	return 0;
}
#endif


#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int Mystrcmp(const char *str1, const char *str2){
	assert(str1 != NULL && str2 != NULL);
	//1、如果相同str1和str2同时++   --》同时为\0  两个字符串相同
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	//2、不相同求出胜负
	if (*str1 > *str2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main(){
	char str1[] = "abcd";
	char str2[] = "abcdef";
	int len = 0;
	len=Mystrcmp(str1, str2);
	printf("%d\n", len);
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char *Mystrncpy(char *dest, const char *src, int n){
	int count = 0;
	char *p = dest;
	assert(dest != NULL && src != NULL);
	while (count < n)
	{
		*dest++ = *src++;
		count++;
	}
	return p;
}
int main(){
	char str1[] = "abcd";
	char str2[] = "hello";
	Mystrncpy(str1, str2, 2);
	printf("%s\n", str1);
	system("pause");
	return 0;
}


#endif


#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char *Mystrncat(char *dest, const char *src, int n){
	char *p = dest;
	int count = 0;
	assert(dest != NULL && src != NULL);
	while (*dest != '\0')
	{
		dest++;
	}
	while (count < n)
	{
		*dest++ = *src++;
		count++;
	}
	*dest = '\0';
	return p;
}
int main(){
	char str1[20] = "abcd";
	char str2[] = "hello";
	Mystrncat(str1, str2, 2);
	printf("%s\n", str1);
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int Mystrncmp(const char *str1, const char *str2,int n){

	int diff = 0;
	int count = 0;
	assert(str1 != NULL && str2 != NULL);
	//1、相同++ && count < n 
	while (count < n && ((diff = (*str1 - *str2)) == 0)
		&& *str1 != '\0')
	{
		str1++;
		str2++;
		count++;
	}
	//2、不相同  
	return diff;
}
int main(){
	char str1[] = "abcd";
	char str2[] = "acd";
	int len = 0;
	len = Mystrncmp(str1, str2,2);
	printf("%d\n", len);
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//自己实现函数strstr
char *Mystrstr(const char *str1, const char *str2){
	const char *s1 = str1;
	const char *s2 = str2;
	const char *start = s1;
	assert(str1 != NULL && str2 != NULL);
	while (*start != '\0')
	{
		s1 = start;
		s2 = str2;
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return start;
		}
		if (*s1 == '\0')
		{
			return NULL;
		}
		start++;
	}
	return NULL;
	}

int main(){
	char str1[] = "adefbbbc";
	char str2[] = "bbc";
	char *p = Mystrstr(str1, str2);
	printf("%s\n", p);
	system("pause");
	return 0;
}
#endif
