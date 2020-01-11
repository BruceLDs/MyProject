#include <stdio.h>
int main(){
	void max(int b[]);
	int a[10];
	int i;
	printf("Please Enter Ten Numebers\n");
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
    max(a); 
	for(i=0;i<10;i++)
	printf("%d",a[i]);
	return 0;
}
 void max(int b[]){
	int i,j,k,t;
	for(i=0;i<9;i++){
		k=i; 
		for(j=i+1;j<10;j++){
			if(b[k]>b[j])
			k=j;
			t=b[k];b[k]=b[i];b[i]=t;
		}
	} 
}

