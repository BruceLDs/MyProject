#define  _CRT_SECURE_NO_WARNINGS
//1.һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ�������ֻ����һ�ε����֣����ʵ�֡�
//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Ժȶ�����ˮ��
//3.ģ��ʵ��strcpy
//4.ģ��ʵ��strcat
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