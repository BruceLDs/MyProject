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
display(board, ROW, COL);//��ӡ����
char ret;
while (1){
	player(board, ROW, COL);//�����
	display(board, ROW, COL);//��ӡ����
	 ret = cheak_win(board, ROW, COL);//�����Ӯ
	 if (ret != 'q'){
		 break;
	 }
	computer(board, ROW, COL);//������
	display(board, ROW, COL);//��ӡ����
	ret = cheak_win(board, ROW, COL);
	if (ret != 'q'){
		break;
	}
}
	if (ret == '*')
	{
		printf("���Ӯ�ˣ�\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ�ˣ�\n");
	}
	else if (ret == ' ')
	{
		printf("ƽ�֣�\n");
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
		printf("��ѡ��>");
		scanf("%d", &a);          //ѡ��
		switch (a){
		case 1:game(); break;
		case 0:return; break;
		default:printf("�޴�ѡ�����������"); break;
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