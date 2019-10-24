#define  _CRT_SECURE_NO_WARNINGS
#include"contact.h"
void InitContact(Contact *pCon){
	assert(pCon!= NULL);
	pCon->usedSize = 0;
		memset(pCon->per, 0, sizeof(pCon->per));
}
void AddContact(Contact *pCon){
	system("cls");
	assert(pCon != NULL);
	if (pCon->usedSize == MAX_NUMPERSON){
		printf("已存满\n");
		return;
	}
	printf("请输入姓名>\n");
	scanf("%s", pCon->per[pCon->usedSize].name);
	printf("请输入性别>\n");
	scanf("%s", pCon->per[pCon->usedSize].sex);
	printf("请输入年龄>\n");
	scanf("%d", &(pCon->per[pCon->usedSize].age));
	printf("请输入电话>\n");
	scanf("%s", pCon->per[pCon->usedSize].tele);
	printf("请输入地址>\n");
	scanf("%s", pCon->per[pCon->usedSize].addr);
	pCon->usedSize++;
	printf("添加成功！\n");
}
int SearchContact(Contact *pCon){
	system("cls");
	assert(pCon != NULL);
	if (pCon->usedSize == 0){
		printf("通讯录为空\n");
		return -1;
	}
		char Nname[MAX_NAME];
	printf("请输入姓名>");
	scanf("%s", Nname);
	int i = 0;
	for (i = 0; i < pCon->usedSize;i++){
		if (strcmp(pCon->per[i].name, Nname)==0){
			printf("%-20s %-20s %-20s %-20s %-20s\n", "姓名", "性别", "年龄", "电话", "地址");
			printf("%-20s %-20s %-20d %-20s %-20s \n",
				pCon->per[i].name, pCon->per[i].sex, pCon->per[i].age, pCon->per[i].tele, pCon->per[i].addr);
			return i;
		}
	}
	return -1;
}
void DelContact(Contact *pCon){	
	system("cls");
	int i = 0; 
	assert(pCon != NULL);
	int index = SearchContact(pCon);
	if (index == -1){
		printf("查无此人\n");
	}
	else{
		for (i = index; i < pCon->usedSize - 1; i++){
			pCon->per[i] = pCon->per[i + 1];
		}
		pCon->usedSize--;
		printf("删除成功！\n");
	}
}
void ShowContact(Contact *pCon){
	system("cls");
	assert(pCon != NULL);
	printf("%-20s %-20s %-20s %-20s %-20s\n", "姓名" , "性别","年龄","电话", "地址");
	int i = 0;
	for (i = 0; i < pCon->usedSize; i++){
		printf("%-20s %-20s %-20d %-20s %-20s \n",
			pCon->per[i].name, pCon->per[i].sex, pCon->per[i].age, pCon->per[i].tele, pCon->per[i].addr);
	}

}

void ClearContact(Contact *pCon){
	system("cls");
	assert(pCon != NULL);
	free(pCon->per);
	pCon->usedSize = 0;
}
void  pSortContact(Contact *pCon){
	assert(pCon != NULL);
	PersonInfo tmp;
	int i = 0;
	int j = 0;
	for (j = 0; j < pCon->usedSize; j++){
		for (i = 0; i < pCon->usedSize - j; i++){
			if (pCon->per[i].age>pCon->per[i + 1].age)
			{
				tmp = pCon->per[i];
				pCon->per[i] = pCon->per[i + 1];
				pCon->per[i + 1] = tmp;
			}
		}
	}
}