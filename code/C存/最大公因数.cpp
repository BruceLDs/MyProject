#include<stdio.h>
int main(){
	int i,j;
	printf("������2������:\n");
	scanf("%d%d",&i,&j);
	while(i%j!=0){
	  int k;
	  k=i%j;
	  i=j;
	  j=k;
	}
	printf("���������:%d",j);
	return 0;
}
