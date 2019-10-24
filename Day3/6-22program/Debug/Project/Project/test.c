#define  _CRT_SECURE_NO_WARNINGS
#include"contact.h"

enum OPtion{
	EXIT,//0
	ADD,//1
	SEAR,//2
	DEL,//3
	SHOW,//4
	EMPTY,//5
	SORT//6
};
void menu(){
	printf("*******************************\n");
	printf("*****  1.添加联系人************\n");
	printf("*****  2.查找联系人************\n");
	printf("*******3.删除联系人************\n");
	printf("*******4.显示联系人************\n");
	printf("*******5.清空联系人************\n");
	printf("*******6.联系人排序************\n");
	printf("*******0.退出      ************\n");
	printf("*******************************\n");

}
void start(){
	int input = 0;
		Contact con;
		InitContact(&con);
		do
		{
			menu();
			printf("请输入你的操作>");
			scanf("%d", &input);
			switch (input)
			{
			case  ADD:
				AddContact(&con);
				break;
			case SEAR:
				SearchContact(&con);
				break;
			case DEL:
				DelContact(&con);
			case SHOW:
				ShowContact(&con);
				break;
			case EMPTY:
				ClearContact(&con);
				break;
			case SORT:
			pSortContact(&con);
			break;
			default:printf("输入错误！\n");break;
			}
		} while (input);
	}
int main(){
	start();
	system("pause");
	return 0;
}