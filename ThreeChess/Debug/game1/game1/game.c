#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"

void display(char board[ROW][COL],int row,int col){
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < ROW; i++){
		for (j = 0; j < COL; j++){
			printf(" %c ", board[i][j]);
			if (j < COL - 1)
				printf("|");
		}
		printf("\n");
		if (i < ROW - 1){
		for (k = 0; k < ROW; k++){
			printf("----");
		}
		printf("\n");
	}
	}
}//打印棋盘
void player(char board[ROW][COL], int row, int col){
	int m = 0;
	int n = 0;
	while (1){
		printf("玩家走>\n");
		scanf("%d%d", &m, &n);
		if (board[m-1][n-1] == ' '){
			if (m > 0 && m <= ROW && n > 0 && n <= COL){
				board[m-1][n-1] = '*';
				break;
			}
			else{
				printf("输入非法，请重新输入！\n");
			}
		}
	}
}
//玩家走
void computer(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	printf("电脑走>\n");
	while (1){
		i = rand() % ROW;
		j = rand() % COL;
		if (board[i][j] == ' '){
				board[i][j] = '#';
				return;
		}
	}
}
static int is_full(char board[ROW][COL],int row,int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;


}
char cheak_win(char board[ROW][COL],int row,int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col-2; j++){
			if ((board[i][j] == board[i][j+1]) && (board[i][j] == board[i][j+2]) && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}//横向检测
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row-2; i++){
			if ((board[i][j] == board[i+1][j]) && (board[i+1][j] == board[i+2][j]) && (board[i][j] != ' '))
			{
				return board[i][j];
			}
		}
	}//纵向检测
	j = 0;
		for (i = 0; i < row - 2; i++){
			if ((board[i][j] == board[i + 1][j + 1]) && (board[i + 1][j + 1] == board[i + 2][j + 2]) && (board[i][j] != ' '))
			{
				return board[i][j];
			}
			j--;
			if (j>col - 2){
				break;
			}
	}//左斜向下检测
		j = 0;
		for (i = row-1; i >1; i--){

			if ((board[i][j] == board[i - 1][j + 1]) && (board[i - 1][j + 1] == board[i - 2][j + 2]) && (board[i][j] != ' '))
			{
				return board[i][j];
			}
			j++;
			if (j == col-2){
				break;
			}
	}//右斜向下检测
	if (is_full(board, row, col))
	{
		return ' ';//平局
	}
	return 'q';//游戏继续
}