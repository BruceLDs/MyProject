#define  _CRT_SECURE_NO_WARNINGS

#if 0
#include<stdio.h>
#include<stdlib.h>
void find(int* arr,int size){
	//int left = 0;
	//int right = size - 1;
	//while (left < right){
	//	while (arr[left] % 2 && left < right){//奇数
	//		left++;
	//	}
	//	while (!(arr[right] % 2) && left < right){//偶数
	//		right--;
	//	}
	//	int tmp = arr[left];
	//	arr[left] = arr[right];
	//	arr[right] = tmp;
	//}
	int* front = arr;
	int* back = arr + size - 1;
	while (front < back){
		if (*front % 2){
			front++;
		}
		if (*back % 2 == 0){
			back--;
		}
		if (*front % 2 == 0 && *back % 2){
			int tmp = *front;
			*front = *back;
			*back = tmp;
			front++;
			back--;
		}
	}
}
int main(){
	int arr[] = { 1, 3, 2, 5,7,7,3,5, 4, 6, 7, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	find(arr, size);
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


#endif

#if 0

#include<stdio.h>
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *p = arr;
	int *q = arr;
	*(p + 2) += 2;//*(p+2)=*(p+2)+2
	*(q++) += 1;//*(q++)=*q+2
	printf("%d\n", *(p + 2));
	printf("%d\n", *(q++));
	return 0;
}
#endif


#if 0
#include<stdio.h>
int main(){
	int arr[3][4] = { 0 };
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr[1]));
	printf("%d\n", sizeof(arr[1]+1));
	printf("%d\n", sizeof(arr+1));
	printf("%d\n", sizeof(&arr+1));
	//解引用
	//* [ ]  ->  
	//*(p+n)   ->   p[n]
	int arr1[4] = { 1,2,3,4 };
	printf("%d\n", sizeof(arr1[5]));
	printf("%p\n",arr1 + 1);
	printf("%p\n", arr1 + 3);
	printf("%p\n", &arr1 + 1);
	return 0;
}
#endif


#if 0
#include<stdio.h>
void DelBlink(char *str){
	int i = 0;
	int j = 0;
	int flag = 1;//已处理
	while (str[i] != '\0'){
		if (str[i] == ' '&& flag){//空格已处理
			i++;
		}
		else if (str[i] != ' '&& !flag){//字符未处理
			str[j++] = str[i++];
		}
		else if (str[i] != ' '&& flag){//字符已处理
			str[j++] = str[i++];
			flag = 0;
		}
		else{                                  //空格未处理
			str[j++] = str[i++];
			flag = 1;
		}
	}
	if (str[j - 1] == ' '){
		str[j - 1] = '\0';
	}
	else{
		str[j] = '\0';
	}
}
int  main(){
	char str[] = "   ab  cvvc       id    efg        ";
	DelBlink(str);
	printf("%s", str);
	return 0;
}
#endif


#if 1
#include<stdio.h>
int  IsLittle()//判断主机序是否为小端
{
	short a = 0x0001;//小数据为0x01,高数据为0x00
	return *(char *)&a; //低地址放小数据
}
long Htonl(long a)
{
	long b = 0;
	if (!IsLittle())//大端
	{
		return a;
	}
	for (int i = 0; i<sizeof(a); i++)//小端:0x12345678->0x78563412
	{                                            //处理单位为字节,1字节8位
		b = (b << 8) | (a & 0xff);
		a >>= 8;
	}
	return b;
}
int main()
{                                                //网络序统一为大端
	printf("%x\n", Htonl(0x12345678));
	return 0;
}
#endif


#if 0

#include <stdio.h>
typedef union student_s
{
	int i;
	unsigned char ch[4];
}student_t;
int main(int argc, char *argv[])
{
	student_t  student = { 0 };
	student.i = 0x12345678;
	printf("%x\t%x\t%x\t%x\n", student.ch[0], student.ch[1], student.ch[2], student.ch[3]);
	return 0;
}
#endif

//0x11  2233  44
//高位->低位
//0x100低地址  ->      0x101    0x102高地址
#if 0
#include<stdio.h>
int main(){
	int a = 0x12345678;
	printf("%x\n", *(char*)&a);//转化为char*会截断
	return 0;
}
#endif