#include <stdio.h>
#include<malloc.h> //�õ�ָ���СΪSize���ڴ���������ֽڵ�ָ��// 
#include<string.h> 
#include<stdlib.h> //��׼�⺯��//  
#define NULL 0 
#define LEN sizeof(struct Student) //�����ֽ�//  
struct Student//   ����ṹ�� 
{  long num;
   char name[30];
   char sex;
   int age;
   char addr[30];
   int phone;
   struct Student *next;
} ;
int n;
struct Student*add()//  ��Ӻ��� 
{    struct Student*head;
	 char name[30];
	struct Student*p1,*p2;
	n=0;
	p1=(struct Student*)malloc(LEN);
	p2=p1; 
	printf("����������:\n");
	scanf("%s",&p1->name);
if(strcmp(p1->name,"0")!=0) 
  {
	printf("������ѧ��\n");
	scanf("%d",&p1->num);
	printf("�������Ա�:\n");
	scanf("%c",&p1->sex);
	printf("����������:\n");
	scanf("%d",&p1->age);
	printf("�������ͥ��ַ:\n");
	scanf("%s",&p1->addr);
	printf("������绰����:\n");
	scanf("%d",&p1->phone);
	printf("¼��ɹ�");
	while(1){
	head=NULL;
      n=n+1; 
      if(n==1) 
        head=p1; 
      else
        p2->next=p1; 
      p2=p1; 
      printf("����������:"); 
      scanf("%s",&p1->name);
      if(strcmp(name,"0")==0) 
      { 
        break; 
      } 
      else
      { 
        p1=(struct Student *)malloc(LEN);
		 strcpy(p1->name,name); 
       printf("������ѧ��\n");
	scanf("%d",&p1->num);
	printf("�������Ա�:\n");
	scanf("%c",&p1->sex);
	printf("����������:\n");
	scanf("%d",&p1->age);
	printf("�������ͥ��ַ:\n");
	scanf("%s",&p1->addr);
	printf("������绰����:\n");
	scanf("%d",&p1->phone);
	printf("¼��ɹ�");
    } 
    p2->next=NULL; 
    return (head); 
}
  } 
} 
		

	
void menu()//    ¼��˵� 
{
	printf("***************ѧ����Ϣ¼�����******************\n");
	printf("***************1.��Ϣ¼��************************\n");
	printf("***************2.ɾ����Ϣ************************\n");
	printf("***************3.��ѯ��Ϣ************************\n");
	printf("***************4.ȫ�����************************\n");
	printf("***************5.��������************************\n");
}
void print(struct Student *head)   //���뺯�� 
{ 
  struct Student *p; 
  if(head!=NULL) 
  { 
    p=head; 
    printf("��ͨѶ¼���ڹ���%d��:\n",n); 
    printf("---����-------ѧ��--------�Ա�-------����-------��ͥסַ------�绰����---\n"); 
    printf("==================================\n"); 
    do
    { 
      printf("== %s",p->name); printf("    "); 
      printf("%d",p->num); printf("    "); 
      printf("%s",p->sex); printf("    "); 
      printf("%d",p->age); printf("    "); 
      printf("%s",p->addr); printf("    \n"); 
      printf("%d",p->phone); printf("    \n"); 
      p=p->next; 
    }while(p!=NULL); 
    printf("==================================\n"); 
  } 
  else
    printf("ͨѶ¼Ϊ��,�޷����!\n"); 
} 
struct Student*del()//   ɾ������ 
{   struct Student*head;
	struct Student*p;
	char name[30];
	p=head;
	printf("������Ҫɾ���˵�����:\n");
	 gets(name); 
  if(strcmp(head->name,name)==0) 
  { 
    head=head->next; 
    free(p); 
    printf("ɾ�������ɹ���\n"); 
    return head; 
  } 
	
} 
struct Student* sel()//  ��ѯ���� 
{   struct Student*head;
	struct Student*p1,*p2;
	char name[30];
	head=NULL;
    p1=head;
    printf("����������˵�����:\n");
	gets(name);
	while(p1!=NULL)
	{
	if(strcmp(p1->name,name)==0)
	 printf("����ҵ�������:\n"); 
      printf("+++++++++++++++++++++++++++++++++++\n"); 
      printf("++ %s    %d    %s    %d    %s     %d\n",p1->name,p1->num,p1->sex,p1->age,p1->addr,p1->phone); 
      printf("+++++++++++++++++++++++++++++++++++\n");
	
}

}
struct Student*all() //ȫ��������� 
{   struct Student*head;
	struct Student*p;
	p=head;
	if(head!=NULL)
	do{
	printf("����:%s       ѧ�ţ�%d        �Ա�:%s        ����:%d            ��ͥסַ��%s           �绰���룺%d",p->name,p->num,p->sex,p->age,p->addr,p->phone);
	p=p->next;
}while(p!=NULL);
}

int main()
{
  struct Student *head; 
  int m;
  menu();
  printf("�������Ӧ������ѡ�");
  scanf("%d",&m);
  switch(m) 
  {
     
    case '1':  {
	          
	          head=add();
               } 
      break;
     
    case '2': head=del();
              
    break;
      
    case '3': head=sel(); 
              
      break; 
    case '4': head=all(
	);
              
      break; 
    case '5': 
      break;
  }
}


















