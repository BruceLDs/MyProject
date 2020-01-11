#include<stdio.h>
int main(){
	int i,j;
	printf("请输入2个整数:\n");
	scanf("%d%d",&i,&j);
	while(i%j!=0){
	  int k;
	  k=i%j;
	  i=j;
	  j=k;
	}
	printf("最大公因数是:%d",j);
	return 0;
}
