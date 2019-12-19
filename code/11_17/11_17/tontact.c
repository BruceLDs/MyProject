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
		printf("ͨѶ¼����������ʧ��!\n");
		return;
	}
	printf("��������ϵ�˵�������\n");
	scanf("%s", Info.name);
	printf("��������ϵ�˵��Ա�\n");
	scanf("%s", Info.sex);
	printf("��������ϵ�˵����䣺\n");
	scanf("%d", &Info.age);
	printf("��������ϵ�˵ĵ绰���룺\n");
	scanf("%s", Info.tel);
	printf("��������ϵ�˵ļ�ͥסַ��\n");
	scanf("%s", Info.addr);
	printf("��ųɹ�!\n");
	pc->data[pc->size] = Info;
	pc->size++;
}

void Del(pContact pc)
{
	char name[20];
	printf("������Ҫɾ���˵�����:\n");
	scanf("%s", &name);
	int ret = Find(pc, name);
	if (ret == -1)
	{
		printf("���޴��ˣ�\n");
		return;
	}
	else
	{
		for (int i = ret; i < pc ->size -1; ++i)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->size--;
		printf("ɾ���ɹ�!\n");
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
	printf("������Ҫ�޸��˵�����:\n");
	scanf("%s", &name);
	int ret = Find(pc, name);
	if (ret == -1)
	{
		printf("���޴��ˣ��޸�ʧ�ܣ�\n");
	}
	else
	{
		printf("��������ϵ�˵�������\n");
		scanf("%s", pc->data[ret].name);
		printf("��������ϵ�˵��Ա�\n");
		scanf("%s", pc->data[ret].sex);
		printf("��������ϵ�˵����䣺\n");
		scanf("%d", &pc->data[ret].age);
		printf("��������ϵ�˵ĵ绰���룺\n");
		scanf("%s", pc->data[ret].tel);
		printf("��������ϵ�˵ļ�ͥסַ��\n");
		scanf("%s", pc->data[ret].addr);
		printf("�޸ĳɹ�!\n");
	}
}

void Search(pContact pc)
{
	char name[20];
	printf("������Ҫ�����˵�����:\n");
	scanf("%s", &name);
	int ret = Find(pc, name); 
	if (ret == -1)
	{
		printf("���޴��ˣ�\n");
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
		printf("ͨѶ¼Ϊ�գ����������ϵ����Ϣ!\n");
	}
	else
	{

		for (int i = 0; i < pc->size; ++i)
		{
			printf("������%s\n", pc->data[i].name);
			printf("�Ա�%s\n", pc->data[i].sex);
			printf("���䣺%d\n", pc->data[i].age);
			printf("�绰���룺%s\n", pc->data[i].tel);
			printf("��ͥסַ��%s\n", pc->data[i].addr);
			printf("\n");
		}
	}
}
void Print(pContact pc, int i)
{
	printf("��%dλ��ϵ�˵���Ϣ:\n", i);
	printf("������%s\n",pc->data[i].name);
	printf("�Ա�%s\n", pc->data[i].sex);
	printf("���䣺%d\n", pc->data[i].age);
	printf("�绰���룺%s\n", pc->data[i].tel);
	printf("��ͥסַ��%s\n", pc->data[i].addr);
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