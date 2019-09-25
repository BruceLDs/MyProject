#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu();
void test();

void game(){
char board[ROW][COL] = { 0 };
int i = 0;
int j = 0;
for (i = 0; i < ROW; i++)
{
	for (j = 0; j < COL; j++)
	{
		board[i][j] = ' ';
	}
}
display(board, ROW, COL);//打印棋盘
char ret;
while (1){
	player(board, ROW, COL);//玩家走
	display(board, ROW, COL);//打印棋盘
	 ret = cheak_win(board, ROW, COL);//检测输赢
	 if (ret != 'q'){
		 break;
	 }
	computer(board, ROW, COL);//电脑走
	display(board, ROW, COL);//打印棋盘
	ret = cheak_win(board, ROW, COL);
	if (ret != 'q'){
		break;
	}
}
	if (ret == '*')
	{
		printf("玩家赢了！\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了！\n");
	}
	else if (ret == ' ')
	{
		printf("平局！\n");
	}
	printf("*****************************************************************\n");
	printf("*****************************************************************\n");
	printf("*****************************************************************\n");
	test();
}
void menu(){
	printf("*********************\n");
	printf("****   1 .play   ****\n");
	printf("****   0 .exite  ****\n");
	printf("*********************\n");
}
void test(){
	int a = 0;
	menu();
	while (a != 1){
		printf("请选择>");
		scanf("%d", &a);          //选择
		switch (a){
		case 1:game(); break;
		case 0:return; break;
		default:printf("无此选项，请重新输入"); break;
		}
	}
}
int main(){
	srand((unsigned int)time(NULL));
	test();
	//printf("%d", ROW);
	system("pause");
	return 0;
}