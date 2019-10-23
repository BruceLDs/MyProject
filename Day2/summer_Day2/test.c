#define  _CRT_SECURE_NO_WARNINGS

#if 0
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
void ReplaceBlank(char *str, int len){
	int NumBlank = 0;
	int i = 0;
	int mlen = 0;
	int newLen = 0;
	int indexofMyLen = 0;
	int indexofNewLen = 0;
	assert(str != NULL);
	while (str[i] != '\0')
	{
		++mlen;//strlen();
		if (str[i] == ' ')
		{
			++NumBlank;//空格的个数
		}
		i++;
	}
	//新的数组的长度
	newLen = mlen + NumBlank * 2 + 1;
	if (newLen > len)
	{
		return;
	}
	indexofMyLen = mlen;
	indexofNewLen = newLen;

	while (indexofMyLen >= 0
		&& indexofNewLen > indexofMyLen)
	{
		if (str[indexofMyLen] == ' ')
		{
			str[indexofNewLen--] = '0';
			str[indexofNewLen--] = '2';
			str[indexofNewLen--] = '%';
		}
		else
		{
			str[indexofNewLen] = str[indexofMyLen];
		}
		indexofMyLen--;
		indexofNewLen--;
	}
}
int main(){

	char str[18] = "abc defgx yz";
	int len = sizeof(str) / sizeof(str[0]);
	printf("%d\n", len);
	ReplaceBlank(str, len);
	printf("%s\n", str);
	system("pause");
	return 0;
}
#endif


#if 0
#include<stdio.h>
#include<stdlib.h>
int JumpFloor(int n){
	if (n == 1){
		return 1;
	}	
	   if (n == 2){
		return 2;
	}
	else{
		return JumpFloor(n - 1) + JumpFloor(n - 2);
	}
}
int main(){
int a=JumpFloor(12);
printf("%d\n", a);
system("pause");
return 0;
}
#endif



#if 0
#include<stdio.h>
#include<stdlib.h>
void Move(char pos1, char pos2)
{
	printf("%c->%c \t", pos1, pos2);
}

void Hanota(int n, char pos1, char pos2, char pos3)
{
	if (n == 1){
		Move(pos1, pos2);
		return;
	}

	if (n >= 2){
	Hanota(n-1,pos1,pos3,pos2);
	Move(pos1, pos3);
	Hanota(n - 1, pos2, pos1, pos3);
	}
	//终止条件
	//递归调用
}
int main(){
	Hanota(5, 'A', 'B', 'C');
	printf("\n");
	Hanota(6, 'A', 'B', 'C');
	printf("\n");
	Hanota(7, 'A', 'B', 'C');
	printf("\n");
system("pause");
return 0;
}
#endif

#if 1
#include<stdio.h>
int main(){
	char str[8] = { 'g', 'o', 'o', 'd', '!' };
	char str1[6] = { 'g', 'o', 'o', 'd', '!','\0' };
	char str2[8] = "good!";
	char *str3 = "good!";
	printf("%s\n",str);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	return 0;
}
#endif




