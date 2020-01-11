#include<stdio.h>
int main(){
	int i=10,j=2;
	int k;
	k=i;
	i=j;
	j=k;
	printf("%d\t%d",i,j);
	return 0;
} 
