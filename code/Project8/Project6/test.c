#define _CRT_SECURE_NO_WARNINGS 1
#include <math.h>
#include <stdio.h>
#include <conio.h>
//int main()
//{
//	long int i, x, y, z;
//	for (i = 1; i<100000; i++)
//	{
//		x = sqrt(i + 100); 
//		y = sqrt(i + 268); 
//		if (x*x == i + 100 && y*y == i + 268) 
//			printf("\n%ld\n", i);
//	}
//	return 0;
//}
//int main()
//{
//	int day, month, year, sum, leap;
//	printf("\nplease input year,month,day\n");
//	scanf("%d,%d,%d", &year, &month, &day);
//	switch (month) /*�ȼ���ĳ����ǰ�·ݵ�������*/
//	{
//	case 1:sum = 0; break;
//	case 2:sum = 31; break;
//	case 3:sum = 59; break;
//	case 4:sum = 90; break;
//	case 5:sum = 120; break;
//	case 6:sum = 151; break;
//	case 7:sum = 181; break;
//	case 8:sum = 212; break;
//	case 9:sum = 243; break;
//	case 10:sum = 273; break;
//	case 11:sum = 304; break;
//	case 12:sum = 334; break;
//	default:printf("data error"); break;
//	}
//	sum = sum + day; /*�ټ���ĳ�������*/
//	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) /*�ж��ǲ�������*/
//		leap = 1;
//	else
//		leap = 0;
//	if (leap == 1 && month > 2) /*������������·ݴ���2,������Ӧ�ü�һ��*/
//		sum++;
//	printf("It is the %dth day.", sum);
//	return 0;
//}
//int main()
//{
//	char c;
//	int letters = 0, space = 0, digit = 0, others = 0;
//	printf("please input some characters\n");
//	while ((c = getchar()) != '\n')
//	{
//		if (c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z')
//			letters++;
//		else if (c == ' ')
//			space++;
//		else if (c >= '0'&&c <= '9')
//			digit++;
//		else
//			others++;
//	}
//	printf("all in all:char=%d space=%d digit=%d others=%d\n", letters,
//		space, digit, others);
//	
//	return 0;
//}
main()
{
	float sn = 100.0, hn = sn / 2;
	int n;
	for (n = 2; n <= 10; n++)
	{
		sn = sn + 2 * hn;/*��n�����ʱ������������*/
		hn = hn / 2; /*��n�η����߶�*/
	}
	printf("the total of road is %f\n", sn);
	printf("the tenth is %f meter\n", hn);
	return 0;
}