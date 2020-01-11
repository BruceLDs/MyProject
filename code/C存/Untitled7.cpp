#include<stdio.h>
int main(){
	void swap(int arr[],int n);
	int array[10];
	int i;
	printf("请输入数组元素 :\n");
	for(i=0;i<10;i++)
	scanf("%d",&array[i]);
	swap(array,10);
	for(i=0;i<10;i++)
	printf("%d",array[i]);
	printf("\n");
	return 0;
	
	
}
void swap(int arr[],int n){
	int i;
	int temp;
	for(i=0;i<5;i++,n--){
	
   temp=arr[i];
   arr[i]=arr[n-1];
   arr[n-1]=temp;
}
}
