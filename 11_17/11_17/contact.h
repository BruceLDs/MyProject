#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX  100

typedef struct people
{
	char name[20];
	char sex[10];
	int age;
	char tel[15];
	char addr[30];
} pep;

typedef struct contact
{
	pep data[MAX];
	int size;

}Contact, *pContact;

enum Select
{
	EXIT,
	ADD,
	DEL,
	MODIFY,
	SEARCH,
	SHOWALL
};
void Init(pContact pc);
void Add(pContact pc);
void Del(pContact pc);
void Modify(pContact pc);
void Search(pContact pc);
void ShowAll(pContact pc);
void Print(pContact pc, int i);
int Find(pContact pc , char* name);
void meun();






