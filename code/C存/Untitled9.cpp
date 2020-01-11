#include<stdio.h>
int main(){
	float score[][4]={{60,70,80,90},{56,89,67,88},{34,78,90,66}};
	void *search(float (*p1)[4],int n);
	int i,k;
	printf("enter numner:");
	scanf("%d",&k);
	search(score,k);
	printf("\n");
	return 0;
}
 void *search(float (*p1)[4],int n){
	float *p2;
	p2=*(p1+n);
	int i;
	for(i=0;i<4;i++)
	printf("%5.2f\t",*(p2+i));

}
	
