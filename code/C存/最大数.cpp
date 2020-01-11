#include<stdio.h>
int main(){
	int i,j,t;
	int a[3];
	printf("ÇëÊäÈë3¸öÊı×Ö:\n");
	for(i=0;i<3;i++)
	scanf("%d",&a[i]);
	for(j=0;j<2;j++)
    for(i=0;i<2-j;i++)
    if(a[i]<a[i+1])	
	{
    	t=a[i];a[i]=a[i+1];a[i+1]=t;
	}
	for(i=0;i<3;i++)
	printf("%d\t",a[i]);
	return 0;
}

