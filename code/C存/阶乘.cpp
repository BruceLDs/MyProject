#include<stdio.h>
int main(){

	int i,n;
	int sum=0;
	printf("����һ������:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum=i*(i+1);
		sum=sum*sum;
	}
	printf("%d",sum);
	return 0;
} 
