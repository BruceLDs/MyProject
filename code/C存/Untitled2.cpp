#include<stdio.h>
int main(){
	float average(float array[10]);
	float score[10],aver;
	int i;
	printf("Enter ten secore:\n");
	for(i=0;i<=9;i++)
	scanf("%f",&score[i]);
	printf("\n");
	aver=average(score);
	printf("average score is %5.2f\n",aver);
	return 0; 
} 
float average(float array[10]){
	int i;
	float aver,sum=0;
	for(i=0;i<=9;i++) 
	sum=sum+array[i];
	aver=sum/10;
	return (aver);
}
