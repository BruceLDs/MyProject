#include<stdio.h>
int main(){
	int i, sum;
	int sign= -1;
	for(i=2; i<101; i++)
	{
	sum = 1 + sign /i;
	sign = sign * (-1); 
}   
	printf("%d", sum);
	return 0;
}
