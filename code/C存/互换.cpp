#include<stdio.h>
int main(){
	int i,j;
	int c=0;
	printf("输入2个整数:\n");
	scanf("%d%d",&i,&j);
	c=i;
	i=j;
	j=c;
	printf("%d%d",i,j);
	return 0;
	
}

