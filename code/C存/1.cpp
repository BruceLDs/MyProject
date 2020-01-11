#include <stdio.h>
#include<malloc.h> //得到指向大小为Size的内存区域的首字节的指针// 
#include<string.h> 
#include<stdlib.h> //标准库函数//  
#define NULL 0 
#define LEN sizeof(struct Student) //计算字节//  
struct Student//   定义结构体 
{  long num;
   char name[30];
   char sex;
   int age;
   char addr[30];
   int phone;
   struct Student *next;
} ;
int n;
struct Student*add()//  添加函数 
{    struct Student*head;
	 char name[30];
	struct Student*p1,*p2;
	n=0;
	p1=(struct Student*)malloc(LEN);
	p2=p1; 
	printf("请输入姓名:\n");
	scanf("%s",&p1->name);
if(strcmp(p1->name,"0")!=0) 
  {
	printf("请输入学号\n");
	scanf("%d",&p1->num);
	printf("请输入性别:\n");
	scanf("%c",&p1->sex);
	printf("请输入年龄:\n");
	scanf("%d",&p1->age);
	printf("请输入家庭地址:\n");
	scanf("%s",&p1->addr);
	printf("请输入电话号码:\n");
	scanf("%d",&p1->phone);
	printf("录入成功");
	while(1){
	head=NULL;
      n=n+1; 
      if(n==1) 
        head=p1; 
      else
        p2->next=p1; 
      p2=p1; 
      printf("请输入姓名:"); 
      scanf("%s",&p1->name);
      if(strcmp(name,"0")==0) 
      { 
        break; 
      } 
      else
      { 
        p1=(struct Student *)malloc(LEN);
		 strcpy(p1->name,name); 
       printf("请输入学号\n");
	scanf("%d",&p1->num);
	printf("请输入性别:\n");
	scanf("%c",&p1->sex);
	printf("请输入年龄:\n");
	scanf("%d",&p1->age);
	printf("请输入家庭地址:\n");
	scanf("%s",&p1->addr);
	printf("请输入电话号码:\n");
	scanf("%d",&p1->phone);
	printf("录入成功");
    } 
    p2->next=NULL; 
    return (head); 
}
  } 
} 
		

	
void menu()//    录入菜单 
{
	printf("***************学生信息录入界面******************\n");
	printf("***************1.信息录入************************\n");
	printf("***************2.删除信息************************\n");
	printf("***************3.查询信息************************\n");
	printf("***************4.全部输出************************\n");
	printf("***************5.结束程序************************\n");
}
void print(struct Student *head)   //输入函数 
{ 
  struct Student *p; 
  if(head!=NULL) 
  { 
    p=head; 
    printf("本通讯录现在共有%d人:\n",n); 
    printf("---姓名-------学号--------性别-------年龄-------家庭住址------电话号码---\n"); 
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
    printf("通讯录为空,无法输出!\n"); 
} 
struct Student*del()//   删除函数 
{   struct Student*head;
	struct Student*p;
	char name[30];
	p=head;
	printf("请输入要删除人的姓名:\n");
	 gets(name); 
  if(strcmp(head->name,name)==0) 
  { 
    head=head->next; 
    free(p); 
    printf("删除操作成功！\n"); 
    return head; 
  } 
	
} 
struct Student* sel()//  查询函数 
{   struct Student*head;
	struct Student*p1,*p2;
	char name[30];
	head=NULL;
    p1=head;
    printf("请输入查找人的姓名:\n");
	gets(name);
	while(p1!=NULL)
	{
	if(strcmp(p1->name,name)==0)
	 printf("你查找的内容是:\n"); 
      printf("+++++++++++++++++++++++++++++++++++\n"); 
      printf("++ %s    %d    %s    %d    %s     %d\n",p1->name,p1->num,p1->sex,p1->age,p1->addr,p1->phone); 
      printf("+++++++++++++++++++++++++++++++++++\n");
	
}

}
struct Student*all() //全部输出函数 
{   struct Student*head;
	struct Student*p;
	p=head;
	if(head!=NULL)
	do{
	printf("姓名:%s       学号：%d        性别:%s        年龄:%d            家庭住址：%s           电话号码：%d",p->name,p->num,p->sex,p->age,p->addr,p->phone);
	p=p->next;
}while(p!=NULL);
}

int main()
{
  struct Student *head; 
  int m;
  menu();
  printf("请输入对应操作的选项：");
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


















