#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(){
	//打印100~200 之间的素数 
		 for (int i = 100; i <= 200; i++){
		     int flag = 0;
		     for (int j = 2; j <= sqrt(i); j++){
			         if (i% j == 0){
				             flag++;
				             break;	
			}
		}
			 if (flag == 0)
				 printf("%d\t", i);
	}
		 getchar();
	    return 0;
}