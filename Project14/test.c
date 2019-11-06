#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<ctype.h>
//memcpy  内存拷贝函数
void * Mymemcpy(void *dest, const void *src
	, int count)
{
	//char *p = (char *)dest;
	void *ret = dest;
	while (count--)//16
	{
		*(char *)dest = *(char *)src;
		((char *)dest)++;
		((char *)src)++;
	}
	return ret;
}
int main()
{
	//int arr1[20] = {0};
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	memcpy(arr + 2, arr, 16);


	//Mymemcpy(arr,arr+2,16);
	//Mymemcpy(arr1,arr2,16);

	/*char str1[] = "abcdef";
	char str2[10] = {0};
	memcpy(str2,str1,5);*/
	return 0;
}

#if 0
int main()
{
	char str[] = "12ab34def";
	char *p = str;
	char ch = 0;
	while (*p != '\0')
	{
		if (islower(*p))
		{
			ch = toupper(*p);
			putchar(ch);
		}
		else
		{
			putchar(*p);
		}
		p++;
	}
	/*int count = 0;
	char *p = str;
	while(*p != '\0')
	{
	if(isdigit(*p))
	{
	count++;
	}
	p++;
	}
	printf("%d\n",count);*/
	return 0;
}



int main()
{
	/*FILE *pf = fopen("test.txt","r");
	if(pf == NULL)
	{
	printf("%s\n",strerror(errno));
	}*/
	//2g   堆 
	int *p = (int *)malloc(INT_MAX);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	//printf("%s\n",strerror(errno));
	return 0;
}

int main()
{
	char str[] = "TerryGaoBo@163.com-gb";
	/*printf("%s\n",strtok(str,".-@"));
	printf("%s\n",strtok(NULL,"@.-"));
	printf("%s\n",strtok(NULL,"@.-"));
	printf("%s\n",strtok(NULL,"@.-"));*/
	char *ret = strtok(str, ".-@");
	while (ret != NULL)
	{
		printf("%s\n", ret);
		ret = strtok(NULL, "@.-");
	}
	return 0;
}

void Reverse(char *left, char *right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_move(char *str, int k)
{
	Reverse(str, str + k - 1);
	Reverse(str + k, str + strlen(str) - 1);
	Reverse(str, str + strlen(str) - 1);
}
int is_left_move1(char *arr, const char *p)
{
	int i = 0;
	for (i = 0; i < strlen(arr); i++)
	{
		left_move(arr, 1);
		if (strcmp(arr, p) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int is_left_move(char *arr, const char *p)
{
	assert(arr != NULL && p != NULL);
	if (strlen(arr) != strlen(p))
	{
		return 0;
	}
	strncat(arr, arr, strlen(arr));
	if (strstr(arr, p) != NULL)
	{
		return 1;
	}
	return 0;
}

int main()
{
	char str[30] = "abcdef";
	char *str2 = "cdefab";
	int n = is_left_move(str, str2);
	printf("%d\n", n);
	return 0;
}

void find(int arr[3][3], int *px, int * py, int key)
{
	int x = 0;
	int y = *py - 1;
	//确定可查找的范围
	while (x < *px  &&  y >= 0)
	{
		if (arr[x][y] == key)
		{
			*px = x;
			*py = y;
			return;
		}
		if (arr[x][y]  > key)
		{
			y--;
		}
		if (arr[x][y]  < key)
		{
			x++;
		}
	}
	*px = -1;
	*py = -1;
}
int main()
{
	int arr[3][3] = { 1, 2, 3,
		2, 3, 4,
		3, 4, 5 };
	int x = 3;
	int y = 3;
	find(arr, &x, &y, 13);
	printf("%d,%d\n", x, y);
	return 0;
}


//void Function1(int *arr,int left,int right)
//{
//
//}
void Function(int *left, int *right)
{
	while (left < right)
	{
		while ((left < right) && (*left % 2 == 1))
		{
			left++;
		}
		while ((left < right) && (*right % 2 == 0))
		{
			right--;
		}
		if (left < right)
		{
			int tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
}
void Show(int *arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 1, 3, 13, 5, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Function(arr, arr + len - 1);
	Show(arr, len);
	return 0;
}
#endif
