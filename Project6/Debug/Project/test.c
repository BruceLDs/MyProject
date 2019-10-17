#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void menu(int *p,int k);
void print(int *p,int k){
	int i = 0;
	for (i = 0; i < k; i++){
		printf("%d\t", p[i]);
	}
	printf("\n");
}
void input(int *p, int k){
	system("cls");
	printf("请输入10个数：\n");
	int i = 0;
	for (i = 0; i < k; i++){
		scanf("%d", &p[i]);
	}
	print(p, k);
	menu(p, k);
}
void modify(int *p, int k){
	system("cls");
	int n = 0;
	int i = 0;
	int a = 0;
	printf("请输入你想修改数字的位数>\n");
	scanf("%d", &n);
	printf("请输入你想修改成的数字>\n");
	scanf("%d", &a);
	for (i = 0; i < k; i++){
		if (i == n - 1){
			p[i] = a;
		}
	}
	print(p, k);
	menu(p, k);
}
void mathsort(int *p, int k){
	system("cls");
	int *left = p;
	int i = 0;
	int j = 1;
	while (i < k){
		j = i + 1;
		while (j >i && j < k){
			if (p[i] > p[j]){
				int tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
			j++;
		}
		i++;
	}
	print(p, k);
	menu(p, k);
}

void calculate(int *p, int k){
	system("cls");
	int i = 0;
	int sum = 0;
	for (i = 0; i < k; i++){
		sum = sum + p[i];
	}
	printf("%d", sum);
	menu(p, k);
}
void menu(int *p,int k){
	int num = 0;
	printf("***************************\n");
	printf("*******1.录入  ************\n");
	printf("*******2.修改  ************\n");
	printf("*******3.排序  ************\n");
	printf("*******4.计算  ************\n");
	printf("*******5.退出  ************\n");
	printf("***************************\n");
	printf("请输入>\n");
	scanf("%d", &num);
	switch (num){
	case 1:input(p, k); break;
	case 2:modify(p,k); break;
	case 3: mathsort(p,k); break;
	case 4: calculate(p, k); break;
	case 5:printf("已退出系统\n"); break;
	default:printf("输入错误，退出系统\n"); break;
	}
}
int main(){
	int arr[10] = { 0 };
	menu(arr, 10);
	system("pause");
	return 0;
}