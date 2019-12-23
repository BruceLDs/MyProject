#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 5
#define COL 5

char qi[ROW][COL];
//��ӡ�˵�
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
//����Ƿ�����
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

//�����Ӯ
char winner(char qi[ROW][COL])
{
	int row;
	int col;
	//����ÿһ�У�����Ƿ�����ͬ����
	for (row = 0; row < ROW; row++)
	{
		if (qi[row][0] == qi[row][1] && qi[row][0] == qi[row][2] && qi[row][0] == qi[row][3] && qi[row][0] == qi[row][4] && qi[row][0] != ' ')
		{
			return qi[row][0];
		}
	}
	//����ÿһ�У�����Ƿ�����ͬ����
	for (col = 0; col < COL; col++)
	{
		if (qi[0][col] == qi[1][col] && qi[0][col] == qi[2][col] && qi[0][col] == qi[3][col] && qi[0][col] == qi[4][col] && qi[0][col] != ' ')
		{
			return qi[0][col];
		}
	}
	//���Խ����Ƿ�����ͬ����
	if (qi[0][0] == qi[1][1] && qi[0][0] == qi[2][2] && qi[0][0] == qi[3][3] && qi[0][0] == qi[4][4] && qi[0][0] != ' ')
	{
		return qi[0][0];
	}
	else if (qi[0][4] == qi[1][3] && qi[0][4] == qi[2][2] && qi[0][4] == qi[3][1] && qi[0][4] == qi[4][0] && qi[0][4] != ' ')
	{
		return qi[0][4];
	}
	//ƽ��
	else if (is_full(qi) == 1)
	{
		return ' ';
	}
	else
	{
		return 'p';
	}
}
//����λ���Ƿ�����
int is_exist(char qi[ROW][COL], int row, int col)
{
	if (qi[row][col] == ' ')
	{
		return 1;
	}
	return 0;
}

//�������
void player_move(char qi[ROW][COL])
{
	int row = 0;
	int col = 0;
	while (1)
	{
		printf("����������Ҫ���ӵ��±꣨x y����");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("���벻�Ϸ������������룺");
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
			printf("��λ���Ѿ����ӣ�����������:");
			continue;
		}
	}
}


//��������
void computer_move(char qi[ROW][COL])
{
	printf("��������\n");
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

//��ӡ�˵�
void  menu()
{
	printf("*********************\n");
	printf("1����ʼ��Ϸ\n");
	printf("2���˳���Ϸ\n");
	printf("*********************\n");
}
//��ʼ��
int Init(char qi[ROW][COL])
{
	int choice = 0;
	menu();//��ӡ�˵�
	for (int row = 0; row < ROW; row++)//��ʼ������Ϊ���ַ�
	{
		for (int col = 0; col < COL; col++)
		{
			qi[row][col] = ' ';
		}
	}
	scanf("%d", &choice);
	if (choice == 1)
	{
		print(qi);//���ѡ��ʼ��Ϸ����ӡ����
	}
	else if (choice == 2)
	{
		printf("Game Over!\n");
	}
	return choice;
}

int main()
{
	//�����������
	srand((unsigned)time(0));
	while (1)
	{
		if (Init(qi) == 2)
		{
			break;
		}
		while (1)
		{
			//�������
			player_move(qi);
			//����Ƿ�ƽ��
			if (winner(qi) == 'p')
			{
				printf("ƽ��\n");
				break;
			}
			//�����Ӯ
			if (winner(qi) == 'x')
			{
				printf("��Ϸ���������ʤ����\n");
				break;
			}
			//��������
			computer_move(qi);
			//�����Ӯ
			if (winner(qi) == 'o')
			{
				printf("��Ϸ����������ʤ����\n");
				break;
			}
		}
	}
	system("pause");
	return 0;
}
