#define  _CRT_SECURE_NO_WARNINGS

#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void left_move(char *str,int len, int k)
{
	assert(str != NULL);
	int a = 0;
	int i = 0;
	int j = 0;
	a = len - 1;
	for (i = 0; i < k; i++)
	{
		char tmp = str[0];
		for (j = 0; j < a; j++)
		{
			str[j] = str[j + 1];
		}
		str[a] = tmp;
	}
}
int main(){
	int k = 0;
	char str[] ="ABCDEFGH";
	int len = sizeof(str) / sizeof(str[0]) - 1;
	printf("%s\n", str);
	printf("请输入你要左旋的位数>");
	scanf("%d", &k);
	left_move(str,len,k);
	printf("%s\n", str);
	system("pause");
	return 0;
}
#endif


#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
int left_move(char *str, const char *p, int k)
{
	int a = 0;
	int i = 0;
	int j = 0;
	assert(str != NULL);
	a = k - 1;
	char *tmp = str;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			str[j] = str[j + 1];
		}
		str[k] = *tmp;
		if ( strcmp(str,p == 0)){
			return 1;
		}
	}
	return 0;
}
int is_left_move(char *str, const char *p,int k){
	assert(str != NULL);
	int s=left_move(str,p,k);
	return s;
}
int main(){
	char str1[] = "AABCD";
	char str2[] = "ABCDA";
	int k = sizeof(str1) / sizeof(str1[0])-1;
	int s=is_left_move(str1,str2,k);
	if (s == 1){
		printf("str2可以由str1旋转得到；\n");
	}
	else{
		printf("str2不可以可以由旋转得到；\n");
	}
	printf("%s\n", str1);
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
int main(){
	char  str1[20] = "AABCD";
	char  str2[] = "BCDAA";
	char str=strncat(str1, str1, 5);
	strstr(str,str2);

	system("pausse");
	return 0;
}
#endif
//isdigit 判断是否是字符
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void *Mymemcpy(void *dest,void *src,int count){
	void *p = dest;
	while (count--){
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src)++;
	}
	*((char*)dest) = '\0';
	return p;
}
int main(){
	char src[] = "abcdef";
	char dest[10] = { 0 };
	void *p=Mymemcpy((void*)dest,(void*) src, 4);
	printf("%s\n", p);
system("pause");
return 0;
}
#endif//no