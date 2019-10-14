#define  _CRT_SECURE_NO_WARNINGS
#if 0
#include<stdio.h>
#include<stdlib.h>
char *Mystrstr(char *str, const char *substr){
	char *p = str;
	char *q = substr;
	char *start = p;;
	while (*p != '\0'){
		p = start;
		while (*q != '\0'){
			if (*p == *q){
				p++;
				q++;
			}
			else{
				break;
			}
		}
		if (*q == '\0'){
			return start;
		}
		q = substr;
		start++;
	}
	return NULL;
}
int main(){
	char str[] ="hello bite";
	char substr[] = "llo";
	char *p=Mystrstr(str, substr);
	printf("%s\n", p);
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
char *Mystrchr(const char * str,int n)
{
	char *p = str;
	while (*p && *p != (char)n)
		p++;
	if (*p == (char)n)
		return((char *)p);
	return(NULL);
}
int main(){
	char str[] = "hbfjad";
	char *p=Mystrchr(str,98);
	printf("%s\n", p);
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int Mystrcmp(const char *str1, char *str2){
	while (*str1 != '\0'&&*str2 != '\0'){
		if (*str1 == *str2){
			str1++;
			str2++;
		}
		if (*str1 > *str2)
			return 1;
		if (*str1 < *str2)
			return -1;
	}
	return 0;
}
int main(){
	char str1[] = "hbfjhh";
	char str2[] = "hbfj";
	int k = Mystrcmp(str1,str2);
	printf("%d\n", k);
	system("pause");
	return 0;
}
#endif

#if 0
//6.
#include<stdio.h>
#include<stdlib.h>
void *Mymemcpy(void *dest,const void *src,int k){
	void *p = dest;
	while (k--){
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src) ++;
	}
	return p;
}
int main(){
	char dest[] = "wskjskdjkjsl";
	char src[] = "wskaaaaas";
	Mymemcpy(dest, src, 5);
	printf("%s\n", dest);
	system("pause");
	return 0;
}

#endif

#if 1
#include<stdio.h>
#include<stdlib.h>
void *Mymemmove(void *dest, const void *src,  int k){
	void *p = dest;
	if (dest > src){
		while (k--){
			*((char*)dest + k) = *((char*)src + k);
		}
	}
	else{
		while (k--){
			*(char*)dest = *(char*)src;
			((char*)dest)++;
			((char*)src)++;
		}
	}
	return p;
}
void print(int *arr, int sz){
	int i = 0;
	for (i = 0; i < sz; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
int main(){
	int  dest[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(dest) / sizeof(dest[0]);
	memmove((void*)(dest+2),(void*) dest, 16);
	print(dest,sz);
	system("pause");
	return 0;
}

#endif
