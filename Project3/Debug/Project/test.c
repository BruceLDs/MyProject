#define  _CRT_SECURE_NO_WARNINGS
//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。
//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以喝多少汽水。
//3.模拟实现strcpy
//4.模拟实现strcat
#if 0
#include<stdio.h>
#include<stdlib.h>
void is_once(int *a, int  len){
	int i, j, k;
	for (i = 0; i < len; i++) {
		k = 0;
		for (j = 0; j < len; j++) {
			if (a[j] == a[i]) {
				k++;
			}
		}
		if (k == 1){
			printf("%d\t", a[i]);
		}
	}
	printf("\n");
}
int main(){
	int arr[] = { 1, 2, 3, 1, 2, 3, 5, 7, 8, 7 };
	int i = 0;
	int len = sizeof(arr)/sizeof(arr[0]);
    is_once(arr, len);
	system("pause");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int count = 0;
	int i = 1;
	int k = 0;
	while (i <= 20){
		count++;
		k++;
			if (i % 2 == 0){
				count++;
				k++;
			}
			if (k % 2 == 0){
				count++;
				k++;
			}
		i++;
	}
		printf("%d\n", count);
system("pause");
return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
char *Mystrcpy(char *dest,const char *src){
	char *p = dest;
	while(*dest++ = *src++);
	return p;
}
int main(){
	char dest[] = { 0 };
	char src[] = "hello bite!";
	Mystrcpy(dest, src);
	printf("%s\n", dest);
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
char *Mystrcat(char *dest, const char *src){
	char *p = dest;
	while (*dest != '\0'){
		dest++;
	}
	while (*dest++ = *src++);
	return p;
}
int main(){
	char dest[] = "welcome!";
	char src[] = "hello bite!";
	char *p=Mystrcat(dest, src);
	printf("%s\n", p);
	system("pause");
	return 0;
}
#endif