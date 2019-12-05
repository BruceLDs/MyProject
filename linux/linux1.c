#include<stdio.h>
#include<unistd.h>
int main(){
printf("%d \n", getpid());
printf("%d \n", getppid());
while(1){
sleep(1);
}
return 0;
}

