#include<stdio.h>
int main(){
	int arr[10];
	int i;
	int t=0;
	printf("������10������:\n");
	for(i=0;i<10;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<9;i++)
	if(arr[i]>arr[i+1]){
	  t=arr[i];
	  arr[i]=arr[i+1];
	  arr[i+1]=t;
	 
	 }
	 
	printf("���ֵΪ:%d",arr[i+1]);

	return 0;

}
