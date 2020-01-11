#include<stdio.h>
int main(){
	int a=100,b=10;
	int *p1;int *p2;
	p1=&a;
	p2=&b;
	printf("a=%d,b=%d\n",a,b);
	printf("*p1=%d,*p2=%d\n",*p1,*p2);
	return 0;
}
