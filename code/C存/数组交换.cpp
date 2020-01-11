#include<stdio.h>
int main(){
	int  i, t;
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int b[10]={10,11,12,13,14,15,16,17,18,19};
	for(i=0; i<10; i++){
		t=a[i];a[i]=b[i];b[i]=t;
	}
	for(i=0; i<10; i++) 
	printf("%d\t", a[i]);
	printf("\n");
	for(i=0; i<10; i++)
	printf("%d\t", b[i]);
	return 0;
}
