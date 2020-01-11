#include<stdio.h>
int main(){
	int i;
	int sum =0;
	for(i=1; i<101; i++)
	{
		if (i%10==9){
		printf("% d", i);
		sum ++;
		}
		 
	}
	printf("\n");
	printf("Ò»¹²ÓĞ :%d\n", sum);
	return 0;
}

