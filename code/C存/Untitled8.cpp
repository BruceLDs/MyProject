#include<stdio.h>
int main(){
void copy(char form[],char to[]);
char a[]="I am a teacher";
char b[]="You are a student";
printf("string a=%s\nstring b=%s\n",a,b);
printf("copy string a to b:\n");
copy(a,b);
printf("\nstring a=%s\nstring b=%s\n",a,b);
return 0;

}
void copy(char form[],char to[]){
	for(;*form!='\0';form++,to++)
	*to=*form;
	*to='\0';
	

	
}
