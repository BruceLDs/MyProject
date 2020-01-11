#include<stdio.h>
int main(){
int fun(int x,int y,int (*p)(int,int));
int max(int,int);
int min(int,int);
int add(int,int);
int a=34,b=-21,n;
printf("Please Enter a number:\n");
scanf("%d",&n);
if(n==1)
 fun(a,b, max);
if(n==2)
 fun(a,b,min);
if(n==3)
 fun(a,b,add);
 return 0;
 }
 int fun(int x,int y,int(*p)(int,int)){
 	int end;
 	end=(*p)(x,y);
 	printf("%d",end);
 }
int max(int x,int y){
	int z;
	z=(x>y)?x:y;
	printf("max=");
	return (z);
}
int min(int x,int y){
	int z;
	z=(x>y)?y:x;
	printf("min=");
	return (z);
}
int add(int x,int y){
	int sum;
	sum=x+y;
	printf("sum=");
	return (sum);
}
