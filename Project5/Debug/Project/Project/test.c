#define  _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h> 
#include<stdlib.h>
//#include<string.h>
char *Mystrncpy(char *str1, const char *str2, unsigned int k)
{
	char *p = str1;
	while (k--){
		*str1++ = *str2++;
	}
	return p;
}
int main() {
	char str1[] = "hello bite";
	char str2[30] = { 0 };
	char *p=Mystrncpy(str2,str1,3);
	printf("%s\n", p);
	system("pause");
	return 0;
}
#endif


#if 0
#include <stdio.h> 
#include<stdlib.h>
//#include<string.h>
char *Mystrncat(char *str1, const char *str2, unsigned int k)
{
	char *p = str1;
	while (*str1 != '\0'){
		str1++;
	}
	while (k--){
		*str1++ = *str2++;
	}
	str1 = '\0';
	return p;
}
int main() {
	char str1[] = "hello bite";
	char str2[15] = "Gaobo";
	char *p =Mystrncat(str2, str1, 3);
	printf("%s\n", p);
	system("pause");
	return 0;
}
#endif


#if 0
#include <stdio.h> 
#include<stdlib.h>
#include<string.h>
int Mystrncmp(const char *str1, const char *str2, unsigned int k)
{
	while (k != 0&& *str1 != '\0'&&*str2 != '\0'){
			if (*str1 == *str2){
				str1++;
				str2++;
				k--;
			}
			else if (*str1 > *str2){
				return 1;
			}
			else{
				return -1;
			}
		}
	return 0;
}
int main() {
	char str1[] = "hello bite";
	char str2[] = "hello GaoBo";
	int p =Mystrncmp(str1, str2, 8);
	printf("%d\n",p);  
	system("pause");
	return 0;
}
#endif