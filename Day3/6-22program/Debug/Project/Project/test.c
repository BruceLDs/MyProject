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
	printf("*****  1.�����ϵ��************\n");
	printf("*****  2.������ϵ��************\n");
	printf("*******3.ɾ����ϵ��************\n");
	printf("*******4.��ʾ��ϵ��************\n");
	printf("*******5.�����ϵ��************\n");
	printf("*******6.��ϵ������************\n");
	printf("*******0.�˳�      ************\n");
	printf("*******************************\n");

}
void start(){
	int input = 0;
		Contact con;
		InitContact(&con);
		do
		{
			menu();
			printf("��������Ĳ���>");
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
			default:printf("�������\n");break;
			}
		} while (input);
	}
int main(){
	start();
	system("pause");
	return 0;
}