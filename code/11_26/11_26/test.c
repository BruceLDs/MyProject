#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 5
#define COL 5

char qi[ROW][COL];
//打印菜单
void print(char qi[ROW][COL])
{
	for (int row = 0; row<ROW; row++)
	{
		printf("************************************\n");
		printf("|      |      |      |      |      |\n");
		printf("|   %c  |   %c  |   %c  |   %c  |   %c  |\n", qi[row][0], qi[row][1], qi[row][2], qi[row][3], qi[row][4]);
		printf("|      |      |      |      |      |\n");
	}
	printf("************************************\n");
}
//检查是否下满
int is_full(char qi[ROW][COL])
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (qi[row][col] == ' ')
			{
				return 1;
			}
		}
	}
	return 0;
}

//检查输赢
char winner(char qi[ROW][COL])
{
	int row;
	int col;
	//遍历每一行，检查是否有相同棋子
	for (row = 0; row < ROW; row++)
	{
		if (qi[row][0] == qi[row][1] && qi[row][0] == qi[row][2] && qi[row][0] == qi[row][3] && qi[row][0] == qi[row][4] && qi[row][0] != ' ')
		{
			return qi[row][0];
		}
	}
	//遍历每一列，检查是否有相同棋子
	for (col = 0; col < COL; col++)
	{
		if (qi[0][col] == qi[1][col] && qi[0][col] == qi[2][col] && qi[0][col] == qi[3][col] && qi[0][col] == qi[4][col] && qi[0][col] != ' ')
		{
			return qi[0][col];
		}
	}
	//检查对角线是否有相同棋子
	if (qi[0][0] == qi[1][1] && qi[0][0] == qi[2][2] && qi[0][0] == qi[3][3] && qi[0][0] == qi[4][4] && qi[0][0] != ' ')
	{
		return qi[0][0];
	}
	else if (qi[0][4] == qi[1][3] && qi[0][4] == qi[2][2] && qi[0][4] == qi[3][1] && qi[0][4] == qi[4][0] && qi[0][4] != ' ')
	{
		return qi[0][4];
	}
	//平局
	else if (is_full(qi) == 1)
	{
		return ' ';
	}
	else
	{
		return 'p';
	}
}
//检查该位置是否有子
int is_exist(char qi[ROW][COL], int row, int col)
{
	if (qi[row][col] == ' ')
	{
		return 1;
	}
	return 0;
}

//玩家落子
void player_move(char qi[ROW][COL])
{
	int row = 0;
	int col = 0;
	while (1)
	{
		printf("请输入您想要落子的下标（x y）：");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("输入不合法，请重新输入：");
			continue;
		}
		if (is_exist(qi, row, col) == 1)
		{
			qi[row][col] = 'x';
			print(qi);
			break;
		}
		else
		{
			printf("该位置已经有子，请重新输入:");
			continue;
		}
	}
}


//电脑落子
void computer_move(char qi[ROW][COL])
{
	printf("电脑落子\n");
	while (1)
	{
		int row = rand() % ROW;
		int col = rand() % COL;
		if (is_exist(qi, row, col) == 1)
		{
			qi[row][col] = 'o';
			print(qi);
			break;
		}
	}
}

//打印菜单
void  menu()
{
	printf("*********************\n");
	printf("1、开始游戏\n");
	printf("2、退出游戏\n");
	printf("*********************\n");
}
//初始化
int Init(char qi[ROW][COL])
{
	int choice = 0;
	menu();//打印菜单
	for (int row = 0; row < ROW; row++)//初始化棋盘为空字符
	{
		for (int col = 0; col < COL; col++)
		{
			qi[row][col] = ' ';
		}
	}
	scanf("%d", &choice);
	if (choice == 1)
	{
		print(qi);//如果选择开始游戏，打印棋盘
	}
	else if (choice == 2)
	{
		printf("Game Over!\n");
	}
	return choice;
}

int main()
{
	//产生随机种子
	srand((unsigned)time(0));
	while (1)
	{
		if (Init(qi) == 2)
		{
			break;
		}
		while (1)
		{
			//玩家落子
			player_move(qi);
			//检查是否平局
			if (winner(qi) == 'p')
			{
				printf("平局\n");
				break;
			}
			//检查输赢
			if (winner(qi) == 'x')
			{
				printf("游戏结束、玩家胜利！\n");
				break;
			}
			//电脑落子
			computer_move(qi);
			//检查输赢
			if (winner(qi) == 'o')
			{
				printf("游戏结束、电脑胜利！\n");
				break;
			}
		}
	}
	system("pause");
	return 0;
}
