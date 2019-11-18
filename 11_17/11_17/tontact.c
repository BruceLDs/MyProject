#include"contact.h"

void Init(pContact pc)
{
	pc->size = 0;
}

void Add(pContact pc)
{
	pep Info;
	if (pc->size == MAX)
	{
		printf("通讯录已满，存入失败!\n");
		return;
	}
	printf("请输入联系人的姓名：\n");
	scanf("%s", Info.name);
	printf("请输入联系人的性别：\n");
	scanf("%s", Info.sex);
	printf("请输入联系人的年龄：\n");
	scanf("%d", &Info.age);
	printf("请输入联系人的电话号码：\n");
	scanf("%s", Info.tel);
	printf("请输入联系人的家庭住址：\n");
	scanf("%s", Info.addr);
	printf("存放成功!\n");
	pc->data[pc->size] = Info;
	pc->size++;
}

void Del(pContact pc)
{
	char name[20];
	printf("请输入要删除人的姓名:\n");
	scanf("%s", &name);
	int ret = Find(pc, name);
	if (ret == -1)
	{
		printf("查无此人！\n");
		return;
	}
	else
	{
		for (int i = ret; i < pc ->size -1; ++i)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->size--;
		printf("删除成功!\n");
	}
}

int  Find(pContact pc, char* name)
{
	for (int i = 0; i < pc->size; ++i)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void Modify(pContact pc)
{
	char name[20];
	printf("请输入要修改人的姓名:\n");
	scanf("%s", &name);
	int ret = Find(pc, name);
	if (ret == -1)
	{
		printf("查无此人，修改失败！\n");
	}
	else
	{
		printf("请输入联系人的姓名：\n");
		scanf("%s", pc->data[ret].name);
		printf("请输入联系人的性别：\n");
		scanf("%s", pc->data[ret].sex);
		printf("请输入联系人的年龄：\n");
		scanf("%d", &pc->data[ret].age);
		printf("请输入联系人的电话号码：\n");
		scanf("%s", pc->data[ret].tel);
		printf("请输入联系人的家庭住址：\n");
		scanf("%s", pc->data[ret].addr);
		printf("修改成功!\n");
	}
}

void Search(pContact pc)
{
	char name[20];
	printf("请输入要查找人的姓名:\n");
	scanf("%s", &name);
	int ret = Find(pc, name); 
	if (ret == -1)
	{
		printf("查无此人！\n");
	}
	else
	{
		Print(pc, ret);
	}
}

void ShowAll(pContact pc)
{
	if (pc->size == 0)
	{
		printf("通讯录为空，请先添加联系人信息!\n");
	}
	else
	{

		for (int i = 0; i < pc->size; ++i)
		{
			printf("姓名：%s\n", pc->data[i].name);
			printf("性别：%s\n", pc->data[i].sex);
			printf("年龄：%d\n", pc->data[i].age);
			printf("电话号码：%s\n", pc->data[i].tel);
			printf("家庭住址：%s\n", pc->data[i].addr);
			printf("\n");
		}
	}
}
void Print(pContact pc, int i)
{
	printf("第%d位联系人的信息:\n", i);
	printf("姓名：%s\n",pc->data[i].name);
	printf("性别：%s\n", pc->data[i].sex);
	printf("年龄：%d\n", pc->data[i].age);
	printf("电话号码：%s\n", pc->data[i].tel);
	printf("家庭住址：%s\n", pc->data[i].addr);
	printf("\n");
}
void menu()
{
	printf("\t"); printf("\t"); printf("\t"); printf("\t"); printf("***********************************\n");
	printf("\t"); printf("\t"); printf("\t"); printf("\t"); printf("**************0. exit    **********\n");
	printf("\t"); printf("\t"); printf("\t"); printf("\t"); printf("**************1. add     **********\n");
	printf("\t"); printf("\t"); printf("\t"); printf("\t"); printf("**************2. del     **********\n");
	printf("\t"); printf("\t"); printf("\t"); printf("\t"); printf("**************3. modify  **********\n");
	printf("\t"); printf("\t"); printf("\t"); printf("\t"); printf("**************4. search  **********\n");
	printf("\t"); printf("\t"); printf("\t"); printf("\t"); printf("**************5. showall **********\n");
}