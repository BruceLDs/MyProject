#include"contact.h"
int main()
{
	Contact p;
	int select = 0;
	Init(&p);
	menu();
	do{
		printf("请输入你的操作:\n");
		scanf("%d", &select);
		switch (select)
		{
		case EXIT:
			break;
		case ADD:
			Add(&p);
			break;
		case DEL:
			Del(&p);
			break;
		case MODIFY:
			Modify(&p);
			break;
		case SEARCH:
			Search(&p);
			break;
		case SHOWALL:
			ShowAll(&p);
			break;
		default:
			printf("输入错误，请重新输入选项!\n");
			break;
		}
	} while (select);
	return 0;
}