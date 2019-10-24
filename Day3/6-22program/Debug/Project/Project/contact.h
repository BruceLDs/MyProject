#ifndef _CONTACT_H_
#define _CONTACT_H_
#define MAX_NAME 20
#define MAX_TELE 11
#define MAX_ADDR 15
#define MAX_SEX 3
#define MAX_NUMPERSON      1000
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef struct PersonInfo{
	char name[MAX_NAME];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char sex[MAX_SEX];
}PersonInfo;
typedef  struct Contact
{
	PersonInfo per[MAX_NUMPERSON];
	int usedSize;//被使用的个数

}Contact;
void Addcontact(Contact *pCon);
int SearchContact(Contact *pCon);
void Delcontact(Contact *pCon);
void Showcontact(Contact *pCon);
void Clearcontact(Contact *pCon);
void  pSortContact(Contact *pCon);
#endif//_CONTACT_H_